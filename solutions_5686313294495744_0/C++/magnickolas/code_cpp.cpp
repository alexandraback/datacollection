#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, N) for (decltype(N) i = 0; i < N; i++)
#define dep(i, N) for (decltype(N) i = N - 1; i >= 0; i--)
#define FOR(i, A, B) for (decltype(B) i = A; i <= B; i++)
#define FORD(i, A, B) for (decltype(A) i = A; i >= B; i--)
#define len(A) (int)A.size()
#define all(A) A.begin(), A.end()

typedef long long int64;
typedef unsigned long long uint64;
typedef long double ld;


using namespace std;

template<typename T>
T sqr(const T &a)
{
	return a * a;
}


int main()
{
	ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<string> f, s;
	int T;
	cin >> T;
	rep(t, T)
	{
		int n;
		cin >> n;
		vector<pair<string, string> > a(n);
		rep(i, n)
		{
			cin >> a[i].first >> a[i].second;
		}
		int ans = 0;
		rep(k, 2000)
		{
			random_shuffle(all(a));
			int cur = 0;
			multiset<string> f, s;
			rep(i, n)
			{
				f.insert(a[i].first);
				s.insert(a[i].second);
			}
			rep(i, n)
			{
				if (f.count(a[i].first) > 1 && s.count(a[i].second) > 1)
				{
					f.erase(f.find(a[i].first));
					s.erase(s.find(a[i].second));
					cur++;
				}
			}
			ans = max(ans, cur);
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
	return 0;
}