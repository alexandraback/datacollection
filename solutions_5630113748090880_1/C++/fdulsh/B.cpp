#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxm=2550;

int n,Tmax,A[maxm];

void init()
{
     Tmax=0; int x;
     memset(A,0,sizeof(A));
     scanf("%d",&n);
     for(int i=1;i<=2*n-1;i++)
         for(int j=1;j<=n;j++)
         {
             scanf("%d",&x);
             A[x]++; Tmax=max(Tmax,x);
         }
}

void work()
{
     int cnt=0;
     for(int i=1;i<=Tmax;i++)
         if(A[i]&1)
         {
            printf("%d",i),cnt++;
            if(cnt==n) 
            {
               printf("\n");
               break;
            }else printf(" ");
         }
}

int main()
{
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    int TT;
    scanf("%d",&TT);
    for(int i=1;i<=TT;i++)
    {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
