#include <cstdio>

#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
	int T;
	int E, R, N;
	int v[100];
	scanf("%d\n",&T);
	
	for(int cases=0; cases<T; cases++){
		scanf("%d %d %d\n", &E, &R, &N);
		for(int i=0; i<N; i++){
			int aa;
			scanf("%d\n",&v[i]);
		}
		//printf("%d\n",v[0]);
		sort(v, v+N);
		//printf("%d\n",v[0]);
		int total = 0;
		for(int i=0; i<N-1; i++){
			total+=R*v[i];
		}
		total+=E*v[N-1];
		printf("Case #%d: %d\n", cases+1, total);
	}
	
}

