#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <set>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <climits>
#include <cmath>
#include <iomanip>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define endl '\n'
#define dbgv(arr) cout << #arr << ": "; for (int i = 0; i < (int)arr.size(); i++) cout << arr[i] << " "; cout << endl;
#define dbge(el) cout << #el << ": " << el << endl;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< pair<int, int> > vii;

template<class T> T abs(T x) { return x > 0 ? x : -x; }

const int maxd = 110;
const int maxv = 50;

int solve(int c, int n, int v, int *d) {
	int pos[maxv] = { 0 };
	vi dd;

	/*for (int i = 0; i < n; i++)
		pos[d[i]] = 1;
	
	int k = 1;
	int ans = 0;
	while (2 * k - 1 <= v) {
		if (!pos[k]) {
			//cout << "intro: " << k << endl;
			ans++;
		} else {
			//cout << "skip: " << k << endl;
		}
		k *= 2;
	}

	k /= 2;
	for (int i = 2 * k; i <= v; i++)
		if (!pos[i]) return ans + 1;

	return ans;*/

	for (int i = 0; i < n; i++) {
		dd.pb(d[i]);
	}

	bool finish = true;
	int ans = 0;

	do {
		finish = true;
		for (int i = 1; i < (1 << dd.size()); i++) {
			int sum = 0;
			for (int j = 0; j < dd.size(); j++)
				if (i & (1 << j)) sum += dd[j];
			if (sum <= v)
				pos[sum] = 1;
		}
		//cout << v << endl;
		//cout << pos[4] << endl;

		for (int i = 1; i <= v; i++) {
			if (pos[i] == 0) {
				dd.pb(i);
				//cout << "intro: " << i << endl;
				finish = false;
				ans++;
				break;
			}
		}
	} while (!finish);

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output", "w", stdout);
	int t;
	cin >> t;
	for (int idx = 1; idx <= t; idx++) {
		int d[maxd];
		int c, n, v;
		cin >> c >> n >> v;
		for (int i = 0; i < n; i++)
			cin >> d[i];
		cout << "Case #" << idx << ": " << solve(c, n, v, d) << endl;
	}
	return 0;
}

