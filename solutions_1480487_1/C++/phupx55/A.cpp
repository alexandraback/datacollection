#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int n, s[1000];

void solve(){
	cin >> n;
	int ans;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		sum += s[i];
	}
	int csum = 0;
	int count =0;
	for(int i= 0; i <n ; i++){
		if(s[i] > 2.0*sum/n){
			csum += s[i];
			count++;
		}
	}
	for(int i = 0; i <n; i++){
		double ans;
		if(s[i] >= 2.0*sum/n)
			ans = 0.0;
		else
			ans = 100*((2.0*sum - csum)/(n- count) - s[i])/sum;
		printf("%.6f ", ans);
	}
	cout << endl;
	return;
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tc;
	cin >> tc;
	for(int ti = 0; ti < tc; ti++){
		printf("Case #%d: ", ti+1);
		solve();
	}
	return 0;	
}



