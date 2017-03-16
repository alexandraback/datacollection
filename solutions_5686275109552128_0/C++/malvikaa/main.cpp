#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

int P[1010];
int N,mxp;

int main(){

	int T,t,i,k,cur,sol;


	scanf("%d",&T);

	for(t = 1; t <= T; ++t){
		scanf("%d",&N);

		mxp =0;
		for(i = 0; i < N; ++i){
			scanf("%d",&P[i]);
			mxp = max(mxp,P[i]);
		}

		sol = mxp;
		for(k = mxp; k > 0; --k){
			cur =0;
			for(i = 0; i < N; ++i){
				cur += ((P[i]+k-1)/k-1);
			}

			sol = min(sol,cur+k);
		}

		printf("Case #%d: %d\n",t,sol);
	}

	return 0;
}
