#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool slides[50][50];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0; i < 50; i++) {
		for(int j = 0; j < 50; j++) {
			slides[i][j] = false;
		}
	}
	for(int caseNum = 1; caseNum <= t; caseNum++) {
		int b;
		long long m;
		cin >> b >> m;
		for(int i = 0; i < 50; i++) {
			for(int j = i + 1; j < 50; j++) {
				if(j < b-1)
					slides[i][j] = true;
				else slides[i][j] = false;
			}
		}
		long pow2 = 1LL << (b-2);
		if(pow2 < m) {
			cout << "Case #" << caseNum << ": IMPOSSIBLE" << endl;
			continue;
		}
		if(pow2 == m) {
			for(int i = 0; i < b-1; i++)
				slides[i][b-1] = true;
		}
		else {
			for(int i = 1; i < b-1; i++) {
				if(((m >> (i-1)) & 1) == 1)
					slides[i][b-1] = true;
				else
					slides[i][b-1] = false;
			}
		}
		cout << "Case #" << caseNum << ": POSSIBLE" << endl;
		for(int i = 0; i < b; i++) {
			for(int j = 0; j < b; j++) {
				cout << slides[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}