#include <bits/stdc++.h>

using namespace std;
long long k, c, s;
long long found;
long long path( long long n ) {
    long long complex= c;
    long long check = n;
    long long cnt = n;
    complex--;
    found++;
    while( complex ) {
	complex--;
	if( n != k ){
	    n++;
	    found++;
	}   
	check = ( check - 1 ) * k + n;
    }
    return check;
}
	
void solve( ){
    long long tries = 0;
    vector< long long > sol;
    while( found != k ){
	long long out = path( found+1 );
	sol.push_back( out );
	tries++;
    }
    if( tries > s ){
	cout << " IMPOSSIBLE" << endl;
    }
    else {
	for( int i = 0; i < sol.size(); i++ )
	    cout << " " << sol[i];
	cout << endl;
    }
    return;
}
 
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++ ){
	found = 0;
	cin >> k >> c >> s;
	cout << "Case #" << i << ":";
	solve();
	
    }
    return 0;
}
	
