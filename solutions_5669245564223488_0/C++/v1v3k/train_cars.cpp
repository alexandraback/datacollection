#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <set>
#include <cstring>
#include <sstream>
#include <stack>
#include <map>
#include <numeric>
using namespace std;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define out(x) cout << (x) << endl;
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
const int INF = (long long) 1e9;
const ll MOD = INF + 7;

ll fact[110];

string compress(string s) {
	string res;
	char last = 0;
	for(int i = 0; i < s.size(); i++) {
		if (s[i] != last) {
			res += s[i];
			last = s[i];
		}
	}
	return res;
}

bool validate(string s) {
	string t = compress(s);
	for(int i = 0; i < t.size(); i++) 
		for(int j = 0; j < i; j++)
			if (t[j] == t[i])
				return false;
	return true;
}

void solve(int t, vector<string> cars) {
	int n = cars.size();

	ll ans = 1, flag = 0;

	for(int i = 0; i < n; i++)
		if (!validate(cars[i])) {
			// puts("validate failed");
			printf("Case #%d: %d\n", t, 0);
			return;
		}

	// try compress
	sort(all(cars));
	vector<string> totry;
	string last = cars[0];
	int ctr = 0;
	for(int i = 0; i < n; i++) {
		if (cars[i] != last) 
		{
			totry.pb(last);
			last = cars[i];
			ans = (ans * fact[ctr]) % MOD;
			ctr = 1;
		} else if (cars[i] == last && last.size() > 1 && i != 0) {
			// puts("compress failed");
			printf("Case #%d: %d\n", t, 0);
			return;
		} else {
			ctr++;
		}
	}

	totry.pb(last);
	ans = (ans * fact[ctr]) % MOD;

	// try to join coherent structures
	vector<string> final;
	vi used(totry.size() == 0);

	for(int i = 0; i < totry.size(); i++) {	
		int left = 0, right = 0, lleft=-1, lright=-1;
		for(int j = 0; j < i; j++) {
			if (i != j) {
				if (totry[i][0] == totry[j].back()) {
					left++;
					lleft = j;
				}
			}
		}
		for(int j = 0; j < i; j++) {
			if (i != j) {
				if (totry[i].back() == totry[j][0]) {
					right++;
					lright = j;
				}
			}
		}

		if (left > 1 || right > 1) {
			printf("Case #%d: %d\n", t, 0);
			// puts("more possibilities");
			return;
		}

		if (lleft != -1) {
			totry[i] = totry[lleft] + totry[i];
			totry[lleft] = "";
		}
		if (lright != -1) {
			totry[i] = totry[lright] + totry[i];
			totry[lright] = "";
		}
	}
	int cnt = 0;
	for(int i = 0; i < totry.size(); i++) {
		if (totry[i] != "") {
			cnt++;
			final.pb(compress(totry[i]));
		}
	}

	int seen[256] = {0};

	for(int i = 0; i < final.size(); i++) {
		for(int j = 0; j < final[i].size(); j++) {
			if (seen[final[i][j]]) {
				printf("Case #%d: %d\n", t, 0);
				// puts("Exclusivity failed");
				return;
			} else {
				seen[final[i][j]] = 1;
			}
		}
	}

	ans = (ans * fact[cnt]) % MOD;
	printf("Case #%d: %lld\n", t, ans);
}	

int main() {
	fact[0] = 1;
	for(int i = 1; i < 110; i++) fact[i] = (i * fact[i-1]) % MOD; 

	int T;
	cin >> T;
	for(int i = 0; i < T; i++) {
		int n;
		cin >> n;
		vector<string> words;
		for(int j = 0; j < n; j++) {
			string s;
			cin >> s;
			words.pb(compress(s));
		}
		solve(i+1, words);
	}
	return 0;
}