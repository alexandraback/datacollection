#include <iostream>

using namespace std;

#define ll long long int
#define endl '\n'

int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);
	int T;
	cin >> T;
	int Case = 1;
	while (T--){
		int K, C, S;
		cin >> K >> C >> S;
		cout << "Case #" << Case << ":";
		for (int i = 1; i <= K; i++){
			cout << ' ' << i;
		}
		cout << endl;
		Case++;
	}
}