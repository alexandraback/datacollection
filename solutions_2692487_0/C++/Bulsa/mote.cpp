#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	int T;
	cin >> T;
	for(int t=1; t<=T; ++t) {
		int A,N;
		cin >> A >> N;
		int other[N+1];
		for(int i=0; i<N; ++i) {
			cin >> other[i];
		}
		sort(other,other+N);
		int added = 0, opt = N;
		for(int i=0; i<N; ++i) {
			if(other[i]<A) {
				A += other[i];
				opt = min(opt,N-i-1+added);
			} else {
				if(A-1==0) break;
				A += A-1;
				++added;
				opt = min(opt,N-i-1+added);
				--i;
			}
		}
		cout << "Case #" << t << ": " << opt << endl;
	}
}
