#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int T;

int main(){

	scanf("%d",&T);
	int t;
	int N,M,W;

	for(t = 1; t <= T; ++t){
		scanf("%d%d%d",&M,&N,&W);

		int sol = (N/W)*M - 1 + W;
		if(N%W) ++sol;

		printf("Case #%d: %d\n",t,sol);
	}

	return 0;
}
