#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2000;

int n;
double a[MAXN], b[MAXN];
bool f[MAXN];

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
    int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
			scanf("%lf", &a[i]); 
        for (int i = 1; i <= n; ++i)
			scanf("%lf", &b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
        int ans1 = 0, ans2 = 0;
		memset(f, 0, sizeof(f));
        int l = 1, r = n;
        for (int i = n; i >= 1; --i)
		if (a[r] > b[i])
		{
			++ans1;
			--r;
		}
		else ++l;
		memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i)
		{
            int j;
            for (j = 1; j <= n; ++j) if (!f[j] && b[j] > a[i]) break;
            if (j == n + 1)
			{
				for (j = 1; j <= n; ++j)
					if (!f[j]) break;
			}
            if (b[j] <= a[i]) ++ans2;
            f[j] = true;
        }
		printf("Case #%d: %d %d\n", ii, ans1, ans2);
    }
	return 0;
}
