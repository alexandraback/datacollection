#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

int K, S, L;
string key, target;
int bring;
double res;
int calc(string curr, string target) {
	if (curr.size() < target.size()) return 0;
	int cnt = 0;
	for (int i = 0; i + target.size() <= curr.size(); i++) {
		if (curr.substr(i, target.size()) == target) {
			cnt++;
		}
	}
	return cnt;
}
void dfs(string curr, double prob) {
	// cout << curr << " " << prob << endl;
	if (curr.size() == S) {
		int cnt = calc(curr, target);
		// cout << curr << " " << cnt << " " << prob << endl;
		bring = max(bring, cnt);		
		if (cnt > 0) {
			res += prob * cnt;
		}
		return;
	}
	for (int i = 0; i < K; i++) {
		curr.push_back(key[i]);
		prob = prob * 1.0 / K;
		dfs(curr, prob);
		curr.pop_back();
		prob = prob * K;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		cin >> K >> L >> S;
		cin >> key;
		cin >> target;
		
		res = 0;
		bring = 0;
		dfs("", 1.0);
		printf("Case #%d: %.8f\n", cas, bring - res);
	}
	return 0;
}

