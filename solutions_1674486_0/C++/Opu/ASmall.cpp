#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

#define PI 2*acos(0.0)
#define FOR(i,n) for(int i = 0;i<n;++i)
#define setbit(a,b) a|=(1<<b)
#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define C1(a) __builtin_popcount(a)
#define gcd(a,b) __gcd(a,b)
#define ALL(a) (a.begin(),a.end())

typedef long long LL;
typedef vector<int> vi;
const int INF = (1LL<<31)-1;

int n;
vector<int> adj[1005];
int vis[1005],goal,f;

int dfs(int i){

    if(i==goal)
        return 1;

    int ret = 0;
    for(int j = 0;j<adj[i].size();++j)if(!vis[adj[i][j]]){

        vis[adj[i][j]]++;
        ret = max(ret,dfs(adj[i][j]));

    }
    else f = 1;

    return ret;
}

int main(){

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-Small_output.txt","w",stdout);

    int t;
    S1(t);

    for(int ca = 1;ca<=t;++ca){

        S1(n);

        for(int i = 1;i<=n;++i)
            adj[i].clear();

        for(int i = 1;i<=n;++i){
            int m;
            S1(m);
            int v;
            for(int j = 0;j<m;++j){
                S1(v);
                adj[i].push_back(v);
            }
        }

        bool yes = false;
        for(int i = 1;i<=n&&!yes;++i)
            for(int j = 1;j<=n;++j)if(i!=j){

                memset(vis,0,sizeof(vis));
                goal = j;
                f = 0;
                int res = dfs(i);
                if( f && res ){
                    yes = true;
                    break;
                }

            }
        printf("Case #%d: ",ca);
        if(yes)
            puts("Yes");
        else
            puts("No");

    }
    return 0;

}
