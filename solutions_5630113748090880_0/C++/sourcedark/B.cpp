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
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	
	int tasks;
	cin >> tasks;
	for (int task = 1; task <= tasks; task ++) {
		int n;
		cin >> n;
		int m = 2 * n - 1;
		vector<int> count(3000, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int k;
				cin >> k;
				count[k] ++;
			}
		}
		cout << "Case #" << task << ":";
		for (int i = 0; i <= 2500; i++) if (count[i] % 2 == 1) cout << " " << i;
		cout << endl;
	}
	
	return 0;
}
