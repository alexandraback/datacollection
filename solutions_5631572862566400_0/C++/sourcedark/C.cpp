#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <fstream>
using namespace std;

/* --------------------------------- */
 
#define ios ios_base::sync_with_stdio(false)

template<class T> T stoi(string str) {
	T ret = 0;
	for (int i = 0; i < str.size(); i++) ret = ret * 10 + str[i] - '0';
	return ret;
}

bool updateType1(int now, int &ans) {
	if (ans == -1 || ans > now) {
		ans = now;
		return true;
	}
	return false;
}

bool updateType2(int now, int &ans) {
	if (ans == -1 || ans < now) {
		ans = now;
		return true;
	}
	return false;
}

vector<long long> primesUnder(unsigned long long limit) {
	vector<long long> ret;
	vector<bool> u(limit + 1, false);
	for (long long j = 2; j <= limit; j++) if (!u[j]) {
		ret.push_back(j);
		if (j <= limit / j) {
			for (int k = j * j; k <= limit; k += j) u[k] = true;
		}
	}
	return ret;
}

class Edge {
public:
	int from, to;
	Edge *next;
	Edge(int from_, int to_, Edge *next_):from(from_), to(to_), next(next_) {} 
};

int findf(vector<int> &f, int i) {
	if (f[i] == i) return i;
	return f[i] = findf(f, f[i]);
}

/* --------------------------------- */

int cmp(vector<int> &a, vector<int> &b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;	
	}
	return false;
}

int main() {
	ios;
	
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	int tasks;
	cin >> tasks;
	for (int task = 1; task <= tasks; task ++) {
		int n;
		cin >> n;
		vector<int> next(n + 1);
		vector<int> deg(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> next[i];
			deg[next[i]] ++;
		}
		queue<int> qe;
		for (int i = 1; i <= n; i++) if (deg[i] == 0) qe.push(i);
		vector<int> h(n + 1, 0);
		vector<bool> bo(n + 1, false);
		while (!qe.empty()) {
			int i = qe.front(); qe.pop(); bo[i] = true;
			h[next[i]] = max(h[next[i]], h[i] + 1);
			if (--deg[next[i]] == 0) qe.push(next[i]);
		}
		vector<int> f(n + 1, 0);
		for (int i = 1; i <= n; i++) if (!bo[i]) f[i] = i;
		for (int i = 1; i <= n; i++) if (!bo[i]) f[findf(f, i)] = findf(f, next[i]);
		vector<int> h1(n + 1, 0);
		vector<int> h2(n + 1, 0);
		vector<int> s(n + 1, 0);
		for (int i = 1; i <= n; i++) if (!bo[i]) {
			int j = findf(f, i);
			s[j] ++;
			if (h[i] > h1[j]) {
				h2[j] = h1[j];
				h1[j] = h[i];
			}
			else if (h[i] > h2[j]) {
				h2[j] = h[i];
			}
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++) if (!bo[i] && findf(f, i) == i) {
			if (s[i] == 2) {
				ans2 = ans2 + s[i] + h1[i] + h2[i];
			}
			else {
				ans1 = max(ans1, s[i]);
			}
		}
		cout << "Case #" << task << ": " << max(ans1, ans2) << endl;
	}
	
	return 0;
}
