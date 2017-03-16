#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll T,i,j,K,C,S,Count;
vector<ll> Ans;

int main() {
	cin >> T;
	for(i=1;i<=T;++i) {
		Ans.clear();
		Count=0;
		cin >> K >> C >> S;
		cout << "Case #" << i << ": ";
		if(K==S) {
			for(j=1;j<=S;++j) cout << j << " ";
			cout << endl;
		}
		else {
			if(C==1) {
				cout << "IMPOSSIBLE" << endl;
			}
			else {
				for(j=2;j<=K*K;j+=(K+1)) {
					++Count;
					Ans.push_back(j);
				}
				if(K==2) Count=2;
				if(Count>S) cout << "IMPOSSIBLE" << endl;
				else {
					for(j=0;j<Ans.size();++j) cout << Ans[j] << " ";
					cout << endl;
				}
			}
		}
	}
	return 0;
}
