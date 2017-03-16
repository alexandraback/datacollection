#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

struct Attack
{
	int d, l, r, s;
};

bool cmp(const Attack &a, const Attack &b)
{
	return (a.d < b.d);
}

int h[10000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t = 0;
	cin >> t; getchar();
	string s;
	vector<Attack> v;
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		v.clear();
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int d, k, l, r, s, deltad, deltap, deltas;
			cin >> d >> k >> l >> r >> s >> deltad >> deltap >> deltas;
			l += 1000;
			r += 1000;
			--r;
			for (int j = 0; j < k; ++j)
			{
				Attack q = { d, l, r, s};
				v.push_back(q);
				d += deltad;
				l += deltap;
				r += deltap;
				s += deltas;
			}
		}
		for (int i = 0; i < 10000; ++i)
			h[i] = 0;
		sort(v.begin(), v.end(), cmp);
		int ans = 0;
		for (int i = 0; i < v.size();)
		{
			int d = v[i].d;
			int idx = i;
			while (idx < v.size() && v[idx].d == d)
			{
				bool yes = false;
				for (int j = v[idx].l; j <= v[idx].r; ++j)
					if (h[j] < v[idx].s)
						yes = true;
				if (yes)
					++ans;
				++idx;
			}
			idx = i;
			while (idx < v.size() && v[idx].d == d)
			{
				for (int j = v[idx].l; j <= v[idx].r; ++j)
					h[j] = max(h[j], v[idx].s);
				++idx;
			}
			i = idx;
		}
		cout << ans << endl;
	}
}