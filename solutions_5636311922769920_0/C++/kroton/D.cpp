#include <iostream>
using namespace std;
typedef long long ll;

void solve(int K, int C, int S){
	int lim = (K + C - 1) / C;
	if(S < lim){
		cout << "IMPOSSIBLE";
		return;
	}
	int step = 0;
	for(int i=0;i<lim;i++){
		ll q = 0;
		for(int j=0;j<C;j++){
			q *= K;
			q += step;
			step = min(K - 1, step + 1);
		}		
		cout << q + 1;
		if(i + 1 < lim){
			cout << " ";
		}
	}
}

int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		int K, C, S;
		cin >> K >> C >> S;
		cout << "Case #" << t << ": ";
		solve(K, C, S);
		if(t != T){
			cout << endl;
		}
	}
	return 0;
}

