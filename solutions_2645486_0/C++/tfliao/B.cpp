#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll ;

#define MAXN 10001


int T, nCase = 1 ;
ll E, R, N, v[MAXN];


void input()
{
	cin >> E >> R >> N;
	for ( int i=0;i<N;++i ) cin >> v[i];
}

ll solv_r ( int l, int r, ll startE, ll endE )
{
	// requirement: endE - startE <= (r-l)*R
	if ( l >= r ) return 0;
	
	ll ans = 0;
	
	if ( r == l+1 ) {
		ans = min(startE, (startE-endE))*v[l];
		// cout << "( " << l << ", " << r << "): " << startE << "~" << endE  << ": " << ans << endl;
		return ans ;
	}
	
	
	int mx = l;
	for ( int i=l+1;i<r;++i ) if ( v[i] > v[mx] ) mx = i ;
	
	ll mxE = min ( E, (startE+R*(mx-l)) );
	ll mnE = max ( 0LL, (endE-(r-mx-1)*R) );
	
	ans += solv_r ( l, mx, startE, mxE-R);
	ans += solv_r ( mx, mx+1, mxE, mnE);
	ans += solv_r ( mx+1, r, mnE+R, endE) ;
	
	//cout << "( " << l << ", " << r << "): " << startE << "~" << endE  << ": " << ans << endl;
	
	return ans;
}

ll solv()
{
	return solv_r(0, N, E, 0);
}

int main()
{
	cin >> T;
	while ( T-- ) {
		input();
		cout << "Case #" << nCase ++ << ": " << solv() << endl;
	}
	return 0;
}