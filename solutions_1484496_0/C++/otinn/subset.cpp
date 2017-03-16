#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

int N;
vector <long long> num;

void show(int mask) {
	vector <long long> t;
	for(int i = 0; i < N; ++i)
		if(mask & (1 << i))
			t.push_back(num[i]);
	foreach(i, 0, t) {
		if(i)
			cout << " ";
		cout << t[i];
	}
	cout << endl;
}

bool found;
long long sol[2][500];

void Solve(int pos, int no1, int no2, int su1, int su2) {
	if(su1 > 0 && su1 == su2) {
		for(int i = 0; i < no1; ++i) {
			if(i)
				cout << " ";
			cout << sol[0][i];
		}
		cout << endl;
		for(int i = 0; i < no2; ++i) {
			if(i)
				cout << " ";
			cout << sol[1][i];
		}
		cout << endl;
		found = true;
		return;
	}
	if(pos == num.size())
		return;
	Solve(pos + 1, no1, no2, su1, su2);
	if(!found) {
		sol[0][no1] = num[pos];
		Solve(pos + 1, no1 + 1, no2, su1 + num[pos], su2);
		if(!found) {
			sol[1][no2] = num[pos];
			Solve(pos + 1, no1, no2 + 1, su1, su2 + num[pos]);
		}
	}
}

void Solve() {
	found = false;
	Solve(0, 0, 0, 0, 0);
	if(!found)
		cout << "Impossible" << endl;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> N;
		num.resize(N);
		foreach(i, 0, num)
			cin >> num[i];
		printf("Case #%d:\n", t + 1);
		Solve();
	}
	return 0;
}
