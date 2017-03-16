#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct arr
{
    int d, n, w, e, s, di, pi, si;
}a[110];
struct brr
{
    int d, w, e, s;
    bool operator<(const brr &x)const{return d < x.d;}
}b[10010];
int h[2000010];
int n, m, l, r, w, T;
long long ans;
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
	{
		ans = m = 0;
	    l = 214748364, r = -214748364;
	    scanf("%d", &n);
	    for (int i = 0; i < n; i++)
		{
	        scanf("%d%d%d%d%d%d%d%d", &a[i].d, &a[i].n, &a[i].w, &a[i].e, &a[i].s, &a[i].di, &a[i].pi, &a[i].si);
	        for (int j = 0; j < a[i].n; j++)
			{
				m++;
				b[m].d = a[i].d + a[i].di * j;
				b[m].w = a[i].w + a[i].pi * j;
				b[m].e = a[i].e + a[i].pi * j;
				b[m].s = a[i].s + a[i].si * j;
	            l = min(l, b[m - 1].w);
	        }
	    }
	    for (int i = 0; i < m; i++)
		{
	        b[i].w -= l, b[i].e -= l;
	        b[i].w = b[i].w * 2, b[i].e = b[i].e * 2 - 1;
	        r = max(r, b[i].e);
	    }
	    for (int i = 0; i <= r; ++i) h[i] = 0;
	    sort(b, b + m);
	    for (int i = 0; i < m;)
		{
	        int j = i + 1;
	        while (j < m && b[j].d == b[j - 1].d) j++;
	        for (int k = i; k < j; k++)
	        for (int x = b[k].w; x <= b[k].e; x++)
	        if (h[x] < b[k].s)
			{
	            ans++;
	            break;
	        }
	        for (int k = i; k < j; k++)
	            for (int x = b[k].w; x <= b[k].e; x++)
	                h[x] = max(h[x], b[k].s);
	        i = j;
	    }
	    printf("Case #%d: ", ++w);
	    printf("%I64d\n", ans);
	}
    return 0;
}
