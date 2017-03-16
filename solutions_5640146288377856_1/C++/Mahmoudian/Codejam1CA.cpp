//In the name of God
#include <bits/stdc++.h>
using namespace std;
ofstream fout("codejam.out");
#define cout fout
const int Maxn = 1e3 + 9;
int mark[Maxn];
int coin[Maxn];
int main(){
	int tc;
	cin >> tc;
	int ts = 0;
	while(tc--){
		cout << "Case #" << ++ts << ": ";
		int n,m,w;
		cin >> n >> m >> w;
		m -= w - 1;
		int bagh = m / w;
		if(m % w) bagh++;
		int ans = 0;
		ans += bagh * (n);
		if(w != 1)
			ans += w;
		if(m % w == 1) ans--;
		cout << ans << endl;
	}
}
