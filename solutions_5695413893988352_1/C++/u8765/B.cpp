#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

LL ppow10[20];
string C, J;
LL maxv[2][20];
LL minv[2][20];
int n;
string maxs[2][20];
string mins[2][20];
const LL INF = numeric_limits<LL>::max();

int dec[20];

/*
void decide( LL& current, LL newone, int k, int  ) {
	if( newone < current ) {
		current = newone;
		decision
	}
}
*/

struct result_t {
	LL val;
	string C, J;
};

void better( result_t& current, result_t other ) {
	if( llabs(other.val) < llabs(current.val) ) { 
		current = other;
	} else if( llabs(other.val) == llabs(current.val) ) {
		if( other.C < current.C || (other.C == current.C && other.J < current.J )) {
			current = other;
		}
	}
}

result_t rec( int k, string rC, string rJ ) {
	if( k == n ) return { 0, rC, rJ };
	
	if( C[k] == J[k] && C[k] != '?' ) {
		return rec( k+1, rC+C[k], rJ+J[k] );
	}
	
	result_t res = { INF, "", "" };
	
	if( C[k] == J[k] ) {
		// ?-?
		
		// equal: 0-0
		better( res, rec( k+1, rC + '0', rJ + '0' ) );

		// C<J : 0-1
		better( res, { ppow10[n-1-k] + minv[1][k+1] - maxv[0][k+1], rC + '0' + maxs[0][k+1], rJ + '1' + mins[1][k+1] } );
				
		// C>J : 1-0
		better( res, { ppow10[n-1-k] + minv[0][k+1] - maxv[1][k+1], rC + '1' + mins[0][k+1], rJ + '0' + maxs[1][k+1] } ); 
	} else if( C[k] == '?' ) {
		// ?-x
		// J[k] != '?'

		// C<J
		if( J[k] != '0' ) {
			better( res, { ppow10[n-1-k] + minv[1][k+1] - maxv[0][k+1], rC + (char)(J[k]-1) + maxs[0][k+1], rJ + J[k] + mins[1][k+1] } ); 
		}
		
		// equal
		better( res, rec( k+1, rC + J[k], rJ + J[k] ) );
		
		// C>J
		if( J[k] != '9' ) {
			better( res, { 
					ppow10[n-1-k] + minv[0][k+1] - maxv[1][k+1], 
					rC + (char)(J[k]+1) + mins[0][k+1], 
					rJ + J[k] + maxs[1][k+1] } );
		}
		
		
	} else if( J[k] == '?' ) {
		// x-?
		
		// equal
		better( res, rec( k+1, rC + C[k], rJ + C[k] ) );
		
		// C>J
		if( C[k] != '0' ) {
			better( res, { 
					ppow10[n-1-k] + minv[0][k+1] - maxv[1][k+1], 
					rC + C[k] + mins[0][k+1], 
					rJ + (char)(C[k]-1) + maxs[1][k+1] } );
		}
		
		// C<J		
		if( C[k] != '9' ) {
			better( res, { ppow10[n-1-k] + minv[1][k+1] - maxv[0][k+1], rC + C[k] + maxs[0][k+1], rJ + (char)(C[k]+1) + mins[1][k+1] } ); 
		}
	} else {
		// x-y
		if( C[k] > J[k] ) {
			better( res, { (LL)(C[k]-J[k]) * ppow10[n-1-k] + minv[0][k+1] - maxv[1][k+1], rC + C[k] + mins[0][k+1], rJ + J[k] + maxs[1][k+1] } );
		} else {
			assert( C[k] < J[k] );
			
			better( res, { (LL)(J[k]-C[k]) * ppow10[n-1-k] + minv[1][k+1] - maxv[0][k+1], rC + C[k] + maxs[0][k+1], rJ + J[k] + mins[1][k+1] } );
		}
	}
	
	assert( res.val != INF );
	return res;
}

int main() {
	int cases;
	
	ppow10[0] = 1;
	for( int i = 1; i < 19; ++i ) {
		ppow10[i] = ppow10[i-1]*10;
	}
	
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		cin >> C >> J;
		
		n = C.size();
		assert( J.size() == C.size() );

		string s[2] = { C, J };
		for( int i = 0; i < 2; ++i ) {
			maxv[i][n] = 0;
			for( int j = n-1; j >= 0; --j ) {
				int d = s[i][j] == '?' ? 9 : s[i][j]-'0';
				maxv[i][j] = d * ppow10[n-1-j] + maxv[i][j+1];
			}
			
			minv[i][n] = 0;
			for( int j = n-1; j >= 0; --j ) {
				int d = s[i][j] == '?' ? 0 : s[i][j]-'0';
				minv[i][j] = d * ppow10[n-1-j] + minv[i][j+1];
			}
			
			maxs[i][n] = "";
			for( int j = n-1; j >= 0; --j ) {
				if( s[i][j] == '?' ) {
					maxs[i][j] = string("9") + maxs[i][j+1];
				} else maxs[i][j] = string("") + s[i][j] + maxs[i][j+1]; 
			}

			mins[i][n] = "";
			for( int j = n-1; j >= 0; --j ) {
				if( s[i][j] == '?' ) {
					mins[i][j] = string("0") + mins[i][j+1];
				} else mins[i][j] = string("") + s[i][j] + mins[i][j+1]; 
			}
		}
		
		auto res = rec( 0, "", "" );
		cout << res.C << ' ' << res.J << endl;
	}
	return 0;	
}
