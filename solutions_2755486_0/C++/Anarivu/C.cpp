#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct pt
{
	int d, l, r, s;
	pt(int dd = 0, int ll = 0, int rr = 0, int ss = 0) : d(dd), l(ll), r(rr), s(ss) {}
	bool operator < (const pt& p) const
	{
		return d < p.d;
	}
};

vector<pt> arr;

int len[1000];
int len2[1000];

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; tt++)
	{
		int nn;
		scanf("%d", &nn);
		arr.clear();
		for(int i = 0; i < nn; i++)
		{
			int d, n, w, e, s, dd, dp, ds;
			scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
			w += 500;
			e += 500;
			for(int j = 0; j < n; j++)
			{
				arr.push_back(pt(d, w, e, s));
				d += dd;
				s += ds;
				w += dp;
				e += dp;
			}
		}
		sort(arr.begin(), arr.end());

		memset(len, 0, sizeof(len));
		memset(len2, 0, sizeof(len2));
		int ans = 0;
		int idx = 0;
		while(idx < arr.size())
		{
			int curd = arr[idx].d;
			while(idx < arr.size() && arr[idx].d == curd)
			{
				bool fo = 0;
				for(int i = arr[idx].l; i < arr[idx].r; i++)
				{
					if(len[i] < arr[idx].s)
					{
						len2[i] = max(len2[i], arr[idx].s);
						fo = 1;
					}
				}
				if(fo)
					ans++;
				idx++;
			}
			for(int i = 0; i < 1000; i++)
				len[i] = max(len[i], len2[i]);
		}
		printf("Case #%d: %d\n", tt + 1, ans);
	}
	

	return 0;
}