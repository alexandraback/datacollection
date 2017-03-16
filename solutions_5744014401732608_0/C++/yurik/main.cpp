#pragma comment(linker, "/STACK:216000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>
const int MAX = 1000001;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


void main() {
	//ios_base::sync_with_stdio(false);
	ifstream cin{ "in.txt" };
	ofstream cout{ "out.txt" };
	int t;
	cin >> t; 
	for (int qqq = 0; qqq < t; ++qqq) {
		cout << "Case #" << qqq + 1 << ": ";
		int b;
		ull m;
		cin >> b >> m;
		bool isok = false;
		for (int i = 0; i < b - 1; ++i) {
			if ((1 << i) >= m)
				isok = true;
		}
		if (!isok) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
		vector<int> from0(b, 0);
		m--;
		from0[b - 1] = 1;
		for (int i = 0; i < b - 1; ++i) {
			if ((m >> i) % 2)
				from0[b - i - 2] = 1;
		}
		for (int i = 0; i < b; ++i) {
			cout << from0[i];
		}
		cout << endl;
		for (int i = 1; i < b; ++i) {
			for (int j = 0; j < b; ++j) {
				cout << ((i < j) ? 1 : 0);
			}
			cout << endl;
		}
	}
	cin.close();
	cout.close();
}