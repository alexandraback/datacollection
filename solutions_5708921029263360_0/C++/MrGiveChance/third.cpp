#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;


int sh[1500];
int ja[1500];
int pa[1500];

int main() {
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);

	int T,cases,N,J,P,S,K;
	
	scanf("%d", &T);

	for (cases=1;cases<=T;cases++){
		scanf("%d %d %d %d", &J, &P, &S, &K);
		
		if (K > S) K = S;

		int c = 0;
		int nextk = 0;
		for (int i=0;i<J;i++) {
			for (int j=0;j<P;j++) {
				for (int k=0;k<K;k++) {

					ja[c] = i;
					pa[c] = j;
					sh[c] = nextk;
					nextk = (nextk+1)%S;
					c++;
				}
			}
		}
		int valid = c;
		
		for (int i=0;i<J;i++){
			for (int j=0;j<S;j++) {
				int dup = 0;
				for (int k=0;k<c;k++){
					if (ja[k]==-1) continue;

					if (ja[k]==i && sh[k]==j) {
						dup ++;
						if (dup > K) {
							ja[k] = -1;
							valid --;
						}
					}
				}
			}
		}


		for (int i=0;i<P;i++){
			for (int j=0;j<S;j++) {
				int dup = 0;
				for (int k=0;k<c;k++){
					if (ja[k]==-1) continue;

					if (pa[k]==i && sh[k]==j) {
						dup ++;
						if (dup > K) {
							ja[k] = -1;
							valid --;
						}
					}
				}
			}
		}
		printf( "Case #%d: %d\n",cases, valid);
		for (int i=0;i<c;i++){
			if (ja[i] == -1) continue;
			printf("%d %d %d\n", ja[i]+1, pa[i]+1, sh[i]+1);
		}



	}
}
