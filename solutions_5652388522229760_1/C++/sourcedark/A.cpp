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
using namespace std;

/* --------------------------------- */
 
#define ios ios_base::sync_with_stdio(false)

template<class T> T stoi(string str) {
	T ret = 0;
	for (int i = 0; i < str.size(); i++) ret = ret * 10 + str[i] - '0';
	return ret;
}

void updateType1(int now, int &ans) {
	if (ans == -1 || ans > now) {
		ans = now;
	}
}

class Edge {
public:
	int from, to;
	Edge *next;
	Edge(int from_, int to_, Edge *next_):from(from_), to(to_), next(next_) {} 
};

/* --------------------------------- */

int testCase = 0;

void work(int n) {
	if (n == 0) {
		cout << "Case #" << ++ testCase << ": " << "INSOMNIA" << endl;
		return;
	}
	int count = 0, s = 0, t = 0;
	vector<bool> exist(10, false);
	while (count < 10) {
	//	cout << s << ' ' << count << endl;
		s += n, t ++;
		for (int p = s; p; p = p / 10) {
			if (!exist[p % 10]) {
				count  ++;
				exist[p % 10] = true;
			}
		}
	}
	cout << "Case #" << ++ testCase << ": " << s << endl;
	//cout << n << ' ' << s << ' ' << t << endl;
}
int main() {
	ios;
	
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	int task;
	cin >> task;
	while (task --) {
		int n;
		cin >> n;
		work(n);	
	}
	
	return 0;
}
