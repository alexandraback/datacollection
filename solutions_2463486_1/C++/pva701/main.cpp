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
const int N = 105;
int a[N][N], n, m;
string solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			bool h1 = true, h2 = true;
			for (int k = 0; k < m; ++k)
				h1 &= a[i][j] >= a[i][k];
			for (int k = 0; k < n; ++k)
				h2 &= a[i][j] >= a[k][j];
			if (!h1 && !h2) return "NO";
		}
	return "YES";
}
bool ispal(ll x)
{
	char ss[20];
	sprintf(ss, "%I64d", x);
	string s(ss);
	string t = s;
	reverse(t.begin(), t.end());
	return s == t;
}
 
int ans[50] = {1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002};
int main()
{
	freopen("C-large-1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int pr = 0;
		ll L, R;
		cin >> L >> R;
		for (int j = 0; j < 40; ++j)
			if (1LL * ans[j] * ans[j] >= L && 1LL * ans[j] * ans[j] <= R) pr++;
		cout << "Case #" << i << ": " << pr << endl;
	}
	return 0;
}
