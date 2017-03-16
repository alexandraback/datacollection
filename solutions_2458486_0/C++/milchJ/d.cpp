#include <cstdio>
#include <vector>
#include <string.h>

#define NMAX 20
#define KMAX 201

using namespace std;

int startkey[KMAX];
vector<int> openable[KMAX];
int keysinchest[NMAX][KMAX];
int nkeysinchest[NMAX];
int needkey[NMAX];


int keys[KMAX];
int steps[NMAX];


int T, K, N;

void printkeys() {
	for(int i=0; i<KMAX; i++) {
		printf("%d ", keys[i]);
	}
	printf("\n");
}

bool visited[1048576];
bool dp[1048576];

bool step(int bitstring, int num) {
	if(visited[bitstring]) {
		//printf("save!-----------------------------level %d\n", num);
		return dp[bitstring];
	}
		
	int n=0;
	int tmp=bitstring;
	bool alldone=true;
	for(int n=0; n<N; n++) {
		if(tmp%2 == 0) {
			//printf("need key: %d\n", needkey[n]);
			alldone=false;
			if(keys[needkey[n]]>0) {
				//printf("oeffne mal chest %d (bistring %d)\n", n, bitstring);
				for(int i=0; i<KMAX; i++) {
					keys[i] += keysinchest[n][i];	
				}			
				keys[needkey[n]]--;
				// mach den step
				steps[num] = n;
				if(step(bitstring + (1<<n), num+1)) {
					visited[bitstring] = true;
					dp[bitstring] = true;
					return true;
				}
				// mach das ganze rueckgaengig
				for(int i=0; i<KMAX; i++) {
					keys[i] -= keysinchest[n][i];	
				}			
				keys[needkey[n]]++;
			}
		}
		tmp /=2;
	}
	visited[bitstring] = true;
	dp[bitstring] = alldone;
	return alldone;
}

int main() {

	scanf("%d ", &T);
	for(int t=0; t<T; ++t) {
	
		for(int i=0; i<KMAX; i++) {
			startkey[i]=0;
			for(int j=0; j<NMAX; j++) {
				keysinchest[j][i]=0;
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(dp, 0, sizeof(dp));
			
		scanf("%d %d ", &K, &N);
		int k;
		for(int i=0; i<K; i++) {
			scanf("%d ", &k);
			startkey[k]++;
		}
		
		for(int i=0; i<N; ++i) {
			scanf("%d %d", &needkey[i], &nkeysinchest[i]);
			openable[needkey[i]].push_back(i);
			for(int j=0; j<nkeysinchest[i]; ++j) {
				scanf("%d ", &k);
				keysinchest[i][k]++;
			}
		}
		
		for(int i=0; i<KMAX; ++i) {
			keys[i]=startkey[i];
		}
		
		//printkeys();
		
		if(step(0,0)) {			
			printf("Case #%d:", t+1);
			for(int i=0; i<N; i++) {
				printf(" %d", steps[i]+1); 
			}
			printf("\n");
		} else {
			printf("Case #%d: IMPOSSIBLE\n", t+1);
		}
		
	}
	return 0;
}
