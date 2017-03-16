#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define KEYS 100

struct Chest {
	int need;
	int keys[KEYS];
	int nkeys;
};

int keys[KEYS];
Chest chests[25];
int T, N, K;

int taken[25];
vector<int> Q;
bool solved;

bool can_take(int i) {
	if (keys[chests[i].need]) {
		return true;
	}
	return false;
}

void take(int i) {
	keys[chests[i].need]--;
	for(int j=1; j<KEYS; j++) {
		keys[j] += chests[i].keys[j];
	}
	taken[i] = 1;
	Q.push_back(i);
	return;
}

void undo(int i) {
	keys[chests[i].need]++;
	for(int j=1; j<=KEYS; j++) {
		keys[j] -= chests[i].keys[j];
	}
	taken[Q.back()] = 0;
	Q.pop_back();
	return;
}


void recurse(int numtaken) {
	if (numtaken == N) {
		solved = 1;
		return;
	}
	for(int i=0; i<N; i++) {
		//for every chest, if can take, recurse
		if ((!taken[i]) && can_take(i)) {
			take(i);
			recurse(numtaken+1);
			if (solved) return;
			undo(i);
		}
	}
	return;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);

	for(int asdf=1; asdf<=T; asdf++) {
		scanf("%d%d", &K, &N);
		memset(chests, 0, sizeof(chests));
		memset(keys, 0, sizeof(keys));
		memset(taken, 0, sizeof(taken));
		Q.clear();
		solved = 0;

		for(int i=0; i<K; i++) {
			int j; scanf("%d", &j);
			keys[j]++;
		}
		for(int i=0; i<N; i++) {
			scanf("%d", &chests[i].need);
			scanf("%d", &chests[i].nkeys);
			for(int j=0; j<chests[i].nkeys; j++) {
				int k; scanf("%d", &k);
				chests[i].keys[k]++;
			}
		}
		recurse(0);
		printf("Case #%d:", asdf);
		if (solved) {
			for(int i=0; i<Q.size(); i++) {
				printf(" %d", Q[i]+1);
			}
			putchar('\n');
		} else {
			printf(" IMPOSSIBLE\n");
		}
	}

	return 0;
}