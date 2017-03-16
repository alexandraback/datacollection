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

const int maxl = 100;

void gen(string p, int s, string &k, vector<string> &x) {
	if (p.length() == s) {
		return x.pb(p);
	}

	for (int i = 0; i < k.length(); i++) {
		gen(p + k[i], s, k, x);
	}
}

double solve(int s, string k, string l) {
	int n = k.length();
	int m = l.length();
	int p[maxl];
	vector<string> x;
	
	/*p[0] = -1;
	for (int i = 1; i < l.length(); i++) {
		int z = p[i - 1];
		while (z > 0 && l[i] != l[z + 1]) z = p[z];
		if (l[i] == l[z + 1]) z++;
		p[i] = z;
	}*/

	//cout << l << endl;
	//for (int i = 0; i < l.length(); i++) {
		//cout << p[i] << " ";
	//}

	gen("", s, k, x);

	int mx = 0;
	for (int i = 0; i < x.size(); i++) {
		int occ = 0;
		for (int j = 0; j < s - m + 1; j++) 
			if (strncmp(x[i].c_str() + j, l.c_str(), m) == 0) occ++;
		mx = max(mx, occ);
	}

	//dbge(mx);
	
	double ans = 0;
	double fr = 1.0 / x.size();
	for (int i = 0; i < x.size(); i++) {
		int occ = 0;
		for (int j = 0; j < s - m + 1; j++) 
			if (strncmp(x[i].c_str() + j, l.c_str(), m) == 0) occ++;
		ans += (mx - occ) * fr;
	}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output", "w", stdout);
	int t;
	cin >> t;
	
	for (int idx = 1; idx <= t; idx++) {
		int k, l, s;
		string a, b;
		cin >> k >> l >> s;
		cin >> a >> b;
		cout << "Case #" << idx << ": " << setprecision(15) << solve(s, a, b) << endl;
	}
	return 0;
}

