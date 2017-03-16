#include <iostream>
#include <string>

using namespace std;

int main() {
	int cases=0;
	cin >> cases;
	int caseNum=0;
	while (caseNum < cases) {
		caseNum++;
		cout << "Case #" << caseNum << ":";
		int k = 0;
		cin >> k;
		int c = 0;
		cin >> c;
		int s = 0;
		cin >> s;
		int sNeeded = k/c+(k%c!=0);
		if (s < sNeeded) {
			cout << " IMPOSSIBLE" << endl;
		} else {
			unsigned long long loc = 1;
			int target = 1;
			int level = 1;
			while (target < k) {
				if (level < c) {
					target++;
					loc=k*(loc-1)+target;
					level++;
				}else {
					cout << " " << loc;
					level=1;
					loc=++target;
				}
			}
			cout << " " << loc << endl;
		}
	}
	return 0;
}

