//AV
//quasar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, r, c, w, cs=1;
	cin >> t;
	while (t--){
		cin >> r >> c >> w;
		int ans = ceil((double)c / w) + w - 1+(c/w)*(r-1);
		cout << "Case #"<<cs<<": "<<ans << "\n";
		cs++;
	}
}
