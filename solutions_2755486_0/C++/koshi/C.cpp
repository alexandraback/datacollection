#include <iostream>
#include <queue>
#include <functional>

#define ll long long int

using namespace std;

class Attack {
public:
	ll day;
	ll w, e;
	ll s;

	Attack(ll tday, ll tw, ll te, ll ts) : day(tday), w(tw), e(te), s(ts) {};

	bool operator>(const Attack &a) const {
		return day > a.day;
	}
};

int wall[4000002];
int subwall[4000002];

int main()
{
	int TN;
	cin >> TN;
	for (int tc = 0; tc < TN; tc++)
	{
		ll ans = 0;
		ll N;
		priority_queue<Attack, vector<Attack>, greater<Attack> > queue;

		memset(wall, 0, sizeof(wall));
		memset(subwall, 0, sizeof(subwall));

		cin >> N;
		for( int i=0; i<N; i++ ) {
			ll d, n, w, e, s, dd, dp, ds;
			cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
			for( int k=0; k<n; k++ ) {
				queue.push( Attack(d, w, e, s) );
				d += dd;
				w += dp;
				e += dp;
				s += ds;
			}
		}

		int attackday = -1;
		while( !queue.empty() ) {
			Attack at = queue.top();
			queue.pop();

			if( attackday != at.day ) {
				attackday = at.day;
				memcpy(wall, subwall, sizeof(wall));
			}

			//cout << at.day << ": " << "[" << at.w << ", " << at.e << "] " << at.s << endl;

			bool flag = false;
			for( int p=at.w*2; p<=at.e*2; p++ ) {
				if( wall[p+2000000] < at.s ) {
					if( subwall[p+2000000] < at.s ) {
						subwall[p+2000000] = at.s;
					}
					flag = true;
				}
			}
			if( flag ) {
				//cout << "suc" << endl;
				ans ++;
			}
		}

		cout << "Case #" << tc+1 << ": " << ans << endl;
	}
	return 0;
}