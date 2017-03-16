#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
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

typedef struct node {
   long long time;
   long type;
}node;

long istype (long long x, struct node *a, long n) {

   long long s;
   long i;
   s=0;
   i=-1;
   while (s < x) {
      i++;
      if (i == n) return -1;
      s += a[i].time;
   }
   
   return a[i].type;

}

long long rest (long long x, struct node *a, long n) {

   long long s;
   long i;
   s=0;
   i=-1;
   while (s < x) {
      i++;
      if (i == n) return -1;
      s += a[i].time;
   }
   
   return (s-x+1);

}

long long chk (long long x, long long y, long long b, struct node *aa, struct node *bb, long N, long M, long long ssa, long long ssb) {
 
    long long t1, t2, t3, t4, ra, rb;
    long ta, tb;

    if ((x > ssa) || (y > ssb))
       return b;

   ta = istype (x, aa, N);
   tb = istype (y, bb, M);
   ra = rest (x, aa, N);
   rb = rest(y, bb, M);
   if ((ta == -1) || (tb == -1) || (ra == -1) || (rb == -1)) return b;
   

   
   if (ta == tb) {
     
     
     if (ra < rb) 
        t3 = chk(x+ra, y+ra, b+ra, aa, bb, N, M, ssa, ssb);
    
     else 
        t3 = chk(x+rb, y+rb, b+rb, aa, bb, N, M, ssa, ssb);
    
        
 
        return t3;
  
   }
   else {
     
     
     t1 = chk(x+ra, y, b, aa, bb, N, M, ssa, ssb);
     t2 = chk(x, y+rb, b, aa, bb, N, M, ssa, ssb);
     if (t1 > t2)
        return t1;
     else
        return t2;
   }



}

int main () {

   long T,ii, i, j, k, l, x, v, y, N, M;
   struct node *a, *b;
   long long sa, sb, res;
   
   

   
   T = readLong();
   
   for(ii=1; ii<=T; ii++) {
      N = readLong();
      M = readLong();
      sa = sb = (long long)0;
      a = (struct node *)malloc(N*sizeof(struct node));
      b = (struct node *)malloc(M*sizeof(struct node));
      
      for (i=0; i<N; i++) {
         a[i].time = readLong();
         a[i].type = readLong();
         sa += a[i].time;
      }
      for (i=0; i<M; i++) {
         b[i].time = readLong();
         b[i].type = readLong();
         sb += b[i].time;
      }

      res = chk ((long long)1, (long long)1, (long long) 0, a, b, N, M, sa, sb);
      
      printf("Case #%ld: %lld\n", ii,res);
      
      free(a);free(b);
      
   }
   

   return 0;
}
