#include <bits/stdc++.h>
using namespace std;

int t,n,ok,ans; string a[20],b[20]; set<string> sa,sb;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("techbab.out","w",stdout);
	cin >> t;
	for (int tc=1;tc<=t;tc++){
		cout << "Case #" << tc << ": ";
		cin >> n; ans=1000000000;
		for (int i=0;i<n;i++) cin >> a[i] >> b[i];
		for (int i=0;i<(1<<n);i++){
			sa.clear(); sb.clear();
			for (int j=0;j<n;j++){
				if (i&(1<<j)){
					sa.insert(a[j]); sb.insert(b[j]);
				}
			}
			ok=1;
			for (int j=0;j<n;j++){
				if (!(i&(1<<j))){
					ok&=sa.count(a[j]); ok&=sb.count(b[j]);
				}
			}
			if (ok) ans=min(ans,__builtin_popcount(i));
		}
		cout << n-ans << "\n";
	}
}
