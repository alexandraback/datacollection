#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cassert>
#include<set>
#include<queue>
#include<map>

using namespace std;

#define vi vector < int >
#define pb push_back
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define all(x) x.begin(),x.end()

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int a,b,k,i,j;
    int t,tc=1;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d%d%d",&a,&b,&k);
              int ans = 0;
              for(i=0;i<a;i++)
              {
                for(j=0;j<b;j++)
                {
                   if((i&j)<k)
                   ans++;
                }
              }
              printf("Case #%d: %d\n",tc++,ans);
    }
    //system("pause");
    return 0;
}
