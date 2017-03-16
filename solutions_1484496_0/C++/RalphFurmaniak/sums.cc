#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long i64;

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		int N;
		cin >> N;
		vector<i64> v(N);
		for(int i=0; i<N; i++) cin >> v[i];
		map<i64,int> sn;
		cout << "Case #" << ts << ": " << endl;
		for(int msk=1; msk<(1<<N); msk++) {
			i64 su = 0;
			for(int i=0; i<N; i++) if(msk&(1<<i)) su+=v[i];
			int& msk2 = sn[su];
			if(msk2) {
				for(int i=0; i<N; i++) if(msk2&(1<<i)) cout << " " << v[i]; cout << endl;
				for(int i=0; i<N; i++) if(msk&(1<<i)) cout << " " << v[i]; cout << endl;
				break;
			}
			msk2 = msk;
		}
	}
}
