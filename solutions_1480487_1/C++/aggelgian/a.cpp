#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
#include<iostream>
#define BSIZE 1<<15

char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

long readLong () {
   long d = 0L, x = 0L;
   char c;

   while (1)  {
      if (bpos >= bsize) {
         bpos = 0;
         if (feof(stdin)) return x;
         bsize = fread(buffer, 1, BSIZE, stdin);
      }
      c = buffer[bpos++];
      if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
      else if (d == 1) return x;
   }
   return -1;
}


int main () {

   long T,ii, ppl, *jud, i, x, avail, y, z;
   float myp, *hh;
   
   T = readLong();
   
   for(ii=1; ii<=T; ii++) {
   
      /* read inp */
      x = 0;
      ppl = readLong ();
      jud = (long *)malloc(ppl*sizeof(long));
      hh = (float *)malloc(ppl*sizeof(float));
      for(i=0; i<ppl; i++) {
         jud[i] = readLong();
         x += jud[i];
      }
      avail = x;
      z = x;
      y = ppl;
      
      for(i=0; i<ppl; i++)
         if (jud[i] == avail)
            y--;
      
      /* calc result */
      
      printf("Case #%ld: ", ii);
      
      for (i=0; i<ppl; i++) {
         if (y < ppl)
            myp = avail/y - jud[i];
         else
            myp = 2*avail/(ppl) - jud[i];
            
         if (myp < 0.0)
            hh[i] = 0.0;
         else
            hh[i] = 100.0 *myp/avail;
            //printf("%lf ", 100.0 *myp/avail);
      
      }
      y = ppl;
      for (i=0; i<ppl; i++)
        if (hh[i] == 0.0) {
           y--;
           z -= jud[i];
      }

      for (i=0; i<ppl; i++) {
         if (hh[i] > 0.0) {
           hh[i] = 100.0*((float)(z+avail)/y - jud[i])/avail;}
         
           printf("%lf ", hh[i]);
      }
          
      printf("\n");
      
   }
   

   return 0;
}
