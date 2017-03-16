#include <iostream>
#include <set>

using namespace std;

int N,M;
int AA[120]; // typ
long long aa[120]; // num
int BB[120];
long long bb[120];


long long solv(int a, int b) {
	if (a >= N || b >= M) {
		return 0;
	}

	//	cout << N << "," << M <<  endl;

	// put
	long long ans = 0;
	for (int i = b; i < M; i++) {
		if (BB[i] == AA[a]) {
			int da = 0, db = 0;
			long long d = 0;
			if (aa[a] < bb[i]) {
				d = aa[a];
			} else {
				d = bb[i];
			}
			bb[i] -= d;
			aa[a] -= d;
			if (aa[a] == 0) da = 1;
			if (bb[i] == 0) db = 1;
			ans = d + solv(a+da,i+db);
			//  cout << a << " " << i  << " "  << d  << " ->" << ans<< endl;
			bb[i] += d;
			aa[a] += d;
			break;
		}
	}
	
	// throw a
	long long ans1 = solv(a+1,b);

	if (ans1 > ans) {
		ans = ans1;
		// cerr << "throw!" << endl;
	}

	return ans;
}


int main() {

	int T;
	cin >> T;

	for (int tt=0;tt<T;tt++) {
		cin >> N >> M;
		for (int i=0;i<N; i++) {
			cin >> aa[i];
			cin >> AA[i];
		}
		for (int i=0;i<M; i++) {
			cin >> bb[i];
			cin >> BB[i];
		}
		
		
		long long ans = solv(0,0);

		cout << "Case #" << (tt+1) << ": ";
		cout << ans;
		cout << endl;
	}

	return 0;
}

// 75
// 34.666667 + 26.666667 + 38.666667


