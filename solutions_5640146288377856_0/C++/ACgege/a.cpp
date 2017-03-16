#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define eps 1e-8
#define db double
#define rt return
#define cn const
#define op operator
#define N 30
using namespace std;

int d[N][N];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
      int r,c,w;
    scanf("%d%d%d",&r,&c,&w);

    int ans=0;

      int k=c/w;
      ans=k*(r-1);
      if(c%w)
      ans += k-1 + w +1;
      else ans+= k-1+w;
      printf("Case #%d: %d\n",ca,ans);

    }
    return 0;
}

