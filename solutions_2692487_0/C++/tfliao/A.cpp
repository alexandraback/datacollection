#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL ;

int T, nCase = 1;

LL A ;
int N;
LL mote[101] ;


int solv()
{	
	if ( A == 1 ) return N ;
	int ans = N ;
	int cnt = 0;
	sort(mote, mote+N);
	
	for ( int i=0;i<N;++i ) {
		if ( A > mote[i] ) A += mote[i];
		else {
			ans = min(ans, cnt+N-i);
			while ( A <= mote[i] ) {
				++cnt ;
				A += A-1;
			}
			A += mote[i];
		}
		if ( cnt >= ans ) break;
	}
	ans = min ( ans, cnt);
	return ans;
}

int main()
{
	cin >> T;
	while ( T-- ) {
		cin >> A >> N;
		for ( int i=0;i<N;++i ) cin >> mote[i] ;
		cout << "Case #" << nCase++ << ": " << solv() << endl;
	}
	return 0;
}