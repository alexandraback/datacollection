#include <iostream>

using namespace std;

int main() 
{
	int tests;
	cin >> tests;
	unsigned long long limit[51];
	limit[2] = 1;
	limit[3] = 2;
	for (int i = 4; i < 51; ++i) {
		limit[i] = limit[i-1] + limit[i-2] + i - 3;
	}
	
	
	
	
	for (int i = 0; i < tests; ++i) {
		cout << "Case #" << i + 1 << ": ";
		int build, ways;
		cin >> build >> ways;
		//cout << endl << ways << " " << build << " " << limit[build] << endl;
		if (ways > limit[build]) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << "POSSIBLE\n";
		bool lad[51][51] = {0};
		int curRow = 1;
		int curCol = build-1;
		lad[1][build] = 1;
		while (--ways) {
			lad[curRow][curCol] = 1;
			lad[curCol][build] = 1;
			--curCol;
			if (curCol == curRow) {
				++curRow;
				curCol = build - 1;
			}
		}
		for (int j = 1; j <= build; ++j) {
			for (int k = 1; k <= build; ++k) {
				cout << lad[j][k];
			}
			cout << endl;
		}
		
	}
	
	return 0;
}