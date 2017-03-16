#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;
typedef long double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define y1 djeudyw92
const int MOD = 1e9 + 7;
const int N = 22;
const int KEYS = 44;
int a[N][N], b[N][KEYS], n, k, nums[205], stb[KEYS], st[N], t[N], sz[N], ct;
char dp[1<<N];

bool can(int ms)
{
	if (ms == ((1<<n) - 1)) return dp[ms] = 2;
	if (dp[ms] != 0) return dp[ms] - 1;
	for (int j = 0; j < n; ++j)
		if ((ms>>j)%2 == 0)
		{
			int cur = st[t[j]];
			for (int e = 0; e < n; ++e)
				if ((ms>>e)&1) 
				{
					cur += a[e][t[j]];
					if (t[e] == t[j]) cur--;
				}
			if (cur > 0 && can(ms | (1<<j))) return dp[ms] = 2;
		}
	dp[ms] = 1;
	return 0;
}

void solve()
{
	memset(dp, 0, sizeof dp);
	memset(nums, -1, sizeof nums);
	memset(a, 0, sizeof a);
	memset(st, 0, sizeof st);
	cin >> k >> n;
	for (int i = 0; i < k; ++i) cin >> stb[i];
	ct = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i] >> sz[i];
		if (nums[t[i]] == -1) nums[t[i]] = ct++;
		t[i] = nums[t[i]];
		for (int j = 0; j < sz[i]; ++j) cin >> b[i][j];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < sz[i]; ++j)
			if (nums[b[i][j]] != -1) a[i][nums[b[i][j]]]++;
  for (int i = 0; i < k; ++i)
		if (nums[stb[i]] != -1) st[nums[stb[i]]]++;
	//for (int i = 0; i < ct; ++i) cout << st[i] << endl;
	bool c = can(0);
	if (!c) cout << "IMPOSSIBLE\n";
	else 
	{
		int curms = 0;
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j)
				if ((curms>>j)%2 == 0)
				{
					int cur = st[t[j]];
					for (int e = 0; e < n; ++e) 
						if ((curms>>e) % 2) 
						{
							cur += a[e][t[j]];
							if (t[e] == t[j]) cur--;
						}
					if (cur > 0 && can(curms | (1<<j)))
					{
						curms |= 1<<j;
						cout << j + 1 << " ";
						break;
					}
				}
		cout << endl;
	}
}
int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
