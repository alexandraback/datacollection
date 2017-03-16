#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll eval(ll i, ll K, ll C) {
	ll ret=0, cur=(i-1);
	for (int t=1; t<=C-1; t++)
		cur*=K, ret+=cur;
	ret+=i+1;
	return ret;
}

ll eval2(ll K, ll C) {
	ll ret=1;
	for (int i=0; i<C; i++)
		ret*=K;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		ll K,C,S; cin>>K>>C>>S;
		cout << "Case #" << c << ":";
		if(K==S) {
			for (int i=0; i<S; i++)
				cout << " " << i+1;
			cout << endl;
		}
		else {
			if(C==1) cout << " IMPOSSIBLE" << endl;
			else {
				if(2*S>=K) {
					for (int i=1; i<K; i+=2)
						cout << " " << eval(i,K,C);
					if(K%2) cout << " " << eval2(K,C);
				} else cout << "IMPOSSIBLE";
				cout << endl;
			}
		}
	}
	return 0;
}
