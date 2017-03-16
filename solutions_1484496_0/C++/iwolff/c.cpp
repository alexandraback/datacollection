#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 22

int ok[4000000];

int main() {
	int vet[MAXN],n,aux;
	int nt,nteste=1,lol;
	scanf("%d",&nt);
	while (nt--) {
		scanf("%d",&n);
		for (int i=0; i<n; i++)
			scanf("%d",&vet[i]);
		
		memset(ok,0,sizeof(ok));
		int N = 1<<n;
		int i;
		printf("Case #%d:\n",nteste++);
		for (i=1; i<N; i++) {
			aux = 0;
			for (int j=0; j<n; j++)
				if ((1<<j) & i) aux += vet[j];
			
			if (!ok[aux]) ok[aux] = i;
			else {
				lol = 0;
				for (int j=0; j<n; j++)
					if ((1<<j) & i) {
						if (lol) printf(" ");	lol = 1;
						printf("%d",vet[j]);
					}
				printf("\n");
				
				i = ok[aux];	lol = 0;
				for (int j=0; j<n; j++)
					if ((1<<j) & i) {
						if (lol) printf(" ");	lol = 1;
						printf("%d",vet[j]);
					}
				printf("\n");
				break;
			}
		}
		
		if (i == N) printf("Impossible\n");
		
	}
	
	return 0;
}