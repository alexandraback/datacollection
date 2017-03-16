#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
#include<bitset>
#include<cassert>
#include<queue>
#include<stack>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1007;
string a[MAXN], b[MAXN];
int aa[MAXN], bb[MAXN];
bool havea[MAXN], haveb[MAXN];
bool used[MAXN];
bool canBeGood[MAXN];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		cin >> n;
		map<string, int>conva, convb;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i];
			if (!conva.count(a[i]))
			{
				conva[a[i]] = i;
			}
			if (!convb.count(b[i]))
			{
				convb[b[i]] = i;
			}
			aa[i] = conva[a[i]];
			bb[i] = convb[b[i]];
			used[i] = false;
			canBeGood[i] = false;
		}
		int ans = 0;
		for (int mask = 0; mask < (1 << n); mask++)
		{
			int tmp = mask;
			int curans = 0;
			for (int j = 0; j <= 17; j++)
			{
				havea[j] = false;
				haveb[j] = false;
			}
			for (int i = 1; i <= n; i++)
			{
				if (tmp % 2 == 1)
				{
					havea[aa[i]] = true;
					haveb[bb[i]] = true;
				}
				else
				{
					curans++;
				}
				tmp /= 2;
			}
			bool ok = true;
			tmp = mask;
			for (int i = 1; i <= n; i++)
			{
				if (tmp % 2 == 0)
				{
					if (!havea[aa[i]] || !haveb[bb[i]]) ok = false;
				}
				tmp /= 2;
			}
			if (ok) ans = max(ans, curans);
		}
		printf("Case #%d: %d\n", tt, ans);
		cerr << tt << endl;
	}
}
