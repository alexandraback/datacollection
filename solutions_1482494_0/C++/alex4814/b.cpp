#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 2000

int n;

struct pp {
	int a, b;
}p[maxn];

int win[maxn][2];

bool cmp(pp pa, pp pb)
{
	if (pa.a == pb.a) return pa.b > pb.b;
	return pa.a < pb.a;
}

bool cmp2(pp pa, pp pb)
{
	if (pa.b == pb.b) return pa.a < pb.a;
	return pa.b < pb.b;
}

int solve()
{
	int i, total = 0, pass = 0, cnt = 0;
	sort(p, p + n, cmp);
	if (p[0].a > 0) return 0;
	/*
	for (i = 0; i < n; ++i) {
		if (total >= p[i].b) {
			total += 2;
			win[i][1] = 1;
		} else if (total >= p[i].a) {
			total += 1;
			win[i][0] = 1;
		}
	}
	*/
	int f = 0;
	while (pass < n) {
		//sort(p, p + n - pass, cmp2);
		for (i = 0; i < n - pass; ++i) {
			if (total >= p[i].b) {
				total += 2;
				pass += 1;
				//printf("%d\n", p[i].b);
				swap(p[i], p[n - pass]);
				cnt++;
				f = 1;
				break;
			} else if (total >= p[i].a && !win[i][0]) {
				total += 1;
				win[i][0] = 1;
				cnt++;
				f = 1;
			}
		}
		if (!f) return 0;
		f = 0;
	}
	return cnt;
}

int main()
{
	freopen("B-small-attempt1.in.txt", "r", stdin);
	freopen("bout.txt", "w", stdout);
	int i, t, c = 0;
	int ans;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(win, 0, sizeof(win));
		for (i = 0; i < n; ++i) scanf("%d%d", &p[i].a, &p[i].b);
		printf("Case #%d: ", ++c);
		ans = solve();
		if (ans) printf("%d\n", ans);
		else puts("Too Bad");
	}
	return 0;
}
