#include <cstdio>
#include <algorithm>

#define NUMKEYS 201

typedef struct Chest {
	int type;
	int opened;
	int keys[NUMKEYS];
} Chest;

typedef struct State {
	int moves;
	int * moveList;
	int * currentKeys;
	Chest * chestState;
} State;

void setKeysToZero(int * keys) {
	for (int i = 0; i < NUMKEYS; i++) {
		keys[i] = 0;
	}
}

void initChests(Chest * chests, int size) {
	for (int i = 0; i < size; i++) {
		chests[i].type = 0;
		chests[i].opened = 0;
		setKeysToZero(chests[i].keys);
	}
}

bool emptyKeys(Chest ch) {
	for (int i = 1; i < NUMKEYS; i++) {
		if (ch.keys[i] > 0)
			return false;
	}
	return true;
}

bool runValid(State * st, int * moves, int N) {
	bool ret = true;
	int * keys = new int[NUMKEYS];
	for (int i = 1; i < NUMKEYS; i++) {
		keys[i] = st->currentKeys[i];
	}
	int type;
	for (int i = 0; i < N; i++) {
		type = st->chestState[moves[i]].type;
		keys[type] -= 1;
		if (keys[type] < 0) {
			ret = false;
			break;
		}
		for (int j = 1; j < NUMKEYS; j++) {
			keys[j] += st->chestState[moves[i]].keys[j];
		}
	}
	delete [] keys;
	return ret;
}

bool subsetKeys(Chest ch, int * ke) {
	for (int i = 1; i < NUMKEYS; i++) {
		if (ch.keys[i] > ke[i])
			return false;
	}
	return true;
}

int arrayMin(int * list, int from, int end) {
	if (from == end - 1)
		return list[from];
	return std::min(arrayMin(list, from, (from + end) / 2), arrayMin(list, (from + end) / 2, end));
}

void bubbleUp(int * list, int from, int to) {
	int temp;
	for (int i = from; i > to; i--) {
		temp = list[i];
		list[i] = list[i - 1];
		list[i - 1] = temp;
	}
}

void bubbleDown(int * list, int from, int to) {
	int temp;
	for (int i = from; i < to; i++) {
		temp = list[i];
		list[i] = list[i + 1];
		list[i + 1] = temp;
	}
}

void solve(int caseNum, int K, int N) {
	
	int key, x;
	State * stackFront;
	
	stackFront = new State;
	stackFront->moves = 0;
	stackFront->moveList = new int[N];
	
	stackFront->currentKeys = new int[NUMKEYS];
	setKeysToZero(stackFront->currentKeys);
	
	for (int j = 0; j < K; j++) {
		scanf("%d", &key);
		stackFront->currentKeys[key]++;
	}
	
	stackFront->chestState = new Chest[N + 1];
	initChests(stackFront->chestState, N + 1);
	
	for (int j = 1; j <= N; j++) {
		scanf("%d %d", &x, &key);
		stackFront->chestState[j].type = x;
		for (int k = 0; k < key; k++) {
			scanf("%d", &x);
			stackFront->chestState[j].keys[x]++;
		}
	}
	
	State * back = new State;
	
	back->moves = N;
	back->moveList = new int[N];
	
	back->currentKeys = new int[NUMKEYS];
	setKeysToZero(back->currentKeys);
	
	for (int j = 1; j < NUMKEYS; j++) {
		back->currentKeys[j] += stackFront->currentKeys[j];
	}
	
	back->chestState = new Chest[N + 1];
	initChests(back->chestState, N + 1);
	
	for (int j = 1; j <= N; j++) {
		back->chestState[j].type = stackFront->chestState[j].type;
		back->chestState[j].opened = 1;
		for (int k = 1; k < NUMKEYS; k++) {
			back->chestState[j].keys[k] = stackFront->chestState[j].keys[k];
			back->currentKeys[k] += back->chestState[j].keys[k];
		}
		back->currentKeys[back->chestState[j].type]--;
	}
	
	int i, j;
	
	for (i = N; i > 0; i--) {
		x = 0;
		for (j = N; j > 0; j--) {
			if (back->chestState[j].opened) {
				if (emptyKeys(back->chestState[j]) || subsetKeys(back->chestState[j], back->currentKeys)) {
					back->chestState[j].opened = 0;
					back->currentKeys[back->chestState[j].type]++;
					for (int k = 1; k < NUMKEYS; k++) {
						back->currentKeys[k] -= back->chestState[j].keys[k];
					}
					back->moveList[i-1] = j;
					back->moves--;
					x = 1;
					break;
				}
			}
		}
		if (x = 0) goto noSolve;
	}
	if (back->moves != 0) {
		noSolve:
		delete [] stackFront->moveList;
		delete [] stackFront->currentKeys;
		delete [] stackFront->chestState;
		delete stackFront;
		
		delete [] back->moveList;
		delete [] back->currentKeys;
		delete [] back->chestState;
		delete back;
		
		printf("Case #%d: IMPOSSIBLE\n", caseNum);
		return;
	}
	int swap;
	int * result = back->moveList;
	int max;
	
	/* BUBBLE */
	bubble:
	max = 0;
	swap = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (result[i] < arrayMin(result, j, N)) {
				break;
			}
			if (result[i] > result[j]) {
				bubbleUp(result, j, i);
				if (runValid(stackFront, result, N)) {
					swap = 1;
					break;
				}
				bubbleDown(result, i, j);
			}
		}
	}
	if (swap == 1) goto bubble;
	/* END BUBBLE */
	
	printf("Case #%d:", caseNum);
	for (int i = 0; i < N; i++) {
		printf(" %d", result[i]);
	}
	printf("\n");
	
	delete [] stackFront->moveList;
	delete [] stackFront->currentKeys;
	delete [] stackFront->chestState;
	delete stackFront;
	
	delete [] back->moveList;
	delete [] back->currentKeys;
	delete [] back->chestState;
	delete back;
	
	return;
}

int main() {
	int T, K, N;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &K, &N);
		solve(i, K, N);
	}
	return 0;
}
