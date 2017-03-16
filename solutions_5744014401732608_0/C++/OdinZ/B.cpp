#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,b;
	long long m;
	cin >> t;
	for(int cs = 1; cs <= t; ++cs){
		cin >> b;
		cin >> m;
		printf("Case #%d: ", cs);
		if((1LL << (b - 2)) < m){
			//cerr << "impossible" << endl;
			printf("IMPOSSIBLE\n");
		}
		else{
			//cerr << "possible" << endl;
			printf("POSSIBLE\n");
			vector<int> adj(b, 1);
			adj[0] = 0;
			vector<long long> ways(b, 1LL);
			for(int i = b-3; i >=0; --i){
				ways[i] = ways[i+1] * 2LL;
			}
			long long w = ways[0];
			//for(int i = 0; i < b; ++i){
			//	cerr << ways[i] << " ";
			//}
			//cerr << endl;
			for(int i = 1; (i < b) && (w != m); ++i){
				if((w > m) && (w - ways[i] >= m)){
					w -= ways[i];
					adj[i] = 0;
				}
			}
			//cerr << "start print" << endl;
			for(int i = 0; i < b; ++i){
				cout << adj[i];
			}
			cout << endl;
			for(int j = 1; j < b - 1; ++j){
				for(int i = 0; i < b; ++i)
					cout << ((i <= j)? 0: 1);
				cout << endl;
			}
			for(int i = 0; i < b; ++i)
					cout << 0;
			cout << endl;
		}
	}
}