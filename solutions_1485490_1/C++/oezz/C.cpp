#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long ll;

using namespace std;

const int MAXN=110;

struct node{
    ll x, y;
    node(){}
    node(ll _x, ll _y):x(_x),y(_y){}
    void rd(){cin>>x>>y;}
} A[MAXN], B[MAXN];

int n, m;
ll F[MAXN][MAXN];

void remake()
{
    int nn=0, mm=0;
    for (int i=1; i<=n;)
    {
        int j=i+1;
        while (j<=n && A[j].y==A[i].y) A[i].x+=A[j].x, ++j;
        ++nn;
        i=j;
    }
    n=nn;
    for (int i=1; i<=m;)
    {
        int j=i+1;
        while (j<=m && B[j].y==B[i].y) B[i].x+=B[j].x, ++j;
        ++mm;
        i=j;
    }
    m=mm;
}

ll solve(void)
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i) A[i].rd();
    for (int i=1; i<=m; ++i) B[i].rd();
    //remake();
    memset(F, 0, sizeof(F));
    A[0]=B[0]=node(0,0);
    ll ret=0, up[MAXN], down[MAXN];
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
        {
            ret=max(ret, F[i][j]);
            memset(up, 0, sizeof(up));
            for (int k=i+1; k<=n;++k)
            {
                up[A[k].y]+=A[k].x;
                memset(down, 0, sizeof(down));
                for (int t=j+1; t<=m; ++t)
                {
                    down[B[t].y]+=B[t].x;
                    F[k][t]=max(F[k][t], F[i][j]+min(up[A[k].y], down[A[k].y]));
                    ret=max(ret, F[k][t]);
                }
            }
        }
    return ret;
}

int main()
{
    int T;
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    cin>>T;
    for (int i=1; i<=T; ++i) cout << "Case #" << i << ": " << solve() << endl;
    return 0;
}
