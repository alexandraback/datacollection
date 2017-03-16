#include <utility>
#include <map>
#include <queue>
#include <cstdio>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		int N, M;
		scanf("%d%d", &N, &M);
		long long a[N], aSum[N+1];
		int A[N];
		map<long long, int> aTree;
		for(int n=0; n<N; ++n) {
			scanf("%lld%d", &a[n], &A[n]);
			aSum[n] = (n==0 ? 0 : aSum[n-1]) + a[n];
			aTree[aSum[n]-1] = n;
		}
		aTree[aSum[N-1]] = N;
		long long b[M], bSum[M+1];
		int B[M];
		map<long long, int> bTree;
		bTree[0] = 0;
		for(int m=0; m<M; ++m) {
			scanf("%lld%d", &b[m], &B[m]);
			bSum[m] = (m==0 ? 0 : bSum[m-1]) + b[m];
			bTree[bSum[m]-1] = m;
		}
		bTree[bSum[M-1]] = M;
		typedef pair<long long, long long> TyP;
		map<TyP, long long> mp;
		mp[TyP(0, 0)] = 0;
		int turn = 0;
		while(!mp.empty()) {
			++turn;
			map<TyP, long long>::iterator it = mp.begin();
			pair<TyP, long long> now = *it;
			mp.erase(it);

			int aIdx = aTree.lower_bound(now.first.first)->second;
			int bIdx = bTree.lower_bound(now.first.second)->second;
			if(aIdx==N && bIdx==M) {
				printf("Case #%d: %lld\n", t, now.second);
				break;
			}
			if(aIdx==N || bIdx==M) {
				long long sc = now.second;
				TyP p = TyP(aSum[N-1], bSum[M-1]);
				if(mp[p] <= sc) {
					mp[p] = sc;
				}
				continue;
			}
			if(A[aIdx]==B[bIdx]) {
				long long x = min(aSum[aIdx] - now.first.first, bSum[bIdx] - now.first.second);
				long long sc = now.second + x;
				TyP p = TyP(now.first.first + x, now.first.second + x);
				if(mp[p] <= sc) {
					mp[p] = sc;
				}
			}
			else {
				long long sc = now.second;
				TyP p1 = TyP(aSum[aIdx], now.first.second);
				TyP p2 = TyP(now.first.first, bSum[bIdx]);
				if(mp[p1] <= sc) {
					mp[p1] = sc;
				}
				if(mp[p2] <= sc) {
					mp[p2] = sc;
				}
			}
		}
	}
	return 0;
}
