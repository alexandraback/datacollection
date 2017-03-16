#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define rtrav(it, v) for(typeof((v).rbegin()) it = (v).rbegin(); it != (v).rend(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

long long mem[2][2][2][100];
bool mems[2][2][2][100];
const int ONES = ~0;

long long sol(int A, int B, int K, int i) {
	int ca = A==ONES, cb = B==ONES, ck = K==ONES;
	bool ia = A&(1<<i), ib = B&(1<<i), ik = K&(1<<i);

// i < 0?
	if (i<0) return 1;

	if(!mems[ca][cb][ck][i]) {
		if (ik) {
			if(ia && ib)
				mem[ca][cb][ck][i] = sol(A,B,K,i-1)+sol(A,ONES,ONES,i-1)+sol(ONES,B,ONES,i-1)+sol(ONES,ONES,ONES,i-1);
			else if(ia)
				mem[ca][cb][ck][i] = sol(ONES,B,ONES,i-1)+sol(A,B,ONES,i-1);
			else if(ib)
				mem[ca][cb][ck][i] = sol(A,ONES,ONES,i-1)+sol(A,B,ONES,i-1);
			else
				mem[ca][cb][ck][i] = sol(A,B,ONES,i-1);
		} else {
			if(ia && ib)
				mem[ca][cb][ck][i] = sol(A,ONES,K,i-1)+sol(ONES,B,K,i-1)+sol(ONES,ONES,K,i-1);
			else if(ia)
				mem[ca][cb][ck][i] = sol(ONES,B,K,i-1)+sol(A,B,K,i-1);
			else if(ib)
				mem[ca][cb][ck][i] = sol(A,ONES,K,i-1)+sol(A,B,K,i-1);
			else
				mem[ca][cb][ck][i] = sol(A,B,K,i-1);
		}
		mems[ca][cb][ck][i] = true;
	}
	return mem[ca][cb][ck][i];
}

int main(int argc, char const *argv[]) {
	unsigned int T, A, B, K;
	scanf("%u", &T);
	rep(t,0,T) {
		scanf("%u%u%u",&A,&B,&K);
		--A;--B;--K;
		memset(mems, false, sizeof(mems));
		long long ans = sol(A,B,K,30);
		printf("Case #%d: %lld\n",t+1,ans);
	}
	return 0;
}