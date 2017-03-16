#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		string S; cin >> S;
		vector<int> a(26);
		for (char c: S) a[c - 'A']++;
		char c[] = {'z', 'w', 'u', 'x', 'g', 'o', 't', 'f', 's', 'n'};
		string s[] = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
		int b[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
		string ans;
		for (int i = 0; i < 10; i++) {
			int k = c[i] - 'a';
			while (a[k]) {
				for (char c: s[i])
					a[c - 'a']--;
				ans.push_back('0' + b[i]);
			}
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d: ", t);
		cout << ans << endl;
	}
}
