#include      <iostream>
#include      <fstream>
#include      <map>
#include      <cmath>
#include      <set>

using namespace std;
const int MAX = 2000001;

int len(int n) {
	return (n ? log10(n) : 0) + 1;
}
int rotate(int n, int by, int nLen) {
	const int p1 = pow(10, by);
	const int p2 = pow(10, nLen - by);
	return n / p1 + (n % p1) * p2;
}

set< pair<int, int> > setAll;

void generateAll() {
	pair<int, int> pairTmp;
	int nLen;

	for (int n = 0; n <= MAX; ++n) {
		nLen = len(n);
		for (int i = 1; i < nLen; ++i) {
			pairTmp.first = n;
			pairTmp.second = rotate(n, i, nLen);
			if (pairTmp.first != pairTmp.second) {
				if (pairTmp.second < pairTmp.first) {
					swap(pairTmp.second, pairTmp.first);
				}
				setAll.insert(pairTmp);
			}
		}
	}
}

bool between(int n, int l, int h) {
	return l <= n && n <= h;
}

int main(int argc, char **argv) {
	int nTests, nFrom, nTo, nResult;
	freopen("input", "r", stdin);
	cin >> nTests;

	generateAll();

	for (int nTest = 1; nTest <= nTests; ++nTest) {
		cin >> nFrom >> nTo;
		nResult = 0;
		for (set< pair<int, int> >::const_iterator it = setAll.begin(); it != setAll.end(); ++it) {
			if (between(it->first, nFrom, nTo) && between(it->second, nFrom, nTo)) {
				++nResult;
			}
		}
		cout << "Case #" << nTest << ": " << nResult << endl;
	}

	return 0;
}
