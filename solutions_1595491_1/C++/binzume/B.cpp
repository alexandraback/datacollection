#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i< T; i++) {
		int N,S,p;
		cin >> N >> S >> p;
		vector<int> tt;
		int sup = 0;
		int ans = 0;
		for (int j=0 ; j< N ; j++) {
			int t;
			cin >> t;
			tt.push_back(t);
			if (t >= p*3-2) {
				ans ++ ;
			} else if (sup < S && t > 1 && t<=28 && t >= p*3-4) { // min: 0 0 2 max: 8 10 10
				ans ++;
				sup ++;
			}
		}

		cout << "Case #" << (i+1) << ": " << ans << endl;
	}
	
	
	return 0;
}


