#include <bits/stdc++.h>

using namespace std;

string k, l;

int freq[555];
int K, L, S;

bool can ( int p ) {
	for ( int i = 0; i < L - p; i ++ )
		if ( l[i] != l[i + p] )
			return false;
			
	return true;
}

int main() {

	freopen ( "B.in", "r", stdin );
	freopen ( "SalidaB2.txt", "w", stdout );
	
	int ntc;
	
	cin >> ntc;
	
	for ( int tc = 1; tc <= ntc; tc ++ ) {
		
		cin >> K >> L >> S;
		cin >> k >> l;
		
		bool possible = true;
		double ans = 0.0;
		int diff = 0;
		
		for ( int i = 'A'; i <= 'Z'; i ++ ) freq[i] = 0;
		
		for ( int i = 0; i < K; i ++ )
			freq[k[i]] ++;
		
		for ( int i = 0; i < L; i ++ ) 
			if ( freq[l[i]] == 0 )
				possible = false;
				
		if ( !possible ) {
			printf ( "Case #%d: %.10lf\n", tc, ans );
			continue;
		}
		
		int pref = L;
		for ( int i = 1; i < L && pref == L; i ++ )
			if ( can(i) )
				pref = i;
		
		// cout << "Prefijo " << pref << endl;
		
		int mx = 1, curr = L;
		while ( curr + pref <= S ) {
			mx ++;
			curr += pref;
		}
		
		double frac = 1.0;
		
		for ( int i = 0; i < L; i ++ )
			frac *= double(freq[l[i]]) / double(K);
		
		// cout << "Max " << mx << " " << freq << endl;
		
		ans = double(mx) - ( double(S - L + 1) * frac );
		
		printf ( "Case #%d: %.10lf\n", tc, ans );
	}
	
	
	return 0;
}
