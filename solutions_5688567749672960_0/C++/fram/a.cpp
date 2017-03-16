#include <iostream>
using namespace std;

int f[1000001];

int inv(int x){
	int y = 0;
	while(x){
		y = y*10 + x%10;
		x/=10;
	}
	return y;
}

int sol(int x){
	if(x == 1) return 1;
	if(f[x]) return f[x];
	f[x] = sol(x-1) + 1;
	int i=inv(x); if(x%10 != 0 && i<x){
		int s=sol(i); if(s+1 < f[x]) f[x] = s+1; 
	}
	return f[x];
}

void solve(){
	int n;
	cin >> n;
	cout << sol(n) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		cout.flush();
		solve();
	}
	
	return 0;
}
