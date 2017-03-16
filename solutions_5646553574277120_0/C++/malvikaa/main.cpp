#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;


int seen[32];

int A[7];

int main(){

	int T,t,C,D,V;

	scanf("%d",&T);


	int sel;
	int i;
	for(t = 1; t <= T; ++t){

		scanf("%d%d%d",&C,&D,&V);

		memset(seen,0,sizeof(seen));
		for(i = 0; i < D; ++i) scanf("%d",&A[i]);

		for(sel = 0; sel < (1<<D); ++sel){
			int sum = 0;
			for(i= 0; i < D; ++i){
				if(sel&(1<<i)) sum += A[i];
			}
			seen[sum] = 1;
		}


		int sol = 0;
		for(i = 0; i <= V; ++i) sol += (!seen[i]);
		printf("Case #%d: %d\n",t,sol);
	}



	return 0;
}
