#include <iostream>
#include <cstring>

using namespace std;

#define ll long long int
#define endl '\n'

bool done[10];

inline bool ready(){
	for (int i = 0; i < 10; i++){
		if (!done[i]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	int Case = 1;
	while (T--){
		memset(done, false, sizeof(done));
		ll N;
		cin >> N;
		if (N == 0) {
			cout << "Case #" << Case << ": INSOMNIA" << endl;
			Case ++; 
			continue;
		}
		ll cur = N;
		while(!ready()){
			ll temp = cur;
			while (temp){
				done[temp%10] = true;
				temp /= 10;
			}
			cur += N;
		}
		cout << "Case #" << Case << ": " << cur-N << endl;
		Case++;
	}

}