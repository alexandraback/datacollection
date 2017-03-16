#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

int main(void) {
	int T, D, tmp;
	cin >> T;
	vector<int> vec;
	for( int i = 1; i <= T; ++ i ) {
		cin >> D;
		int max = 0;
		for( int j = 0; j < D; ++ j) {
			cin >> tmp;
			if( max < tmp ) max = tmp;
			vec.push_back(tmp);
		}
		int ans = max;
		for( int j = 1; j < max; ++ j ) {
			int sum = j;
			for( size_t k = 0; k < vec.size(); ++ k ) {
				if( vec[k] % j == 0 )
					sum += vec[k] / j - 1;
				else
					sum += vec[k] / j;
			}
			if( sum < ans ) ans = sum;
		}
		cout << "Case #" << i << ": " << ans << endl;
		vec.clear();
	}
	return 0;
}
