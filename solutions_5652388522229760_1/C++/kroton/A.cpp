#include <iostream>
using namespace std;
typedef long long ll;

void solve(ll N){
	if(N == 0){
		cout << "INSOMNIA";
		return;	
	}
	const int goal = (1 << 10) - 1;
	int mask = 0;
	for(int i=1;;i++){
		ll T = i * N;
		while(T > 0){
			mask |= 1 << (T % 10);
			T /= 10;
		}
		if(mask == goal){
			cout << i * N;
			return;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		int N;
		cin >> N;
		cout << "Case #" << t << ": ";
		solve(N);
		if(t != T){
			cout << endl;
		}
	}
	return 0;
}
