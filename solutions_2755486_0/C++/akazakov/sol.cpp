#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Attack {
	long long day, strength, from, to;
	bool operator < (const Attack &x) {
		return day < x.day;
	}
};

struct Wall {
	unordered_map<int, int> height;
	bool applyAttack(const Attack &a) {
		bool success = false;
		for (int i = a.from; i < a.to; ++i) {
			if (height[i] < a.strength) {
				success = true;
			}
		}
		//cout << success << ": " << a.day << "/ " << a.from << " " << a.to << " " << a.strength << endl;
		return success;
	}
	void repairWall(const Attack &a) {
		for (int i = a.from; i < a.to; ++i) {
			if (height[i] < a.strength) {
				height[i] = a.strength;
			}
		}
	}
};

void addAttacks(vector<Attack> &out) {
	long long n, dd, dp, ds;
	Attack x;
	cin >> x.day >> n >> x.from >> x.to >> x.strength >> dd >> dp >> ds;
	for (int i = 0; i < n; ++i) {
		out.push_back(x);
		x.day += dd;
		x.from += dp;
		x.to += dp;
		x.strength += ds;
	}
}

void solveTestCase_stupid() {
	int n;
	cin >> n;
	vector<Attack> a;
	for (int i = 0; i < n; ++i) {
		addAttacks(a);
	}
	sort(a.begin(), a.end());
	int d = 1;
	long long res = 0;
	Wall w;
	for (int i = 0; i < a.size(); i += d) {
		for (d = 1; i + d < a.size() && a[i].day == a[i + d].day; ++d);
		for (int j = i; j < i + d; ++j) {
			res += w.applyAttack(a[j]);
		}
		for (int j = i; j < i + d; ++j) {
			w.repairWall(a[j]);
		}
	}
	cout << res;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << (i + 1) << ": ";
		solveTestCase_stupid();
		cout << endl;
	}
	return 0;
}