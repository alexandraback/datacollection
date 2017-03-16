#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int a[32];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("C-large.in", "r", stdin);
	freopen("Clarge.out", "w", stdout);
	int t; cin >> t;
	int n, j; cin >> n >> j;
	cout << "Case #1:" << "\n";
	for(int i = 0; i < j; i++)
	{
		memset(a, 0, sizeof(a));
		a[0] = 1;
		a[n-1] = 1;
		int tmp = i;
		for(int l = 1; l < n/2; l++)
		{
			a[l] = tmp%2;
			a[n-1-l] = a[l];
			tmp >>= 1;
		}
		for(int l = 0; l < n; l++)
		{
			cout << a[l];
		}
		cout << " ";
		for(int x = 2; x <= 10; x++)
		{
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}


