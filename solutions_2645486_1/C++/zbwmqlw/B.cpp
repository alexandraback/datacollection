#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 10005;

typedef long long ll;
int v[N];
int E, T, R, n;
pair<int, int> pii[N];
int hf[N], sE[N];
ll s[N];

void dfs(int depth, int curE, int curV, int &maxV)
{
	if (depth == n) {
		maxV = max(maxV, curV);
		return;
	}
	for (int i = 0; i <= curE; ++i) 
		dfs(depth + 1, min(E, curE - i + R), curV + v[depth] * i, maxV);
}
void work()
{
	scanf("%d%d%d", &E, &R, &n);
	memset(s, 0, sizeof(s));
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
	ll res = 0;
	// dfs(0, E, 0, res);
	for (int i = 0; i < n; ++i) pii[i] = make_pair(-v[i], i);
	sort(pii, pii + n);
	for (int t = 0; t < n; ++t) {
		int i = pii[t].second;
		int ub = E;
		ll cur = E;
		ll left = 0, right = 0;
		for (int j = i - 1; j >= 0; --j) {
			cur += R - s[j];
			if (cur - E < left) left = cur - E;
			if (cur < ub) ub = cur;
		}
		cur = E;
		for (int j = i + 1; j < n; ++j) {
			cur += R - s[j];
			if (cur - E < right) right = cur - E;
			if (cur < ub) ub = cur;
		}
		s[i] = E + left + right;
		res += (ll)s[i] * v[i];
	}
	
	static int ttt = 0;
	printf("Case #%d: %I64d\n", ++ttt, res);
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B_2.out", "w", stdout);
	scanf("%d", &T);
	while (T--) work();
}
