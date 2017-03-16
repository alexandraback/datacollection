
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

int sps(int n){
	return (n * (n + 1)) / 2;
}

void calc(){
	int N,M,K;
	cin >> N >> M >> K;
	if(N > M)swap(N,M);
	if(N <= 2){
		cout << K << endl;
		return;
	}
	int R = K;
	FOR(B,3,N+1){
		int PA = (B - 3) * 2;
		int fixed = B * 2 - 2;
		int remainingLen = M - B;
		int cov = B * B;
		vi AV(4, B/2);
		if(B%2==0){
			FOR(i,0,2)AV[i]--;
		}
		FOR(i,0,4)cov-= sps(AV[i]);
		int neededLen = (K - cov) / B;
		if(neededLen < remainingLen){
			R = min(R, fixed + neededLen * 2 + 2);
		}
		int len = min(neededLen, remainingLen);
		int used = len * 2 + fixed;
		cov += len * B;
		while(cov < K){
			int mid = 0;
			FOR(i,1,4)if(AV[i] > AV[mid])mid = i;
			++used;
			cov += AV[mid];
			if(AV[mid] > 1)--AV[mid];
		}
		R = min(R, used);

	}
	cout << R << endl;
}

int main() {
	int TC;
	cin >> TC;
	FOR(T,1,TC+1){
		cout << "Case #" << T << ": ";
		calc();
	}
	return 0;
}
