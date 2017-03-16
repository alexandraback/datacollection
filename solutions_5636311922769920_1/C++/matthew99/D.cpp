#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case)
	{
		printf("Case #%d: ", Case);
		int k, c, S;
		scanf("%d%d%d", &k, &c, &S);
		vector<LL> ans;
		LL lst = -1;
		LL now = 1;
		REP(i, 0, k)
		{
			chkmax(lst, 0LL);
			lst += i * now;
			now *= k;
			if (!((i + 1) % c)) ans.pb(lst + 1), lst = -1, now = 1;
		}
		if (~lst) ans.pb(lst + 1);
		if (SZ(ans) > S) printf("IMPOSSIBLE\n");
		else 
		{
			for (auto x : ans) printf("%I64d ", x);
			printf("\n");
		}
	}
	return 0;
}
