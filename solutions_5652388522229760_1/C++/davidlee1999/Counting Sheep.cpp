#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
bool vis[10];
bool check()
{
    for(int i=0;i<=9;i++)
        if(!vis[i]) return 0;
    return 1;
}

void get(int x)
{
    while(x)
    {
        vis[x%10]=1;
        x/=10;
    }
}

int main()
{
    int T,test,n,now;
    //freopen("Alarge.in","r",stdin);
    //freopen("Alarge.out","w",stdout);
    cin>>T;
    for(test=1;test<=T;test++)
    {
        printf("Case #%d: ",test);
        memset(vis,0,sizeof(vis));
        cin>>n;
        if(n==0) printf("INSOMNIA\n");
        else
        {
            now=0;
            while(!check())
            {
                now+=n;
                get(now);
            }
            cout<<now<<endl;
        }
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
