#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll solve(ll E, ll R, int N, ll v[10001]) {
	int order[10001]; for(int i = 0; i < N; i++) order[i] = i;
	sort(order, order + N, [&](int i, int j) { return v[i] > v[j]; });
	ll me[10001] = {};
	for(int i = 0; i < N; i++) {
		int k = order[i];
		int j = k - 1;
		ll m = E - R;
		while(j >= 0 && v[j] < v[k] && m > 0) {
			me[j] = m;
			--j;
			m -= R;
		}
	}
	ll T = 0;
	ll curE = E;
	for(int i = 0; i < N; i++) {
		if(curE > me[i]) {
			T += v[i]*(curE - me[i]);
			curE = me[i];
		}
		curE += R;
	}
	return T;
}

int main() {
	int ncases;
	cin >> ncases;
	ll v[10001];
	for(int casen=1; casen<=ncases;casen++) {
		ll E, R, N;
		cin >> E >> R >> N;
		for(int i = 0; i < N; i++) cin >> v[i];
		cout << "Case #" << casen << ": " << solve(E, R, N, v) << endl;		
	}
}
