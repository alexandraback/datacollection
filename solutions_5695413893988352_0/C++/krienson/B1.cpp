#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

bool matchPat( int n, string &p ){
	for( int i = int(p.length())-1; i>= 0; i-- ){
		if( p[ i] == '?' ){ n/=10; continue;}
		int v = int(p[i]-'0');
		if(	v != (n%10) ) return false;
		n /= 10;
	}
	return true;
}

int main(){
	int kases; cin >> kases;
	for( int kase = 1; kase <= kases; kase++ ){
		string c, j;
		cin >> c >> j ;
		int tam = int( c.length() );
		int lim = 1;
		for( int t = 0; t < tam; t++ ) lim*=10;
		int best_dif = 2000000000;
		int rc = -1, rj = -1;
		for( int ic = 0; ic < lim; ic++ ){
			for( int ij = 0; ij < lim; ij++ ){
				if( abs(ic-ij) < best_dif && matchPat( ic, c) && matchPat( ij, j) ){
					best_dif = abs( ic - ij );
					rc = ic; rj = ij;
				}
			}
		}//cout << rc << " " << rj << endl;
		c = ""; j = "";
		for( int i = 0; i < tam; i++){
			c = string(1,('0'+(rc%10))) + c;
			j = string(1,('0'+(rj%10))) + j;
			rc/=10; rj/=10;
		} 
		cout << "Case #" << kase <<": "<< c << " " << j << endl;
	}
}
