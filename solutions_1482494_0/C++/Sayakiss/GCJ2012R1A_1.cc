#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define TWO(i) (1<<(i))
using namespace std;

typedef vector<int> VI;
typedef VI::iterator VIit;
typedef pair<int,int> PII;
typedef map<int,int> MII;
typedef MII::iterator MIIit;
typedef set<int> SI;
typedef SI::iterator SIit;
typedef long long LL;
const int DX[8]={1,-1,0,0,1,1,-1,-1};
const int DY[8]={0,0,1,-1,1,-1,1,-1};
const int intmax=0x7fffffff;
const int mod=1000000007;
int t,n;
int a[1005],b[1005],vis[1005];
int main()
{
    freopen("1.txt","r",stdin);
    freopen("3.txt","w",stdout);
    scanf("%d",&t);
    for(int mt=1;mt<=t;mt++)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",a+i,b+i);
        }
        int cnt=0,now=0;
        while(1)
        {
            int find=-1;
            for(int j=0;j<n;j++)
            {
                if (vis[j]==2) continue;
                if (now>=b[j]&&vis[j]==0) {find=j;break;}
            }
            if (find>=0)
            {
                now+=2;
                vis[find]=2;
                cnt++;
                continue;
            }
            for(int j=0;j<n;j++)
            {
                if (vis[j]==2) continue;
                if (now>=b[j]&&vis[j]==1) {find=j;break;}
            }
            if (find>=0)
            {
                now++;
                vis[find]=2;
                cnt++;
                continue;
            }
            int maxb=-1;
            for(int j=0;j<n;j++)
            {
                if (vis[j]) continue;
                if (now>=a[j]&&maxb<b[j]) {find=j;maxb=b[j];}
            }
            if (find>=0)
            {
                now++;
                vis[find]=1;
                cnt++;
                continue;
            }
            if (find<0) break;
        }
        int flag=0;
        for(int i=0;i<n;i++) if (vis[i]!=2) flag=1;
        if (flag) printf("Case #%d: Too Bad\n",mt);
        else printf("Case #%d: %d\n",mt,cnt);
    }
}

