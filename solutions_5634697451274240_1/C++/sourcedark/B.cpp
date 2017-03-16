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

class Edge {
public:
	int from, to;
	Edge *next;
	Edge(int from_, int to_, Edge *next_):from(from_), to(to_), next(next_) {} 
};

/* --------------------------------- */

int testCase = 0;

int main() {
	ios;
	
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int task;
	cin >> task;
	while (task --) {
		string str;
		cin >> str;
		//cout << str << endl
		int ans = 0;
		for (int i = 0; i < str.length(); i++) {
		//	if (i > 0) cout << str[i] << ' ' << str[i - 1] << endl;
			if (i == 0 || str[i] != str[i - 1]) ans ++;
		}
		cout << "Case #" << ++testCase << ": " << (ans - (str[str.length() - 1] == '+')) << endl;
	}

	return 0;
}
