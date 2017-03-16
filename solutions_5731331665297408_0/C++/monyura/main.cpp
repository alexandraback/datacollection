#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;


struct vert
{
    vector<int> inc;
    bool was;
    bool closed;
    int index;
} g[51];

bool Con[51][51] = {0};

void dfs(int k)
{
    g[k].was = true;
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (!g[to].was && !g[to].closed)
            dfs(to);
    }
}

bool graphOk(const vector<int> &used, int n)
{
    rep(i,0,n)
        g[i].was = false;
    rep(i,0,used.size())
        dfs(used[i]);
    rep(i,0,n)
        if (!g[i].was && !g[i].closed)
            return false;
    return true;
}

bool canTake(int v, vector<int> &vec, int n)
{
    vector<int> cop = vec;
    g[v].closed = true;
    rep(i,0,cop.size())
    {
        int last = cop.back();
        if (Con[last][v])
        {
            cop.push_back(v);
            if (graphOk(cop, n))
            {
                vec = cop;
                return true;
            }
            cop.pop_back();
        }
        cop.pop_back();
    }
    g[v].closed = false;
    return false;
}

void test()
{
    int n, m;
    cin>>n>>m;
    rep(i,0,n)
    {
        g[i].inc.clear();
        g[i].closed = false;
    }
    rep(i,0,n)
    rep(j,0,n)
        Con[i][j] = 0;
    rep(i,0,n)
        scanf("%d",&g[i].index);
    rep(i,0,m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a; --b;
        g[a].inc.push_back(b);
        g[b].inc.push_back(a);
        Con[a][b] = Con[b][a] = 1;
    }
    pii A[50];
    rep(i,0, n)
        A[i] = pii(g[i].index, i);
    sort(A, A+n);
    int st = A[0].second;
    g[st].closed = true;
    vector<int> res;
    vector<int> vec;
    vec.push_back(st);
    res.push_back(g[st].index);
    rep(i,1,n)
    {
        rep(j,0,n)
        if (!g[A[j].second].closed && canTake(A[j].second, vec, n))
        {
            res.push_back(g[A[j].second].index);
            break;
        }
    }
    rep(i,0,res.size())
        printf("%d",res[i]);
    puts("");
}

void run()
{
    int t;
    cin>>t;
    rep(i,0,t)
    {
        printf("Case #%d: ",i+1);
        test();
    }
}


#define prob "C-small-attempt0(1)"


int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#else
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
#ifndef prob
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
#endif
    
    return 0;
}
