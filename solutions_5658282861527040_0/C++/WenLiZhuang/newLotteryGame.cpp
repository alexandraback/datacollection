#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


typedef unsigned long long int ui;
ui A, B, K;
ui clearAfter( ui t ){
	ui k = 1;

	while( t & ~k ) {
		t &= ~k;
		k <<= 1;
	}

	return t;
}

ui solveBig(){
	if ( A <= K ){
		return A * B;
	}

	//A > K:

	ui tot = K * B;

	if( B < K ) return tot + (A-K) * B;

	// B > K:
	
	tot += (A-K) * K;

	

	
	return tot;
}



ui solve(){
	if ( A <= K ){
		return A * B;
	}

	A > K;

	ui tot = K * B;
	
	for( ui a = K; a<A; a++ ){
		for( ui b=0; b < B; b++ ){
			if ( (a & b) < K ) tot++;
		}
	}

	return tot;
}

int main(){
	int testCase;
	cin >> testCase;
	for( int cas=1; cas <= testCase; cas++){
		
		cin >> A >> B >> K;


		cout << "Case #" << cas << ": " << solve() << "\n";
	}
}
