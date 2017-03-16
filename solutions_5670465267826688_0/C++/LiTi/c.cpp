/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

string calc() { 
	int l;
	ll x;
	cin >> l >> x; 
	string s;
	cin >> s; 

	if( x > 12 ) 
		x = x % 12 + 12;
	string t = "";
	for( int i = 0 ; i < x ; i++ ) 
		t += s;

	char curr = '1'; int z = 1;
	swap(s,t);
	int lvl = 0;
	for( int i = 0 ; i < sz(s) ; i++ ) { 
		if( curr == '1' ) 
			curr = s[i];
		else if( s[i] == curr ) {
			curr = '1';
			z *= -1;
		} else {
			if( min( curr , s[i] ) == 'i' && max( curr , s[i] ) == 'k' ) swap( curr, s[i] ) ;
			if( curr > s[i] ) z *= -1;
			curr = char( int('i') + int('j') + int('k') - s[i] - curr ) ;
		}
	//	cerr << curr << ' ' << z << endl;
		if( curr == char('i' + lvl)  && z == 1 ) {
			curr = '1';
			lvl++;
	//		cout << "CHANGED" << endl;
		}
	}
//	cerr << lvl << ' ' << curr << ' ' << z << endl;
	if( lvl == 3 && curr == '1' && z == 1 ) 
		return "YES";
	return "NO";
}

int main() { 
	int t;
	cin >> t;
	for( int i = 0 ; i < t; i++ ) 
		cout << "Case #" << i+1 << ": " << calc() << endl;
}
