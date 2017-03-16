#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(arr,i) for(vector<pii>::itr i=(arr.begin());i!=(arr.end());++i)
#define pb push_back
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),x.end());
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define pr pair
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf

#define lowbit(i) (i&(-i))

typedef long long int LL;
typedef pr<int,int> pii;

const int oo=(~0u)>>1;
const LL lloo=(~0ull)>>1;
const int INF = 0x3f3f3f3f;
const double dboo=1e+20;
const double eps=1e-8;
const double pi=3.1414926;

const int maxn = 100;
int T;
int N,M;
char zips[100][100];
int zipnum[100];
vector<int> maps[maxn];

int a,b;
bool vis[maxn];
vector<int> anss;

bool cmp(const int a,const int b)
{
    return zipnum[a] < zipnum[b];
}
void dfs(int now)
{
    // cout << now << endl;
    vis[now] = 1;
    anss.pb(now);
    int len = sz(maps[now]);
    sort(maps[now].begin(),maps[now].end(),cmp);

    for (int i = 0; i < len; ++i)
    {
        int to = maps[now][i];
        if(!vis[to])
            dfs(to);
    }
}
void clear()
{
    anss.clear();
    memset(vis,0,sizeof(vis));
    for (int i = 0; i < maxn; ++i)
    {
        maps[i].clear();
    }
}
int main(int argc, char *argv[])
{
    sf("%d",&T);
    ft(tt,1,T)
    {
        sf("%d%d",&N,&M);
        ft(i,1,N)
            sf("%s",&zips[i][1]);
        ft(i,1,N)
            zipnum[i] = atoi(&zips[i][1]);
        ft(i,1,M)
        {
            sf("%d%d",&a,&b);
            maps[a].pb(b);
            maps[b].pb(a);
        }
        int beg = 0;
        int mins = INF;
        ft(i,1,N)
        {
            if(zipnum[i] < mins)
                beg = i, mins = zipnum[i];
        }
        // cout << beg << endl;    // 
        dfs(beg);
        pf("Case #%d: ",tt);
        ft(i,1,N)
            pf("%d",zipnum[anss[i-1]]);
        puts("");
        clear();

    }
    return 0;
}
