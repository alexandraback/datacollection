#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const double eps=1e-10;
const int MAXN=210;

int n, m, x, a[MAXN], b[MAXN], sum;

bool check(double r)
{
    int cnt=m;
    double t, xx=x;
    while (1)
    {
        t=(sum-xx+sum*(1-r))/cnt;
        if (b[cnt-1]<t+eps) break;
        while (b[cnt-1]>t-eps) xx+=b[cnt-1], --cnt;
    }
    return x+sum*r>t-eps;
}

double calc(int k)
{
    double st=0, ed=1.0;
    x=a[k];
    for (int i=0; i<k; ++i) b[i]=a[i];
    for (int i=k+1; i<n; ++i) b[i-1]=a[i];
    m=n-1;
    sort(b, b+m);
    while (st+eps<ed)
    {
        double mid=(st+ed)/2.0;
        if (check(mid)) ed=mid;
        else st=mid;
    }
    return st;
}

void solve(int cas)
{
    scanf("%d", &n);
    sum=0;
    for (int i=0; i<n; ++i) scanf("%d", a+i), sum+=a[i];
    printf("Case #%d:", cas);
    for (int i=0; i<n; ++i)
        printf(" %.8f", calc(i)*100.0);
    puts("");
}

int main()
{
    int T;
//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    scanf("%d", &T);
    for (int i=1; i<=T; ++i) solve(i);
    return 0;
}
