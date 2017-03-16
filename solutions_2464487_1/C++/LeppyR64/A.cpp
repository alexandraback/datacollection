#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
	
long long R,T;
	
bool possible(long long N) {
	long long A = (R+1)*(R+1)-R*R;
	long long L =  A+(N-1)*2ll;
	long long R =  T/N;
	return (L <= R);
}

	
int main() {
	int testcases;
	cin >> testcases;
	for(int curtestcase = 1; curtestcase <= testcases; curtestcase++) {
		cout << "Case #" << curtestcase << ":";
		cin >> R >> T;
		
		int lo = 1;
		int hi = 1007106780;
		
		//cout << endl;
		while(hi > lo) {
			//cout << lo << " " << hi << endl;
			long long m = (lo+hi+1)/2;
			if(possible(m))
				lo = m;
			else
				hi = m-1;
		}
		cout << " " << lo;
		cout << endl;
	}
}