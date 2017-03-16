#include<iostream>
using namespace std;

#define ll long long int

void imprime(ll k, ll c, ll s){
	ll cont, aux=0, pot=k;
	int r=0;
	for(cont=1;cont<k;cont++){
		if(cont%c==0){
			cout << " " << aux+1;
			r++; pot=1; aux=0;
		}
		aux = aux + (pot*cont);
		pot*=k;
	}
	if( r<s ) cout << " " << aux+1;
		
}

int main(){
	int t;
	ll k, c, s;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> k >> c >> s;
		cout << "Case #" << tt+1 << ":";
		if( c*s < k )
			cout << " IMPOSSIBLE";
		else
			imprime(k, c, s);
		cout << endl;
	}
	return 0;
}
