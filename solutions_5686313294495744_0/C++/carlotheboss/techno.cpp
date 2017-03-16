#include <bits/stdc++.h>
using namespace std;

#define MAXN 20

typedef pair<string, string> ss;

int T, N;
ss words[MAXN];
map<string, int>prima, seconda;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for(int i=1;i<=T;i++) {
		cin >> N;
		
		for(int j=0;j<N;j++) cin >> words[j].first >> words[j].second;
		
		int ans=0;
		// Scelgo il gruppo di false
		for(int t=0;t < (1<<N);t++) {
			vector< ss >fakes;
			prima.clear();
			seconda.clear();
			fakes.clear();
			for(int k=0;k<N;k++) {
				if(t & (1<<k)) fakes.push_back(words[k]);
				else {
					prima[ words[k].first ]++;
					seconda[ words[k].second ]++;
				}
			}
			bool posso=true;
			for(ss k : fakes) if(prima[k.first]<=0 || seconda[k.second]<=0) posso=false;
			
			if(posso) ans=max(ans, (int)fakes.size());
		}
		cout << "Case #"<<i<<": "<<ans<<endl;
	}
	
	
	return EXIT_SUCCESS;
}
