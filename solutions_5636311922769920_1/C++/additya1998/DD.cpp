#include<bits/stdc++.h>
#define int unsigned long long int
using namespace std;
int k[110];
signed main(){
	freopen("D-large.in","r",stdin);
	freopen("D_large.out","w",stdout);
	int t;
	cin >> t;
	int c= 0;
	while(t--){
		++c;
		int K,C,S;
		cin >> K >> C >> S;
		k[0] = 1;
		for(int i=1; i<=C; ++i) k[i] = k[i-1]*K;
		cout << "Case #" << c << ": ";
		if(K > C*S){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		int cur = 0;
		int done = 1;
		while(true){
			if(done>K) break;
			int pre = 0;
			for(int i=1; i<=C; ++i){
				if(done<=K){
					pre = pre + k[C-i]*(done-1);
					++done;	
				} 
				else break;
			}
			cout << pre + 1 << ' ';
		}
		cout << endl;
	}
}
