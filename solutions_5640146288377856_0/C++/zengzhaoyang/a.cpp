#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	for(int ii =1; ii <= t; ii++){
		int ans;
		int r,c,w;
		cin >> r >> c >> w;
		ans = (c/w)*r +w;
		if( c % w == 0)
			ans--;
		printf("Case #%d: %d\n",ii ,ans);
	}
}