#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	
	int T;
	cin >> T;
	for (int t=0; t<T; ++t) {
		cout << "Case #" << t+1 << ": ";
		long long K, C, S;
		cin >> K >> C >> S;
		if (S*C < K) {
			cout << "IMPOSSIBLE";
		}
		else {
			long long d = 0;
			while(d<K) {
				long long pos = 0;
				long long len = 0;
				while ( (len<C) && (d<K) ) {
					pos = d + K*pos;
					++d;
					++len;
				}
				cout << (pos+1);
				if (d<K) cout << " ";
			}
		}
		cout << "\n";
	}
	return 0;
} 
