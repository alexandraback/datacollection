#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

LL sroot( LL x ) {
	LL r = sqrt((double)x );
	assert( r*r <= x );
	assert( (r+1)*(r+1) > x );
	//while( (r+1)*(r+1) <= x ) ++r;
	return r;
}

char buf[255];
int is_pd( LL x ) {
	int l = sprintf( buf, "%lld", x );
	int u = 0;
	int v = l-1;
	while( u < v ) {
		if( buf[u] != buf[v] ) return 0;
		++u;
		--v;
	}
	return 1;
}

vector<LL> res;

void prep() {
	res.clear();
	for( LL i = 1; i <= 10000000; ++i ) {
		if( is_pd(i) && is_pd(i*i) ) res.push_back(i*i);
	}
}

int main(int argc, char** argv) {
	prep();
	
	int cases;
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		LL a, b;
		cin >> a >> b;
		int cnt = 0;
		for( int i = 0; i < (int)res.size(); ++i ) {
			if( a <= res[i] && res[i] <= b ) ++cnt;
		}
		cout << cnt << endl;
	}
	return 0;
}


