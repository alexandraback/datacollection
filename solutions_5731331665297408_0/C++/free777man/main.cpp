#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

char g[55][55], used[55], usedOut[55];
int n, remVis;
string zip[55];
set<int> unusedRet;
vector<int> currRes;
string bestRes;

vector<int> currpath;

void f(int v)
{
    currpath.push_back(v+1);
    char wasused = used[v];
    if(!used[v])
    {
        --remVis;
        used[v]=1;
        currRes.push_back(v);
    }

    set<int> cp(unusedRet);

    if (remVis == 0 && unusedRet.empty())
    {
        string res;
        REP(i,n)res+=zip[currRes[i]];
        if(res<bestRes)
            bestRes=res;
        goto exit;
    }

    REP(i,n)if(g[v][i] && !usedOut[i] && !used[i])
    {
        usedOut[i]=1;
        unusedRet.insert(100*i+v);
        f(i);
        unusedRet.erase(100*i+v);
        usedOut[i]=0;
    }

    for(int ret : cp)
    {
        int from = ret/100, to = ret%100;
        if(from == v)
        {
            unusedRet.erase(ret);
            f(to);
            unusedRet=cp;
        }
    }

exit:
    used[v]=wasused;
    if(!wasused)
    {
        ++remVis;
        currRes.pop_back();
    }
    currpath.pop_back();
}

string get(int v)
{
    CLR(used,0);
    CLR(usedOut, 0);
    
    unusedRet.clear();
    remVis=n;
    currRes.clear();
    bestRes.assign(5*n,'9');
    currpath.clear();
    f(v);

    return bestRes;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w+", stdout);
    
    int TTT;
    scanf("%d", &TTT);
    FOR(ttt,1,TTT+1)
    {
        int m;
        cin>>n>>m;

        REP(i,n)cin>>zip[i];
        
        CLR(g,0);
        REP(i,m)
        {
            int a,b;
            cin>>a>>b;
            --a,--b;
            g[a][b]=g[b][a]=1;
        }

        string res(5*n,'9');
        REP(i,n)
        {
            string const & r = get(i);
            if(r<res)res=r;
        }

        cout << "Case #"<< ttt << ": " << res << "\n";
    }

    return 0;
}


