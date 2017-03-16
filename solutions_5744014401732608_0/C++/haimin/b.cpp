#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define zero(x) (fabs(x)<eps)
#define pi acos(-1.0)
#define f1 first
#define f2 second
#define ms(x,y) memset(x,y,sizeof(x))
#define fr(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
LL x,y;
#define N 55
bool a[N][N];
int n;
void doit()
{
   scanf("%d%I64d",&n,&x);
   y=1;
   fr(i,1,n-2) y*=2;
   if (x>y) {puts("IMPOSSIBLE"); return;}
   puts("POSSIBLE");
   y=1;

   int s=0;
   while (y<x) {y*=2;s++;}
   y/=2;s++;
   ms(a,0);
   fr(i,1,s)
   fr(j,1,s)
   if (i<j) a[i][j]=1;
   while (x>0&&y>=1)
   {
       if (x>=y)
       {    a[s][n]=1;
            x-=y;
       }
       y/=2;
       s--;
   }
   if (x) a[1][n]=1;

   fr(i,1,n){
   fr(j,1,n)
    printf("%d",a[i][j]);
    printf("\n");
   }
}

int main()
{
    freopen("B1.in","r",stdin);
    freopen("B1.txt","w",stdout);
    int cas,i=0;
    scanf("%d",&cas);
    while (cas--)
    {   printf("Case #%d: ",++i);
        doit();
    }
}
