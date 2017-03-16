/// izizi

#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <ctime>

#define pii pair<int, int>
  
#define pb push_back
#define mp make_pair
  
#define f first
#define s second
  
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1);
  
const int oo = 1e9, bpr = 1e9 + 7, N = 12;

#define int __int128

inline bool bit (int mask, int pos) {
	return (mask >> pos) & 1;
}

inline int getdivisor (int x) {
	for (int i = 2; i * i <= x && i <= 1e5; ++i)
		if (x % i == 0)
			return i;
	return x;
}

int g[N], val[N];
int pw[N][40];

main() {

	freopen ("in", "r", stdin);
	freopen ("out", "w", stdout);

	ios_base :: sync_with_stdio (0);
	cin.tie (0);
	
	ll t_num;

	cin >> t_num;
	
	cout << "Case #" << 1 << ":\n";
	
	ll n, k;
	
	cin >> n >> k;
	
	for (int i = 2; i <= 10; ++i) {
		pw[i][0] = 1;
		for (int j = 1; j < 32; ++j)
			pw[i][j] = pw[i][j - 1] * i;
	}
	
	ll cnt = 0;
	for (ll mask = (1ll << (n - 1)) + 1;; ++mask) {
		mask |= 1;
		for (int j = 2; j <= 10; ++j)
			val[j] = 0;
		for (int j = 0; j < n; ++j) {
			if (bit (mask, j)) {
				for (int i = 2; i <= 10; ++i)
					val[i] += pw[i][j];
			}
		}
		bool flag = 1;
		for (int i = 2; i <= 10; ++i) {
			g[i] = getdivisor (val[i]);
			if (g[i] == val[i])
				flag = 0;
		}
		if (flag) {
			++cnt;
			for (int i = n - 1; i >= 0; --i)
				cout << bit (mask, i);
			cout << " ";
			for (int i = 2; i <= 10; ++i)
				cout << ll (g[i]) << " ";
			cout << "\n";
		}
		if (cnt == k)
			return 0;
	}
	
	return 0;
}
