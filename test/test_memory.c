#include <stdbool.h>
#include "memory.h"

int test_char_one(bool failure) {
   char* p = (char*)memalloc(32768, sizeof(char), __FILE__, __LINE__);
   for(int i = 0; i < 32768; ++i) {
      p[i] = i*257%32768;
   }
   for(int i = 0; i < 32768; ++i) {
      if( p[i] != i*257%32768 || failure ) {
         return 1;
      }
   }
   return 0;
}

int test_char_many(bool failure) {
   char* p[256];
   for(int i = 0; i < 256; ++i) {
      p[i] = (char*)memalloc(i, sizeof(char), __FILE__, __LINE__);
   }
   for(int i = 0; i < 256; ++i) {
      for(int k = 0; k < i; ++k) {
         p[i][k] = i^k;
      }
   }
   for(int i = 0; i < 256; ++i) {
      for(int k = 0; k < i; ++k) {
         if( p[i][k] != i^k || failure ) {
            return 1;
         }
      }
   }
   return 0;
}

int test_int_one(bool failure) {
   int* p = (int*)memalloc(32768, sizeof(int), __FILE__, __LINE__);
   for(int i = 0; i < 32768; ++i) {
      p[i] = i*257%32768;
   }
   for(int i = 0; i < 32768; ++i) {
      if( p[i] != i*257%32768 || failure ) {
         return 1;
      }
   }
   return 0;
}

int test_int_many(bool failure) {
   int* p[256];
   for(int i = 0; i < 256; ++i) {
      p[i] = (int*)memalloc(i, sizeof(int), __FILE__, __LINE__);
   }
   for(int i = 0; i < 256; ++i) {
      for(int k = 0; k < i; ++k) {
         p[i][k] = i^k;
      }
   }
   for(int i = 0; i < 256; ++i) {
      for(int k = 0; k < i; ++k) {
         if( p[i][k] != i^k || failure ) {
            return 1;
         }
      }
   }
   return 0;
}

int main(int argc, char* argv[]) {
   if( argc == 2 || ( argc == 3 && strcmp(argv[2], "failure") ) ) {
      return 1;
   }
   bool failure = argc == 3;
   if( strcmp(argv[1], "char_one") == 0 ) {
      return test_char_one(failure);
   }
   else if( strcmp(argv[1], "char_many") == 0 ) {
      return test_char_many(failure);
   }
   else if( strcmp(argv[1], "int_one") == 0 ) {
      return test_int_one(failure);
   }
   else if( strcmp(argv[1], "int_many") == 0 ) {
      return test_int_many(failure);
   }
   else {
      return 1;
   }
}
