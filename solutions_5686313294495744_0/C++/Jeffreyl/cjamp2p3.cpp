#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string, int> mapa, mapb;
int T, N; string in[2][1001];
int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>N;
		for (int i=0; i<N; i++) {
			cin>>in[0][i]>>in[1][i];
		}
		int ans=0;
		for (int mask=0; mask<(1<<N); mask++) {
			mapa.clear();
			mapb.clear();
			for (int j=0; j<N; j++) {
				if (mask&(1<<j)) { // if it is real
					mapa[in[0][j]]=1;
					mapb[in[1][j]]=1;
				}
			}
			bool fail=0; int count=0;
			for (int j=0; j<N; j++) {
				if (!(mask&(1<<j))) { // if it is fake
					count++;
					if (mapa[in[0][j]]&&mapb[in[1][j]]) continue;
					else fail=1;
				}
			}
			if (!fail) {
				ans=max(ans, count);
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}
