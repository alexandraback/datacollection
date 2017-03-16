#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
using namespace std;


int B,M;
int main() {
	int TC;
	scanf("%d",&TC);
	for(int tc =1; tc<=TC; tc++) {
		printf("Case #%d: ",tc);
		scanf("%d%d",&B,&M);
		long long way[51]={0};
		way[1] = way[2] = 1;
		for(int i=3; i<=B; i++) {
			for(int j=1; j<i; j++) 
				way[i] += way[j];
		}
		if(M > way[B]) printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			int adj[51][51]={0};
			char bin[64];
			int p=0;
			if(M == way[B]) {
				adj[1][B]=1;
				M--;
			}
			while(M) {
				bin[p++] = M%2;
				M/=2;
			}
			for(int i=B-1; i>1; i--) 
				for(int j=i+1; j<=B; j++) 
					adj[i][j] = 1;

			for(int i=0; i<p; i++) {
				if(bin[i])  {
					adj[1][B-i-1]=1;
				}
			}
			for(int i=1; i<=B; i++){
				for(int j=1; j<=B; j++) printf("%d",adj[i][j]);
				puts("");
			}
		}
	}
}
