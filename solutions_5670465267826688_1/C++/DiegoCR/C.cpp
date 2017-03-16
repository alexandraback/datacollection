#include <bits/stdc++.h>

using namespace std; 

typedef long long ll;

int mat[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1},
};

int pot[5];

int operate ( int a, int b ) {
	int sign = a * b;	
	a = mat[abs(a)][abs(b)];
	if ( sign < 0 ) return -a;
	return a;
}

int main() {
	
	freopen ( "C.in", "r", stdin );
	freopen ( "SalidaC.txt", "w", stdout );
	
	int ntc;
	ll N, X;
	string cad;
	
	 cin >> ntc;
	 
	 
	 for ( int tc = 1; tc <= ntc; tc ++ ) {
	 	
	 	cin >> N >> X;
	 	cin >> cad;
	 	
	 	cout << "Case #" << tc << ": ";	 	
	 	
	 	int curr = 1;
	 	
	 	for ( int i = 0; i < N; i ++ ) curr = operate ( curr, cad[i] - 'g' );
	 	
	 	pot[0] = 1;
	 	
	 	for ( int i = 1; i < 4; i ++ ) pot[i] = operate ( pot[i - 1], curr );
	 	
	 	if ( pot[X % 4] != -1 ) {
	 		cout << "NO\n";
	 		continue;
	 	}
	 	
	 	int poti = -1, potij = -1;
	 	
	 	for ( int i = 0; i < 8; i ++ ) {
	 		curr = pot[i % 4];
	 		
	 		for ( int j = 0; j < N; j ++ ) {
	 			curr = operate ( curr, cad[j] - 'g' );
	 			if ( curr == 2 && poti == -1 )
	 				poti = i;
	 			if ( curr == 4 && poti != -1 && potij == -1 )
				 	potij = i;
	 		}
	 	}
	 	
	 	if ( poti != -1 && potij != -1 ) {
	 		if ( poti < X && potij < X ) {
	 			cout << "YES\n";
	 			continue;
	 		}
	 	}
	 	
	 	cout << "NO\n";
	 }
	
	return 0;	
}
