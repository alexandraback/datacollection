#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++){
		int a;
		cin >> a;
		int q[a], ma = 0, cou, t;
		for (int i = 0; i < a; i++){
			cin >> q[i];
			ma = max(ma, q[i]);
		}
		cou = ma;
		for (int i = ma; i >= 1; i--){
			t = 0;
			for (int j = 0; j < a; j++){
				t += (q[j] - 1) / i;
			}
			cou = min(cou, i + t);
		}
		cout << "Case #" << k << ": " << cou << endl; 
	}
	
	return 0;
}

