#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

unsigned long long int a[105],b[105];
int A[105],B[105];
long long int ans,tmp;
unsigned long long int f[105][105];
int n,m,cas(0);


void solve()
{
    int i(0),j(0),k(0);
    scanf("%d%d", &n, &m);

    for(i=1; i<=n; ++i)
    {
        scanf("%I64u%d", &a[i],&A[i]);
    }
    for(i=1; i<=m; ++i)
    {
        scanf("%I64u%d", &b[i],&B[i]);
    }
    memset(f,0,sizeof(f));

    for(k=2; k<=m+n; ++k)
    {
        for(i=1; i<=n && i<k; ++i)
        {
            j = k-i;
            f[i][j] = (f[i-1][j]>f[i][j-1]? f[i-1][j]:f[i][j-1]);
            if(A[i] == B[j])
            {
                if(a[i]>b[j])
                {
                    f[i][j] += b[j];
                    a[i] -= b[j];
                    b[j] = 0;
                }
                else
                {
                    f[i][j] += a[i];
                    a[i] = 0;
                    b[j] -= a[i];
                }
            }
        }
    }
    /*
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
        {
            if(f[i][j-1]>f[i-1][j])
                f[i][j] = f[i][j-1];
            else f[i][j] = f[i-1][j];
            if(f[i][j]<f[i-1][j-1]) f[i][j] = f[i-1][j-1];
            if(A[i]==B[j])
            {
                if(a[i]>b[j])
                {
                    f[i][j]+=b[j];
                    a[i]-=b[j];
                    b[j] = 0;
                }
                else{
                    f[i][j] +=a[i];
                    b[j]-=a[i];
                    a[i] =0;
                }
            }
        }
    }
    */
    printf("Case #%d: %I64u\n",++cas,f[n][m]);
}


int main()
{
    int t(0);
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C1.out","w",stdout);
    scanf("%d", &t);
    while(t--)
    {
        solve();
    }
    return 0;
}

