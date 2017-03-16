#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
long long T, D[MAXN], N, H[MAXN], M[MAXN];

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	cin >> T;
	for(int t=1; t<=T; ++t){
		cin >> N;
		for(int i=0; i<N; ++i) cin >> D[i] >> H[i] >> M[i];
		long long best = INT_MAX;
		for(int i=0; i<N; ++i) for(int j=0; j<H[i]; ++j){
			long long pass = 0;
			long long time = (360 - D[i]) * (M[i] + j);
			for(int k=0; k<N; ++k) for(int l=0; l<H[k]; ++l){
				long long speed_inv = M[k] + l;
				long long dist = D[k] + time / speed_inv;
				long long turns = dist / 360;
				pass += abs(1 - turns);
			}
			best = min(best, pass);
		}
		cout << "Case #" << t << ": " << best << '\n';
	}
}
