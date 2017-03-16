#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("large.txt", "r", stdin);
	freopen("lout.txt", "w", stdout);

	int T, N, J; cin >> T >> N >> J;
	cout << "Case #1:" << endl;
	for (int i = 0; i < J; i++){
		unsigned ans = (1u << (N - 1)) + 1;
		for (int j = 0; j < (N / 2 - 1); j++){
			if (i&(1 << j)){
				int L = j + 1;
				int R = (N - 1) - L;
				ans |= (1 << L);
				ans |= (1 << R);
			}
		}
		for (int i = 0; i < N; i++) if (ans&(1 << i)) cout << 1; else cout << 0;
		for (int i = 2; i <= 10; i++) cout << ' '<< i + 1;
		cout << endl;
	}
}