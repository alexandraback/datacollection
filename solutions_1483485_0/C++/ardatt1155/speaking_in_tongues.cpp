#include "stdio.h"
#include "stdlib.h"
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#define CHARS 26
#define SIZE 128
int main()
{
   //char g2e[CHARS] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
   char *g2e = (char *)"yhesocvxduiglbkrztnwjpfmaq\0";
   unsigned int T; char c;
   char buffer[SIZE]; buffer[SIZE] = '\0';
   fgets(buffer, SIZE, stdin); T = atoi(buffer);
   for (int jack = 0; jack < T; ) {
      fgets(buffer, SIZE, stdin);
      for (int i = 0; i < SIZE; i++) {
         if (buffer[i] == '\0') break; c = buffer[i];
         if (c >= 'A' && c <= 'Z') c = c + 'a' - 'A';
         if (c >= 'a' && c <= 'z') buffer[i] = g2e[c - 'a'];
      }
      printf("Case #%u: %s", ++jack, buffer);
   }
   return 0;
}
