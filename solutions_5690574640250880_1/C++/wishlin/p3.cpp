#include <iostream>
#include <stdio.h>
using namespace std;

int cas, r, c, m, fail, safe;
char arr[52][52];

int countM(int i, int j) {
   if (arr[i][j]!='.') return 0;
   int ret=0;
   for (int ii=-1; ii<=1; ++ii)
   for (int jj=-1; jj<=1; ++jj)
      if (i+ii>=0 && i+ii<r && j+jj>=0 && j+jj<c && arr[i+ii][j+jj]=='*')
         ++ret;
   return ret;
}

void sweep(int i, int j) {
   for (int ii=-1; ii<=1; ++ii)
   for (int jj=-1; jj<=1; ++jj)
      if (i+ii>=0 && i+ii<r && j+jj>=0 && j+jj<c)
         arr[i+ii][j+jj]='.';
}

void resolve() {
   int num;
   for (int i=0; i<r; ++i)
   for (int j=0; j<c; ++j) {
      num = countM(i,j);
      if (num && num==safe) {sweep(i,j); safe-=num; return;}
   }
   for (int k=0; k<2; ++k)
   for (int i=0; i<r; ++i)
   for (int j=0; j<c; ++j) {
      num = countM(i,j);
      if (num && safe>=num) {sweep(i,j); safe-=num;}
   }
}

int main() {
   scanf("%d",&cas);
   for (int k=1; k<=cas; ++k) {
      scanf("%d %d %d",&r,&c,&m);
      printf("Case #%d:\n", k);
      for (int i=0; i<r; ++i)
         for (int j=0; j<c; ++j) arr[i][j]='*';
      safe = r*c - m;
      fail = 0;
      
      if (r>1 && c>1) {
         if (safe==1 || m==0) {
            arr[0][0]='c';
         }
         else if (safe < 4) fail = 1;
         else {
            arr[0][0]=arr[0][1]=arr[1][0]=arr[1][1]='.';
            safe-=4;
            int j=1;
            while (safe>3 || safe==2) {
               for (int i=0; i<r && j<c && (safe>3 || safe==2); ++i)
                  if (arr[i][j-1]=='*' && arr[i][j]=='*')
                     {arr[i][j-1]=arr[i][j]='.'; safe-=2;}
               for (int i=0; i<c && j<r && (safe>3 || safe==2); ++i)
                  if (arr[j-1][i]=='*' && arr[j][i]=='*')
                     {arr[j-1][i]=arr[j][i]='.'; safe-=2;}
               j+=2;
            }
            resolve();
            if (safe) fail = 1;
            arr[0][0]='c';
         }
      }
      else {
         if (safe <= 0) fail = 1;
         else {
            arr[0][0]='c'; --safe;
            for (int i=0; i<r && safe>0; ++i)
               for (int j=0; j<c && safe>0; ++j)
                  if (arr[i][j]=='*') {arr[i][j]='.'; --safe;}
         }
      }

      if (fail) printf("Impossible\n");
      else {
         for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j)
               printf("%c",arr[i][j]);
            printf("\n");
         }
      }
   }
   return 0;
}
