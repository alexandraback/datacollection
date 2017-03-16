#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> P;
int A[15], prod[15];
int R,N,M,K;
bool go(int x,int p) {
	if(x == N) {
		P.clear();
		for(int i=0;i<(1<<N);++i) {
			int v = 1;
			for(int j=0;j<N;++j)
				if(i&(1<<j)) v *= A[j];
			++P[v];
		}
		for(int i=0;i<K;++i)
			if(P.find(prod[i]) == P.end()) return 0;
		for(int i=0;i<N;++i)
			printf("%d",A[i]);
		printf("\n");
		return 1;
	}
	for(int i=p;i<=M;++i) {
		A[x] = i;
		if(go(x+1,i)) return 1;
	}
	return 0;
}
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		printf("Case #%d:\n",cn);
		scanf("%d%d%d%d",&R,&N,&M,&K);
		for(int rn=0;rn<R;++rn) {
			for(int i=0;i<K;++i) scanf("%d",&prod[i]);
			go(0,2);
		}
	}
}
