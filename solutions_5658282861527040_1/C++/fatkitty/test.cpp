#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <math.h>
#include <map>

using namespace std;

int main(int argc, char** argv) {

	int T;
	cin >> T;

	long long A, B, K;
	for(int i=0; i<T; i++) {
		cin >> A;
		cin >> B;
		cin >> K;
		long long count = 0;

		long long mint = min(A,B)-1;
		long long maxt = max(A,B)-1;
		for(long long a=K; a<A; a++) {
			for(long long b=K; b<B; b++) {
				long long res = (a&b);	
				if(res>=K) count++;
			}
		}

		cout << "Case #" << i+1 << ": " << A*B-count << endl;
	}

/*	int ans = 0;
		int i=1;
	K = 35;
	int count = 0;
	for(int a=0; a<45; a++) {
		for(int b=0; b<56; b++) {
			if((a&b)>=K) {
				cout << "a,b are " << a <<"," << b << ","<< ", a&b is " << (a&b) << endl;
				count++;
			}
			i++;
			ans = max(ans, (a&b));
		}
	}
	cout << "i is " << count << " and max is " << ans << endl;
*/
}
