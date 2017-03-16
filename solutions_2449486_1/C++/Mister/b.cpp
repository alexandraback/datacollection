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
using namespace std;
int A[105][105];
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		int N,M;
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				scanf("%d",&A[i][j]);
		bool ans = 1;
		for(int y=0;y<N;++y)
			for(int x=0;x<M;++x) {
				bool fail = 0;
				for(int i=0;i<N;++i)
					if(A[i][x] > A[y][x]) fail = 1;
				if(fail) {
					fail = 0;
					for(int i=0;i<M;++i)
						if(A[y][i] > A[y][x]) fail = 1;
				}
				if(fail) {
					ans = 0;
					goto end;
				}
			}
		end:;
		if(!ans) printf("Case #%d: NO\n",cn);
		else printf("Case #%d: YES\n",cn);
	}
}
