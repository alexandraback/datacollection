#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN=100;

map <int, int> mp;

int n, a[MAXN], lim=1<<20;
int ans0[MAXN], ans1[MAXN], m0, m1;

bool check(int st)
{
    int tot=0;
    for (int x=st, i=0; x; x>>=1, ++i) if (x&1) tot+=a[i];
    if (mp.find(tot)==mp.end()) mp[tot]=st;
    else
    {
        m0=m1=0;
        for (int x=st, i=0; x; x>>=1, ++i)
            if (x&1) ans0[m0++]=a[i];
        for (int x=mp[tot], i=0; x; x>>=1, ++i)
            if (x&1) ans1[m1++]=a[i];
        for (int i=0; i<m0; ++i)
            printf("%d%c", ans0[i], i==m0-1?'\n':' ');
        for (int i=0; i<m1; ++i)
            printf("%d%c", ans1[i], i==m1-1?'\n':' ');
        return 1;
    }
    return 0;
}

void solve(int cas)
{

    scanf("%d", &n);
    for (int i=0; i<n; ++i) scanf("%d", a+i);
    mp.clear();
    printf("Case #%d:\n", cas);
    for (int i=1; i<lim; ++i) if (check(i)) return;
    puts("Impossible");
}

int main()
{
    int T;
//	freopen("C.in","r",stdin);
	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    scanf("%d", &T);
    for (int i=1; i<=T; ++i) solve(i);
    return 0;
}
