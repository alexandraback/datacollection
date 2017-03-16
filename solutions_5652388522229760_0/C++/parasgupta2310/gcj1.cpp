#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll inf = 1e18;
ll arr[1000001];

ll find_frst(ll n,int d){
	for(int i=1;i<=1000;i++){
		ll no = (n*i);
		while(no){
			int dig = no%10;
			if(dig==d)	return n*i;
			no/=10;
		}
	}
	return inf;
}

ll solve(ll i){
	bool f = 0;
	ll res = -1;
	for(int j=0;j<10;j++){
		res = max(res,find_frst(i,j));
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);	cin.tie();
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	for(int tt=1;tt<=t;tt++){
		int n;	cin>>n;
		cout<<"case #"<<tt<<": ";
		ll res = solve(n);
		if(res==inf)	cout<<"INSOMNIA\n";
		else cout<<res<<'\n';
	}
}