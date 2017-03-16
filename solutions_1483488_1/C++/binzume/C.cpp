#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	for (int i = 0; i< T; i++) {
		int A,B;
		cin >> A >> B;
		int ans = 0;
		for (int n = A; n <= B; n++) {
			int dd = 1;
			while(dd<=n) {
				dd*=10;
			}
			dd /=10;
			set<int> ss;
			for (int d=10; d <= B; d*=10) {
				int m = n/d + (n%d)*dd;
				//cout << d << " " << n << "," << m << endl;
				if (m > n && m <= B && ss.find(m) == ss.end()) {
					ss.insert(m);
					ans++;
				}
				dd/=10;
			}
			
		}

		cout << "Case #" << (i+1) << ": " << ans << endl;
	}
	
	
	return 0;
}


