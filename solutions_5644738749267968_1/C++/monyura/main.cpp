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

int solveWar(double *A, double *B, int n)
{
    pdi D[2001];
    rep(i,0,n)
    D[i] = pdi(A[i], 0);
    rep(i,0,n)
    D[i+n] = pdi(B[i], 1);
    sort(D,D+2*n);
    int cnt = 0;
    rep(i,0,2*n)
    if (D[i].second == 1)
    {
        if (cnt > 0)
            --cnt;
    }
    else
        ++cnt;
    return  cnt;
}

int solveSec(double *A, double *B, int n)
{
    pdi D[2001];
    rep(i,0,n)
    D[i] = pdi(A[i], 0);
    rep(i,0,n)
    D[i+n] = pdi(B[i], 1);
    sort(D,D+2*n);
    int cnt = 0;
    int res = 0;
    rep(i,0,2*n)
    if (D[i].second == 0)
    {
        if (cnt>0)
        {
            --cnt;
            ++res;
        }
    }
    else
        ++cnt;
//    rep(i,0,2*n)
//    printf("%d",D[i].second);
//    puts("");
    return res;
        
}

void test()
{
    int n;
    scanf("%d",&n);
    double A[1001];
    double B[1001];
    rep(i,0,n)
    scanf("%lf",A+i);
    rep(i,0,n)
    scanf("%lf",B+i);
    int fir = solveSec(A, B, n);
    int sec = solveWar(A, B, n);
    printf("%d %d\n",fir,  sec);
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


#define prob "D-large"


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
