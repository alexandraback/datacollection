#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		ll K,C,S;
    	cin>>K>>C>>S;
    	cout<<"Case #"<<i+1<<": ";
		if ((K-1)/C+1>S) cout<<"IMPOSSIBLE"<<endl;
		else{
			ll l=0;
			for (ll j=0;j<(K-1)/C+1;j++) {
				ll u=0;
				for (ll k=0; k<C; k++)	{
					u=u*K+l;
					if(l<K-1) l++;
				}
				cout<<u+1<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
}