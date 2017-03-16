#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;


void main() {
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	//freopen("inputA.txt", "r", stdin);
	//freopen("outputA.txt", "w", stdout);
	int nCase;
	cin >> nCase;
	for (int cc = 0; cc < nCase; ++cc) {
		int r, c, w;
		cin >> r >> c >> w;
		int baseAttack = c / w;
		int mod = c % w;
		int addAttack = 0;
		if (mod != 0)
			addAttack++;
		addAttack += (w - 1);
		int ret = baseAttack + addAttack;
		ret = ret + (baseAttack * (r - 1));
		cout << "Case #" << cc + 1 << ": " << ret << endl;
	}
}