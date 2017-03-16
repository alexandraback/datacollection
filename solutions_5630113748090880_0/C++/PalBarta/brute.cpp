#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <queue>
#include <map>
using namespace std;

vector<int> a(100000);

int res[5000];

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		// Problem starts here
		
		memset(&a[0], 0, 5000 * 4);

		//vector< vector<int> > lists(150);
		int N;
		cin >> N;
		//vector<int> l(50);
		for(int j=0; j < 2*N-1; j++) {
			for (int i = 0; i < N; i++) {
				int m;
				cin >> m;
				a[m]++;
			}
			//lists.push_back(l);
		}


		int ri = 0;
		for (int i = 1; i <= 2500; i++) {
			if (a[i] % 2 == 1) {
				res[ri] = i;
				ri++;
			}
		}


		int result;

		for (int i = 0; i < N; i++) {
			cout << res[i] << " ";
		}
		// Problem ends here
		cout << endl;
	}

	return 0;
}