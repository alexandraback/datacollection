#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < (b); ++i)
#define rep(i, n) fr(i,0,n)
#define _(n) rep(i, n)
#define mp make_pair
#define ft first
#define sd second
#define pb push_back
#define SZ(x) int(x.size())
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long hash;

ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;


	fr(tt, 1, 1+t){
		ll a, b;
		char frac[1000];
		cin >> frac;
		int ind = 0;
		while(frac[ind] != '/') ++ind;
		frac[ind] = 0;
		sscanf(frac, "%lld", &a);
		sscanf(frac+ind+1, "%lld", &b);

		ll g = gcd(a, b);
		a /= g, b /= g;

		bool dm = false;
		int d = 40;		

		if((1LL << 40) % b) dm = true; 
		else{
			ll m = (1LL << 40) / b;
			if(a >= (1LL << 20) && m >= (1LL << 20)){ dm = true; goto sai; }
			a *= m;
			if(a > (1LL << 40)){ dm = true; goto sai;}

			while(a) --d, a /= 2;
		}
	sai:
	cout << "Case #" << tt << ": ";
		if(dm) cout << "impossible\n";
		else cout << (d+1) << endl;
	}

	
}

