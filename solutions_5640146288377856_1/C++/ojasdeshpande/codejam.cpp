#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    freopen("a.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin >> t;
	for(int tt=1;tt<=t;tt++){
		cout << "Case #" << tt << ": ";
		int r,c,w;
		cin >> r >> c >> w;
		long long ans = 1;
		ans = c/w;
		ans = ans*r;
		ans += w;
		ans -= 1;
		if(c%w != 0) ans +=1;
		cout << ans << "\n";
	}
	return 0;
}
