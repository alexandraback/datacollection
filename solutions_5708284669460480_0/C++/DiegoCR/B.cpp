#include <bits/stdc++.h>

using namespace std;

string k, l;

vector < string > pals;
string curr;
int K, L, S;

void generate ( int pos ) {
	if ( pos == S ) {
		pals.push_back ( curr );
		return;
	}
	for ( int i = 0; i < K; i ++ ) {
		curr[pos] = k[i];
		generate ( pos + 1 );
	}	
}

int search ( int p ) {
	int na = 0;
	for ( int i = 0; i <= S - L; i ++ ) {
		bool ok = true;
		for ( int j = 0; j < L && ok; j ++ )
			if ( pals[p][i + j] != l[j] )
				ok = false;
		if ( ok ) na ++;
	}
	return na;
}

int main() {

	freopen ( "B.in", "r", stdin );
	freopen ( "SalidaB.txt", "w", stdout );
	
	int ntc;
	
	cin >> ntc;
	
	for ( int tc = 1; tc <= ntc; tc ++ ) {
		
		cin >> K >> L >> S;
		cin >> k >> l;
		
		curr = "";
		for ( int i = 0; i < S; i ++ ) curr += "A";
		pals.clear();
		
		generate ( 0 );
		
		double ans = 0.0, np;
		double tp = 0.0;
		
		for ( int i = 0; i < pals.size(); i ++ ) {
			// cout << pals[i] << endl;
			np = search ( i );
			ans = max ( ans, np );
			tp += np;
		}
		
		// cout << ans << endl;
		
		ans -= ( tp / double(pals.size()) );
		
		printf ( "Case #%d: %.10lf\n", tc, ans );
	}
	
	
	return 0;
}
