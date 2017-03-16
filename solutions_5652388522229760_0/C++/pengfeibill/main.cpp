#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int f(int n) {
	set<int> d;
	int num = 0;
	while (d.size() < 10) {
		num += n;
		int tmp = num;
		while (tmp) {
			d.insert(tmp % 10);
			tmp /= 10;
		}
	}
	return num;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		cout << "Case #" << i << ": ";
		if (n)
			cout << f(n) << endl;
		else
			cout << "INSOMNIA" << endl;
	}
	return 0;
}