#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define ll long long int

using namespace std;


int main()
{
	int TN;
	cin >> TN;
	for (int i = 0; i < TN; ++i)
	{
		ll A, N;
		priority_queue<ll, vector<ll>, greater<ll> > motes;
		cin >> A >> N;
		for( int j=0; j<N; j++ ) 
		{
			int k;
			cin >> k;
			motes.push(k);
		}
		if( A <= 1 ) {
			cout << "Case #" << i+1 << ": " << motes.size() << endl;
			continue;
		}

		ll m = A;
		ll ans = 1000, add = 0;
		while( !motes.empty() )
		{
			ll mote = motes.top();
			motes.pop();	

			if( m > mote ) {
				m += mote;
			} else {
				ans = min( ans, add+(ll)motes.size()+1 );
				ll a = (ll)floor( log2((double)mote/(double)m) )+1;
				m = pow(2,(double)a)*m - (pow(2,(double)a)-1);
				while( m <= mote ) {
					m = m*2-1;
					a += 1;
				}
				m += mote;
				add += a;
			}
		}

		cout << "Case #" << i+1 << ": " << min(add, ans) << endl;
	}
	return 0;
}