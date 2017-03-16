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

inline bool inside(int x, int y, int n ,int m)
{
    return x>=0 && x < n && y>=0 && y < m;
}



bool isMatrixOk(char M[51][51], int n, int m, int cnt)
{
    bool nonZero[51][51] = {0};
    rep(i,0,n)
    rep(j,0,m)
    if (M[i][j]=='.')
    {
        rep(di,-1,2)
        rep(dj,-1,2)
        {
            int ni = i + di;
            int nj = j + dj;
            if (inside(ni,nj,n,m) && M[ni][nj] == '*')
                nonZero[i][j] = 1;
        }
        --cnt;
    }
    if (cnt != 0)
        return  false;
    rep(i,0,n)
    rep(j,0,m)
    if (M[i][j]=='.')
    {
        bool ok = false;
        rep(di,-1,2)
        rep(dj,-1,2)
        {
            int ni = i + di;
            int nj = j + dj;
            if (inside(ni,nj,n,m) && M[ni][nj] == '.' && nonZero[ni][nj] == 0)
                ok = true;
        }
        if (!ok)
            return false;
    }
    return true;
}

bool isOk(char Res[51][51], int n, int m, int cnt)
{
    rep(i,0,n)
    {
        memset(Res[i], '*', m);
    }
    rep(t,2,n+1)
        if (2*t <= cnt)
        {
            int Cnt[51]={t,t};
            int left = cnt - 2*t;
            int has = (m-2)*t;
            if (has < left) continue;
            rep(i,2,m)
                if (left> 0)
                {
                    Cnt[i] = min(left, t);
                    left  -= min(left, t);
                }
            bool isOk = true;
            rep(i,2,m)
                if (Cnt[i] > 0 && Cnt[i] < 2)
                {
                    if (i == 2 || Cnt[i-1] == 2)
                    {
                        isOk = false;
                        break;
                    }
                    Cnt[i-1]--;
                    Cnt[i]++;
                }
            if (!isOk)
                continue;
            rep(j,0,m)
                rep(i,0,Cnt[j])
                    Res[i][j] = '.';
            return true;
        }
    return false;
}

void test()
{
    puts("");
    int n,m, cnt;
    cin>>n>>m>>cnt;
    cnt = n*m - cnt;
    char Res[51][51] = {0};
    if (n == 1 || m == 1 || cnt == 1)
    {
        rep(i,0,n)
        memset(Res[i], '*', m);
        rep(i,0,n)
        rep(j,0,m)
        if (cnt > 0)
        {
            Res[i][j] = '.';
            --cnt;
        }
        Res[0][0] = 'c';
        rep(i,0,n)
            puts(Res[i]);
        return;
    }
    if (isOk(Res, n, m, cnt))
    {
        Res[0][0] = 'c';
        rep(i,0,n)
        {
            Res[i][m] = 0;
            puts(Res[i]);
        }
        return;
    }
    if (isOk(Res, m, n, cnt))
    {
        rep(i,0,max(n,m))
            rep(j,i+1,max(n,m))
                swap(Res[i][j], Res[i][j]);
        Res[0][0] = 'c';
        rep(i,0,n)
        {
            Res[i][m] = 0;
            puts(Res[i]);
        }
        return;
    }
//    if (cnt > 3 && cnt!= 7 && cnt!=5)
//    {
//        fprintf(stderr, "%d %d %d\n", n, m, cnt);
//        exit(0);
//    }
    puts("Impossible");
}

void run()
{
    int t;
    cin>>t;
    rep(i,0,t)
    {
        fprintf(stderr, "Test %d...", i+1);
        printf("Case #%d: ", i+1);
        test();
        fprintf(stderr, " done!\n");
    }
}


#define prob "C-large"


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
