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

int solve(int r, int c, int w) {
	int a = c / w * (r - 1) + c / w + w - 1;
	if (c % w != 0) a++;
	return a;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output", "w", stdout);
	int t;
	cin >> t;
	for (int idx = 1; idx <= t; idx++) {
		int r, c, w;
		cin >> r >> c >> w; 
		cout << "Case #" << idx << ": " << solve(r, c, w) << endl;
	}

	return 0;
}

