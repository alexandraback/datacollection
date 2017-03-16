#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small.out", "w", stdout);
	int t;
	cin >> t;
	for(int caseNum = 1; caseNum <= t; caseNum++) {
		int k, c, s;
		cin >> k >> c >> s;
		if(s*c < k) {
			cout << "Case #" << caseNum << ": IMPOSSIBLE" << endl;
			continue;
		}
		if(c == 1) {
			cout << "Case #" << caseNum << ":";
			for(int i = 1; i <= k; i++) {
				cout << " " << i;
			}
			cout << endl;
			continue;
		}
		cout << "Case #" << caseNum << ":";
		int nextNum = 0;
		while(nextNum < k) {
			long currentPos = nextNum;
			nextNum++;
			for(int i = 1; i < c; i++) {
				currentPos *= k;
				currentPos += (nextNum < k ? nextNum : 0);
				nextNum++;
			}
			cout << " " << currentPos + 1;
		}
		cout << endl;
	}
	return 0;
}