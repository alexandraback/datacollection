#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#define forup(i,a,b) for (long long i=a;i<=b;i++)

using namespace std;

int T,a[21],w[21];
long long c[200001],A,B;

bool check(long long now){
    int cnt=0;
    for (;now;now/=10) a[++cnt]=now%10;
    for (int i=1,j=cnt;i<j;i++,j--)
        if (a[i]!=a[j]) return(false);
    return(true);
}

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int cnt=0;
    forup(i,1,10000000)
       if (check(i) && check(i*i)) c[++cnt]=i*i;
    scanf("%d",&T);
    forup(uu,1,T)
    {
         printf("Case #%d: ",uu);
         scanf("%I64d%I64d",&A,&B);
         int L,R;
         if (A>c[cnt]) 
         {
            printf("0\n");
            continue;
         }
         if (A==1) L=1;
         else
         {
         int Left=1,Right=cnt,Mid=(Left+Right)>>1;
         while (Left+1<Right)
         {
             if (c[Mid]>=A) Right=Mid;
             else Left=Mid;
             Mid=(Left+Right)>>1;
         }
         L=Right;
         }
         if (B>=c[cnt]) R=cnt;
         else
         {
         int Left=1,Right=cnt,Mid=(Left+Right)>>1;
         while (Left+1<Right)
         {
             if (c[Mid]>B) Right=Mid;
             else Left=Mid;
             Mid=(Left+Right)>>1;
         }
         R=Left;
         }
         printf("%d\n",R-L+1);
    }
}
