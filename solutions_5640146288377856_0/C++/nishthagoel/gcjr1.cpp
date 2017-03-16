#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<limits.h>
#define s(n) scanf("%d",&n)
using namespace std;
#define lint unsigned long long int
#define mod 1000000007
int main()
{
  freopen("A-small-attempt2.in","r",stdin);
freopen("op2.txt","w",stdout);
    int t,i,r,c,w,cnt;
    s(t);
    for(int j=1;j<=t;j++)
    {

        cin>>r>>c>>w;
        int temp=c%w;
        if(temp!=0)
        temp=1;
        cnt=(r*(int(c/w)))+w-1+temp;
        printf("Case #%d: %d\n",j,cnt);
    }
return 0;
}
