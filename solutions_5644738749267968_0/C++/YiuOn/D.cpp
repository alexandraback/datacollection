#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D out.txt", "w", stdout);

	int T,count,N;
	double* naomi;
	double* ken;
	
	scanf("%d", &T);
	
	count = 1;
	while(T--){
		scanf("%d", &N);

		naomi = new double[N];
		ken = new double[N];

		for(int i=0; i<N; i++){
			scanf("%lf", &naomi[i]);
		}
		for(int i=0; i<N; i++){
			scanf("%lf", &ken[i]);
		}

		sort(naomi, naomi+N);
		sort(ken, ken+N);

		int y=0;
		int z=0;

		int p=0;
		int q=0;
		while(q<N && p<N){
			if(naomi[q++] > ken[p]){
				y++;
				p++;
			}
		}

		p=0;
		q=0;
		while(q<N && p<N){
			if(ken[q++] > naomi[p]){
				z++;
				p++;
			}
		}
		z = N-z;

		printf("Case #%d: %d %d\n", count++, y, z);
		delete [] naomi;
		delete [] ken;
	}
	

	return 0;
}