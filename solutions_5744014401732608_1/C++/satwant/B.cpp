#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn = 55;
int e[maxn][maxn];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tests; cin >> tests;
	for (int test=1;test<=tests;test++){
		int b; ll m; cin >> b >> m;
		cout << "Case #" << test << ": ";
		if(m > (1ll<<(b-2))) cout << "IMPOSSIBLE\n";
		else {
			cout << "POSSIBLE\n";
			memset(e,0,sizeof e);
			for(int i=1;i<b-1;i++)
				for(int j=0;j<i;j++) e[j][i] = 1;
			for(int i=b-2;i>=0;i--) if((1ll<<max(0,i-1)) <= m){
				e[i][b-1] = 1; m -= (1ll<<max(0,i-1));
			}
			for(int i=0;i<b;i++){
				for(int j=0;j<b;j++) cout << e[i][j];
				cout << "\n";
			}
		}
	}
	return 0;
}