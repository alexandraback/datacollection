//#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
//#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
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

const double PI = acos(-1.0);


int D[4002][5];
char Str[600000][20];
int cnt;
int L[600000];
void test()
{
    const int INF=1e9;
    rep(i,0,4002)
        rep(j,0,5)
            D[i][j]=INF;
    rep(j,0,5)
        D[0][j]=0;
    char A[4001];
    scanf("%s",A);
    int n =strlen(A);
    rep(i,0,n)
    {
        char *curr=A+i;
        for (int j=3;j>=0;--j)
            D[i][j]=min(D[i][j],D[i][j+1]);
        rep(j,0,cnt)
        {
            if (i+L[j]<=n)
            {
                int pr=-100,f=-1;
                int cnt=0;
                for (int p=0;p<L[j];++p)
                    if (curr[p]!=Str[j][p])
                    {
                        if (p-pr<5) goto nextWord;
                        if (f==-1) f = p;
                        pr=p;
                        ++cnt;
                    }
                    if (cnt>0)
                    {
                        int to = L[j]-1-pr;
                        if (to>4) to = 4;
                        int from = 4-f;
                        if (from<0) from = 0;
                        if (D[i+L[j]][to] >D[i][from]+cnt)
                            D[i+L[j]][to]=D[i][from]+cnt;
                    }
                    else
                    {
                        rep(t,0,5)
                        {
                            int to = t+L[j];
                            if (to>4) to = 4;
                            if (D[i+L[j]][to]>D[i][t])
                                D[i+L[j]][to]=D[i][t];
                        }
                    }
            }
            nextWord:;
        }
    }
    int res=INF;
    rep(i,0,5)
        res=min(res,D[n][i]);
    printf("%d\n",res);
}

void run()
{
    FILE *f=fopen("garbled_email_dictionary.txt","r");
    cnt=0;
    while (fscanf(f,"%s",Str[cnt])>=1)
    {
        L[cnt]=strlen(Str[cnt]);
        ++cnt;
    }
    cerr<<"Max len = "<<*max_element(L,L+cnt)<<endl;
    int t;
    cin>>t;
    rep(i,0,t)
    {
        printf("Case #%d: ",i+1);
        test();
        cerr<<i<<" done\n";
    }
}

#define problem "C-small-attempt1"

int main()
{
#ifndef problem
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#else
    freopen(problem".in","r",stdin);
    freopen(problem".out","w",stdout);
#endif
    time_t st=clock();
    run();
#ifndef problem
    fprintf(stderr, "=============\n");
    fprintf(stderr,"Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
} 