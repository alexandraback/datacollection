#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int ans;
int v[10000];
int mem[10][10];
int max(int a,int b)
{
    return (a>b?a:b);
}
int e,r,n;
int search(int energy,int time)
{
     int ans = 0;
     if (time == n) return 0;
     //if (mem[energy][time] != -1) return mem[energy][time];
     for (int i = 0; i <= energy; i++)
     {
         if (energy - i + r > e)
             ans = max(ans,search(e,time+1)+v[time]*i);
         else
             ans = max(ans,search(energy-i+r,time+1)+v[time]*i);
     }
     //mem[energy][time] = ans;
     return ans;
}
int main()
{
     freopen("data.txt","r",stdin);
     freopen("ans.txt","w",stdout);
     int t;
     scanf("%d",&t);
     for (int times = 1; times <= t; times ++)
     {
         scanf("%d %d %d",&e,&r,&n);
         memset(v,0,sizeof(v));

         for (int j = 0;j < n; j++)
             scanf("%d",&v[j]);
         memset(mem,2147483647,sizeof(mem));

         ans = search(e,0);

         printf("Case #%d: %d\n",times,ans);
     }

}
