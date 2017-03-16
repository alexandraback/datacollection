#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
#define mo 321555123
#define eps 1e-6
#define inf 1000000
int t,a1,b1,k1;
int le;
long long int dp[33][2][2][2];
char a[33];
char b[33];
char k[33];
long long int dfs_dp(int pos,int upa,int upb,int upk)
{
    if(pos==-1) return 1;
    if(dp[pos][upa][upb][upk]!=-1) return dp[pos][upa][upb][upk];
    int maxa,maxb,maxk;
    maxa=upa?(a[pos]-'0'):1;
    maxb=upb?(b[pos]-'0'):1;
    maxk=upk?(k[pos]-'0'):1;
    int ak;
    long long int temp=0;
    for(int i=0;i<=maxa;i++)
    {
      for(int j=0;j<=maxb;j++)
      {
        ak=i&j;
        if(ak<=maxk)
          temp+=dfs_dp(pos-1,upa&((i==maxa)?1:0),upb&((j==maxb)?1:0),upk&((ak==maxk)?1:0));
      }
    }
    return dp[pos][upa][upb][upk]=temp;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("ans.txt","w",stdout);
    scanf("%d",&t);
    int cac=0;
    while(t--)
    {
        cac++;
        scanf("%d%d%d",&a1,&b1,&k1);
        printf("Case #%d: ",cac);
        a1--;b1--;k1--;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<33;i++)
        {
          a[i]='0';
          b[i]='0';
          k[i]='0';
        }
        int o=0;
        while(a1!=0)
        {
          a[o++]=char(a1%2+'0');
          a1/=2;
        }
        o=0;
        while(b1!=0)
        {
          b[o++]=char(b1%2+'0');
          b1/=2;
        }
        o=0;
        while(k1!=0)
        {
          k[o++]=char(k1%2+'0');
          k1/=2;
        }
        printf("%lld\n",dfs_dp(31,1,1,1));
    }
    return 0;
}
