#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;

int const MAXN = 2000000;

int x,y;
int n;

int d,diff;

int internal (int d) {
	// numero di diamanti nel triangolo interno rispetto alla posizione d
	
	return d*(2*d-1);
}

long double fact[MAXN];
//double pow[MAXN];

long double factorial (int m) {
	if ( fact[m] < 0.5 ) {
		fact[m] = factorial(m-1) * m;
	}
	
	return fact[m];
}
/*
double ppower (int m) {
	if ( pow[m] < 0.5 ) {
		pow[m] = ppower(m-1) * 2;
	}
	
	return pow[m];
}
*/
long double binomial (int a, int b) {
	assert ( ( a >= 0 ) && ( b >= 0 ) );
	
	if ( a < b ) return 0.0;
	return ( factorial(a) / ( factorial(b) * factorial(a-b) ) );
}


long double probability (int a, int b) {
	
	//printf("Chiamo probability(%d,%d)\n",a,b);
	//printf("d=%d\n",d);

	if ( (a < 2*d) && (b < 2*d) ) {
		return ( binomial(diff,a) / pow(2,diff) );
	}
	
	if ( a < b ) return probability(b,a);
	
	if ( ( a == b ) && ( a == 2*d ) ) return 1.0;
	
	assert( a != b );
	assert( a == 2*d );
	
	// caso a = 2d
	
	long double sum = 0.0;
	for (int i=2*d; i<=diff; ++i) {
		long double p = binomial(i-1,2*d-1)/pow(2,i);
		if ( !isnan(p) ) sum += p;
	}
	
	return sum;
}

long double solve() {
	scanf("%d %d %d",&n,&x,&y);
	
	if ( x < 0 ) x = -x;
	
	d = (x+y)/2; // posizione
	
	int k = internal(d);
	int ksucc = internal(d+1);
	
	if ( n <= k ) return 0.0;
	if ( n >= ksucc ) return 1.0;
	
	diff = n - k;
	
	if ( y == 2*d ) {
		// caso del vertice: non ci sono abbastanza diamanti (viene preso per ultimo)
		return 0.0;
	}
	
	long double sum = 0.0;
	for (int b = max(y+1,diff-2*d); b <= min(2*d,diff); ++b) {
		int a = diff - b;
		long double p = probability(a,b);
		if ( !isnan(p) ) sum += p;
	}
	
	return sum;
}

int main() {
	
	int t;
	scanf("%d",&t);
	
	fact[0] = 1.0;
	//pow[0] = 1.0;
	
	for (int i=0; i<t; ++i) {
		printf("Case #%d: %llf\n",i+1, solve());
	}
	
	return 0;
}
