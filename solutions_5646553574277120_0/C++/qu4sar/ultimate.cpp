//AV
//quasar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int c, d, v, cs = 1;
	int a[10];
	
	cin >> t;
	while (t--){
		cin >> c >> d >> v;
		int b[60] = { 0 }, z;
		set<int> s;
		for (int i = 0; i < d; i++){
			cin >> z;
			s.clear();
			for (int j = 1; j <= v; j++){
				if (b[j] && j + z <= v)s.insert(j + z);
			}
			for (int ss : s)
				b[ss] = 1;
			if (z <= v)b[z] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= v; i++)if (!b[i]){
			ans++;
			int z = i;
			s.clear();
			for (int j = 1; j <= v; j++){
				if (b[j] && j + z <= v)s.insert(j + z);
			}
			for (int ss : s)
				b[ss] = 1;
			if (z <= v)b[z] = 1;
		}
		cout << "Case #"<<cs<<": "<<ans<<"\n";
		cs++;
	}
}
