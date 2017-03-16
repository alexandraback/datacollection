#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,n) fr(i,0,n)
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	int casos;
	 cin >> casos;
	 
	 rep(cas, casos){
	 	ll t, r;
	 	cin >> r >> t;
	 	
	 	int cont = 0;
	 	while(1){
			ll qtd = (r+1)*(r+1) - r * r;
			if(qtd > t) break;
			++cont;
			t -= qtd;
			r += 2;
		}
		cout << "Case #" << (cas+1) << ": " <<  cont << endl;
	 }
}


