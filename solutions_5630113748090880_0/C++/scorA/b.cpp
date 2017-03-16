#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {

	int t;
	cin >> t;

	int n;

	for (int i = 0; i < t; i++) {
		cin >> n;
		vector< vector<int> > d((2*n)-1, vector<int>(n)); 
		int aa[2600] = {0};
		for (int j = 0; j < (2*n)-1; j++) {
			for (int k = 0; k < n; k++) {
				cin >> d[j][k];
				aa[d[j][k]]++;
			}
		}

		printf("Case #%d:", i+1);

		for (int i = 0; i < 2600; i++) {
			if (aa[i] % 2 == 1) {
				printf(" %d", i);
			}
		}
		cout << endl;
	}

	return 0;
}