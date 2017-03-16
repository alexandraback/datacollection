#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007

signed main() {
	freopen("a.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	for(int t=1;t<=tt;t++){
		cout << "Case #" << t << ": ";
		int n,m;
		cin >> n >> m;
		int a[n][n];
		memset(a,0,sizeof(a));
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n-1;j++){
				a[i][j]=1;
			}
		}
		int mm = 1LL<<(n-2);
		if(mm<m){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << "POSSIBLE\n";
		if(mm==m){
			for(int i=0;i<n-1;i++) a[i][n-1] = 1;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					cout << a[i][j];
				}
				cout << "\n";
			}
			continue;
		}
		for(int i=n-3;i>=0;i--){
			if((1LL<<i)&m){
				a[i+1][n-1] = 1;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
    return 0;
}
