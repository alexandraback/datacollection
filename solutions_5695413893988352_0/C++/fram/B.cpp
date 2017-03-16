#include <iostream>
#include <string>
#include <cassert>
using namespace std;

typedef long long ll;

int n;
string c, j;

ll value(string s){
	//~ cerr << "S " << s << endl;
	ll p = 1;
	ll ans = 0;
	for(int i=n-1; i>=0; i--){
		if(!(s[i] >= '0' && s[i] <= '9')) cerr << "WARNING: " << (int)s[i] << endl;
		assert(s[i] >= '0' && s[i] <= '9');
		ans += p*((ll)(s[i]-'0'));
		p *= 10;
	}
	return ans;
}
string extreme(string s, char c){
	string t = s;
	for(int i=0; i<n; i++) if(t[i] == '?') t[i] = c;
	return t;
}
ll difference(string s, string t){
	cerr << "EVAL " << s << ' ' << t << endl;
	ll ans = value(s) - value(t);
	if(ans < 0) ans = -ans;
	return ans;
}


void solve(){
	cin >> c >> j;
	n = c.size();
	
	cerr << n << ' ' << c << ' ' << j << endl;
	
	string solc = extreme(c, '0');
	string solj = extreme(j, '0');
	ll sold = difference(solc, solj);
	
	string nc, nj;
	ll nd;
	
	for(int i=0; i<n; i++){
		if(c[i] == '?' && j[i] == '?'){
			c[i] = '0'; j[i] = '1';
			nc = extreme(c, '9'); nj = extreme(j, '0'); nd = difference(nc, nj);
			if(nd < sold || ((nd == sold) && (nc < solc)) || ((nd == sold) && (nc == solc) && (nj < solj))){sold = nd; solc = nc; solj = nj;}
			
			c[i] = '1'; j[i] = '0';
			nc = extreme(c, '0'); nj = extreme(j, '9'); nd = difference(nc, nj);
			if(nd < sold || ((nd == sold) && (nc < solc)) || ((nd == sold) && (nc == solc) && (nj < solj))){sold = nd; solc = nc; solj = nj;}
			
			c[i] = '0'; j[i] = '0';
		}else if(c[i] == '?'){
			if(j[i] > '0'){
				c[i] = j[i]-1;
				nc = extreme(c, '9'); nj = extreme(j, '0'); nd = difference(nc, nj);
				if(nd < sold || ((nd == sold) && (nc < solc)) || ((nd == sold) && (nc == solc) && (nj < solj))){sold = nd; solc = nc; solj = nj;}
			}
			if(j[i] < '9'){
				c[i] = j[i]+1;
				nc = extreme(c, '0'); nj = extreme(j, '9'); nd = difference(nc, nj);
				if(nd < sold || ((nd == sold) && (nc < solc)) || ((nd == sold) && (nc == solc) && (nj < solj))){sold = nd; solc = nc; solj = nj;}
			}
			c[i] = j[i];
		}else if(j[i] == '?'){
			if(c[i] > '0'){
				j[i] = c[i]-1;
				nc = extreme(c, '0'); nj = extreme(j, '9'); nd = difference(nc, nj);
				if(nd < sold || ((nd == sold) && (nc < solc)) || ((nd == sold) && (nc == solc) && (nj < solj))){sold = nd; solc = nc; solj = nj;}
			}
			if(c[i] < '9'){
				j[i] = c[i]+1;
				nc = extreme(c, '9'); nj = extreme(j, '0'); nd = difference(nc, nj);
				if(nd < sold || ((nd == sold) && (nc < solc)) || ((nd == sold) && (nc == solc) && (nj < solj))){sold = nd; solc = nc; solj = nj;}
			}
			j[i] = c[i];
		}else if(j[i] < c[i]){
			c = extreme(c, '0');
			j = extreme(j, '9');
		}else if(c[i] < j[i]){
			c = extreme(c, '9');
			j = extreme(j, '0');
		}
	}
	
	nc = c; nj = j; nd = difference(nc, nj);
	if(nd < sold || ((nd == sold) && (nc < solc)) || ((nd == sold) && (nc == solc) && (nj < solj))){sold = nd; solc = nc; solj = nj;}
	cout << solc << ' ' << solj << endl;
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
