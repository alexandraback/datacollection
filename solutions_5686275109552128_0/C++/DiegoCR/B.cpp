#include <bits/stdc++.h>

using namespace std;

const int TAM = 1111;

int arr[TAM];
int n;

bool can ( int val, int spec ) {
	
	for ( int i = 0; i < n; i ++ ) {
		if ( arr[i] > val ) {
			spec -= (arr[i] - 1) / val;
			if ( spec < 0 ) return false;
		}
	}
	
	return true;
}

bool possible ( int mid ) {
	
	for ( int i = 0; i < mid; i ++ )
		if ( can ( mid - i, i ) )
			return true;
	
	return false;	
}

int main() {

	freopen ( "B.in", "r", stdin );
	freopen ( "SalidaB.txt", "w", stdout );

	int ntc;
	int tc, i;
	int L, R, mid;
	
	cin >> ntc;
	
	for ( tc = 1; tc <= ntc; tc ++ ) {
		cin >> n;
		
		for ( i = 0; i < n; i ++ ) cin >> arr[i];
		
		L = 0; R = 1000;
		
		while ( L <= R ) {
			mid = ( L + R ) / 2;
			if ( possible ( mid ) ) R = mid - 1;
			else L = mid + 1;
		}
		
		cout << "Case #" << tc << ": " << R + 1 << '\n';
	}
	
	return 0;
}
