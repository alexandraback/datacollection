#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int max_keys;
struct chest {
	bool opened;
	int reqKey;
	int keyCount;
	int keys[401];
};

bool dep[200][200];
bool solve(int index, int* keys, int N, struct chest* chests, int* answer) {
	if (index == N)
		return true;
		
	int tmpkeys[401];
	for(int i=0; i<=max_keys; i++) tmpkeys[i] = keys[i];
	for(int i=0; i<N; i++) {
		if (chests[i].opened)
			continue;
		tmpkeys[chests[i].reqKey]--;
		for(int j=0; j<chests[i].keyCount; j++)
			tmpkeys[chests[i].keys[j]]++;	
	}
	for(int i=0; i<=max_keys; i++) 
		if(tmpkeys[i] < 0) //Not enough keys
			return false;

	//(Circular/self)-dependency is impossible
	for(int i=0; i<N; i++) {
		if (chests[i].opened)
			continue;
		if (keys[chests[i].reqKey] == 0) {
			int depend = -1;
			for(int j=0; j<N; j++) {
				dep[i][j] = false;
				if (chests[i].opened)
					continue;
				for(int k=0; k<chests[j].keyCount; k++)
					if (chests[j].keys[k] == chests[i].reqKey) {
						if (depend == -1) {
							depend = j;
						} else {
							depend = -2;
						}
						break;
					}
			}
			if (depend >= 0) {
				dep[i][depend] = true;
				if (dep[depend][i])
					return false;
			}
		}
	}
	
	//printf("%d\n", index);
	for(int i=0; i<N; i++) {
		if (chests[i].opened)
			continue;
		if (keys[chests[i].reqKey] == 0)
			continue;
			
		keys[chests[i].reqKey]--;
		chests[i].opened = true;
		answer[index] = i;
		for(int j=0; j<chests[i].keyCount; j++)
			keys[chests[i].keys[j]]++;
		
		if (solve(index+1, keys, N, chests, answer))
			return true;
		
		keys[chests[i].reqKey]++;
		chests[i].opened = false;
		for(int j=0; j<chests[i].keyCount; j++)
			keys[chests[i].keys[j]]--;
	}
	return false;
}

int main(int argc, char* argv[]) {
	int T, K, N;
	struct chest chests[201];
	
	setbuf(stdout, NULL);
		
	scanf("%d\n", &T);
	for(int t=0; t<T; t++) {
		max_keys = 0;
		int keys[201];
		scanf("%d %d\n", &K, &N);
		memset(keys, 0 ,sizeof(keys));
		for(int i=0; i<K; i++) {
			int x;
			scanf("%d", &x);
			keys[x]++;
if (x > max_keys) max_keys = x;
		}
		for(int i=0; i<N; i++) {
			memset(&chests[i], 0, sizeof(chests[i]));
			
			chests[i].opened = false;
			scanf("%d %d", &(chests[i].reqKey), &(chests[i].keyCount));
if (chests[i].reqKey > max_keys) max_keys = chests[i].reqKey;
			
			for(int j=0; j<chests[i].keyCount; j++) {
				int x;
				scanf("%d", &x);
				chests[i].keys[j] = x;
if (x > max_keys) max_keys = x;
			}
		}
		
		printf("Case #%d: ", t+1);
		int answer[200];
		if (solve(0, keys, N, chests, answer)) {
			for(int i=0; i<N; i++)
				printf("%d ", answer[i] + 1);
		} else
			printf("IMPOSSIBLE");
		printf("\n");
	}
	
	return 0;
}
