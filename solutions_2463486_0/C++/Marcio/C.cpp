#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,n) fr(i,0,n)
#define N 1000
typedef long long ll;
#define pb push_back

ll a, b;
vector<ll> palin;

bool eh(ll num){
	ll r = 0, tmp = num;
	while(num){
		r = r * 10 + (num%10);
		num /= 10;
	}
	// cout << "xiii " << num << "  " << r << endl;
	return r == tmp;
}

int main(){
	// cout << "UE " << eh(1) << endl;
	// return 0;
	fr(i, 1, int(1e7+100)){
		if(eh(i) && eh(i*ll(i))) palin.pb(i*ll(i));
	}
	// cout << "KI " << palin.size() << endl;
	// rep(i, palin.size()) cout << palin[i] << endl;
	int t;
	cin >> t;
	rep(cas, t){
		cin >> a >> b;
		int menor = lower_bound(palin.begin(), palin.end(), a) - palin.begin();
		int maior = upper_bound(palin.begin(), palin.end(), b) - palin.begin();
		printf("Case #%d: %d\n", cas+1, maior - menor);
	}
}








