#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main(){
	int times, n;
	scanf("%d", &times);
	for (int t=1; t<=times; t++){
		int J, P, S, K, M;
		scanf("%d %d %d %d", &J, &P, &S, &K);
		M = min(S, K);
		printf("Case #%d: %d\n", t, J * P * M);
		for (int i=0; i<J; i++)
			for (int j=0; j<P; j++)
				for (int k=0; k<M; k++){
					printf("%d %d %d\n", i+1, j+1, (i+j+k)%S+1);
				}
	}
	return 0;
}
