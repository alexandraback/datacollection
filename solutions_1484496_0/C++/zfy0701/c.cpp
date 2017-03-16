#include <iostream>
using namespace std;

int n;
int num[1000];

int state[1<<20];
int ht[2000100];

void printstate(int s) {
	bool first = true;
	for (int i = 0; i < n; i++) {
		if ((s & (1<<i)) > 0) {
			if (first) first = false;
			else {
				printf(" ");
			}

			printf("%d", num[i]);
		}
	}
}

int main() {
	int t;




	scanf("%d", &t);
	for (int k = 0; k < t; k++) {

		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", &num[i]);

	//printstate(1);printf("\n");
	//printstate(2);printf("\n");

		memset(state, 0, sizeof(state));
		memset(ht, 0, sizeof(ht));

//		state[1] = num[0];

		for (int s = 0; s < (1 << n); s++) {
			//printf("(%d %d)", state[s], ht[state[s]]);
			ht[state[s]]++;
			
			for (int i = 0; i < n; i++) {

				if (s & (1 << i)) continue;

				int s2 = s | (1 << i);

				state[s2] = state[s] + num[i];
				//printf("%d %d\n", state[s], num[i]);
			}
		}

		//for (int i = 0; i < 100; i++)
		//	printf("%d ", hash[i]);

		for (int s = 1; s < (1 << n); s++) {
			if (ht[state[s]] > 1) {
			//	printf("%d %d\n", state[s], ht[state[s]]);
				int s2 = s+1;
				for (s2 = s+ 1; s2 < (1<<n); s2++) {
					if (state[s] == state[s2]) {
				//		printf("s: %d %d %d\n", s, s2, state[s]);
						break;
					}

				}

				printf("Case #%d:\n", k+1);
				printstate(s); printf("\n");
				printstate(s2);printf("\n");
				break;
			}
		}

		//if (k<t-1) printf("\n");	
	}
	return 0;
}