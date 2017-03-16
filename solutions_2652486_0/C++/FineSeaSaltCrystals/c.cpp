#include <iostream>
#include <cassert>
typedef long long ll;
using namespace std;

int main() {
	ll T; cin >> T;
	ll R, N, M, K;
	cin >> R >> N >> M >> K;
	cout << "Case #1:\n";
	for(ll r = 0; r < R; ++r) {
		ll P[126] = {};
		for(ll k = 0; k < K; k++) {
			ll p;
			cin >> p;
			++P[p];
		}
		ll c[3];
		ll cbest[3] = {};
		ll best = 0;
		if(N == 3) {
			for(c[0] = 2; c[0] <= M; c[0]++) for(c[1] = 2; c[1] <= M; c[1]++) for(c[2] = 2; c[2] <= M; c[2]++) {
				ll Q[126] = {};
				for(ll subset = 0; subset < 8; subset++) {
					ll x = 1;
					if(subset & 4) x *= c[0];
					if(subset & 2) x *= c[1];
					if(subset & 1) x *= c[2];
					++Q[x];
				}
				ll score = 1;
				for(ll i = 1; i < 126; i++)
					for(ll k = 0; k < P[i]; k++)
						score *= Q[i];
				if(score > best) {
					best = score;
					cbest[0] = c[0]; cbest[1] = c[1]; cbest[2] = c[2];
				}
			}
			cout << cbest[0] << cbest[1] << cbest[2] << endl;
		}
		else if(N == 2) {
			for(c[0] = 2; c[0] <= M; c[0]++) for(c[1] = 2; c[1] <= M; c[1]++) {
				ll Q[126] = {};
				for(ll subset = 0; subset < 4; subset++) {
					ll x = 1;
					if(subset & 2) x *= c[0];
					if(subset & 1) x *= c[1];
					++Q[x];
				}
				ll score = 1;
				for(ll i = 1; i < 126; i++)
					for(ll k = 0; k < P[i]; k++) {
						score *= Q[i];
					}
				if(score > best) {
					best = score;
					cbest[0] = c[0]; cbest[1] = c[1]; 
				}
			}
			cout << cbest[0] << cbest[1] << endl;		
		}
		else if(N == 1) {
			for(c[0] = 2; c[0] <= M; c[0]++) {
				ll Q[126] = {};
				for(ll subset = 0; subset < 2; subset++) {
					ll x = 1;
					if(subset & 1) x *= c[0];
					++Q[x];
				}
				ll score = 1;
				for(ll i = 1; i < 126; i++)
					for(ll k = 0; k < P[i]; k++)
						score *= Q[i];
				if(score > best) {
					best = score;
					cbest[0] = c[0]; 
				}
			}
			cout << cbest[0] << endl;		
		}
		else assert(0);
	}
}

