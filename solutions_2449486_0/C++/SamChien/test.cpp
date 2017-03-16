#include <iostream>
#include <map>
using namespace std;

typedef map<int, int> lawnCols;

int main() {
	int n;

	cin >> n;
	for (int i=1; i<=n; i++) {
		int a, b;
		map<int, lawnCols> lawn;
		map<int, int> rowMax;
		map<int, int> colMax;
		bool imp = false;

		cin >> a >> b;
		for (int j=0; j<a; j++) {
			for (int k=0; k<b; k++)
				cin >> lawn[j][k];
		}

		for (int j=0; j<a; j++) {
			int max = -1;

			for (int k=0; k<b; k++)
				if (lawn[j][k] > max)
					max = lawn[j][k];
			rowMax[j] = max;
		}

		for (int j=0; j<b; j++) {
			int max = -1;

			for (int k=0; k<a; k++)
				if (lawn[k][j] > max)
					max = lawn[k][j];
			colMax[j] = max;
		}

		for (int j=0; j<a; j++) {
			for (int k=0; k<b; k++) {
				if (lawn[j][k] < rowMax[j] && lawn[j][k] < colMax[k]) {
					imp = true;
					break;
				}
			}
			if (imp)
				break;
		}

		if (imp)
			cout << "Case #" << i << ": NO\n";
		else
			cout << "Case #" << i << ": YES\n";
	}
	return 0;
}
