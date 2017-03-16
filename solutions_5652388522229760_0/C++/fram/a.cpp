#include <iostream>
#include <vector>
using namespace std;


void solve(int n = -1){
	if(n < 0) cin >> n;
	if(n == 0) {cout << "INSOMNIA" << endl; return;}
	
	bool f[10] = {0};
	int tot = 0;
	int m = 0;
	
	while(tot < 10){
		m += n;
		int x = m;
		while(x){
			if(f[x%10] == false) {tot++; f[x%10] = true;}
			x/=10;
		}
	}
	cout << m << endl;
}

int main(){
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
