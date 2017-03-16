#include <iostream>

using namespace std;

int solve(long long int P, long long int Q) {
	int j = 1;
	/*
	for(long long int i = 2;i <= 1099511627776;i=i*2){
		if(){

		}
		++j;
	}
	*/
	for(int i = 1;i <=40;++i){
		P*=2;
		if(P/Q>=1){
			return i;
		}
	}
	return -1;
}

void answer(int X, int ans) {
	cout << "Case #" << X << ": ";
	if (ans == -1) {
		cout << "impossible\n";
	} else {
		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	long long int P, Q;
	char slash;
	for (int i = 1; i <= T; ++i) {
		cin >> P >> slash >> Q;
		long long int tempQ = Q;
		while(true){
			if(tempQ%2==0){
				tempQ/=2;
			}else{
				break;
			}
		}
		if(P%tempQ==0){
			P/=tempQ;
			Q/=tempQ;
			int ans = solve(P, Q);
			answer(i, ans);
		}else{
			answer(i, -1);
		}
		/*
		for (long long int j = P; j > 1 && j <= P; --j) {
			if (Q % j == 0 && P % j == 0) {
				Q /= j;
				P /= j;
			}
		}
		*/
	}
	cout.flush();
	return 0;
}
