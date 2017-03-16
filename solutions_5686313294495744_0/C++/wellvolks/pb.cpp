#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t, k = 1;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a, b;
		vector < pair < string, string > > vet;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			vet.push_back(make_pair(a, b));
		}
		int ans = 0;
		for(int i = 0; i < (1 << n); i++){
			vector < pair < string, string > > va, vb;
			for(int j = 0; j < n; j++){
				if( i & (1 << j) ) vb.push_back(vet[j]);
				else va.push_back(vet[j]);
			}
			int ok = 0;
			for(int j = 0; j < va.size(); j++){
				bool c1 = false, c2 = false;
				for(int z = 0; z < vb.size(); z++){
					if( va[j].first == vb[z].first && va[j].second != vb[z].second ) c1 = true;
					if( va[j].first != vb[z].first && va[j].second == vb[z].second ) c2 = true;
				}
				if( c1 && c2 ) ok++;
			}
			if( ok == va.size() ) ans = max(ans, ok);
		}
		cout << "Case #" << k++ << ": " << ans << '\n';
	}
	return 0;
}