#include<stdio.h>

bool find_solution(int* keys, int* chests, bool* chestopened, int* numberopened, int** keysinside, int* chestkeys, int solution[], int n, int* sn, int* nkeys, int *keysexcept, int* keychestremained) {
	if (*numberopened == n) return 1;
	int i, j, k;
	for (i=0; i<n; i++) {
		if (!chestopened[i] && keys[chests[i]] > 0) {
			keys[chests[i]]--;
			keychestremained[chests[i]]--;
			(*nkeys)--;
			(*numberopened)++;
			chestopened[i] = true;
			solution[(*sn)++] = i;
			bool impossible = 0;
			for (j=0; j<chestkeys[i]; j++) {
				keys[keysinside[i][j]]++;
				if (chests[i] != keysinside[i][j]) keysexcept[keysinside[i][j]]--;
				(*nkeys)++;
			}
			if (*numberopened == n) return 1;
			if (*nkeys == 0)
				impossible = 1;
			else if (keys[chests[i]] == 0 && keysexcept[chests[i]] == 0 && keychestremained[chests[i]] != 0) {
				impossible = 1;
			}
			if (!impossible && find_solution(keys, chests, chestopened, numberopened, keysinside, chestkeys, solution, n, sn, nkeys, keysexcept, keychestremained))
				return true;
			else {
				keys[chests[i]]++;
				(*nkeys)++;
				(*numberopened)--;
				keychestremained[chests[i]]++;
				chestopened[i] = false;
				for (j=0; j<chestkeys[i]; j++) {
					keys[keysinside[i][j]]--;
					if (chests[i] != keysinside[i][j]) keysexcept[keysinside[i][j]]++;
					(*nkeys)--;
				}
				solution[--(*sn)] = 0;
			}
		}
	}
	return false;
}

int main() {
	FILE* ifp = fopen("input.txt", "r");
	FILE* ofp = fopen("output.txt", "w");

	int c, nc = 0;
	int k, n, i, j, temp;
	fscanf(ifp, "%d", &c);
	while(c--) {
		nc++;
		fscanf(ifp, "%d %d", &k, &n);
		int mostkeyforsolution = 0;
		int keys[401] = {0,};
		int keysforsolution[401] = {0,};
		int keysexcept[401] = {0,};
		int keychestremained[401] = {0,};
		for (i=0; i<k; i++) {
			fscanf(ifp, "%d", &temp);
			keys[temp] += 1;
			keysforsolution[temp]++;
			if (mostkeyforsolution < temp) mostkeyforsolution = temp;
		}
		bool chestopened[400] = {0,};
		int numberopened = 0;
		int* chests = new int[n];
		int* chestkeys = new int[n];
		int** keysinside = new int*[n];
		for (i=0; i<n; i++) {
			fscanf(ifp, "%d", &chests[i]);
			fscanf(ifp, "%d", &chestkeys[i]);
			keysforsolution[chests[i]]--;
			keychestremained[chests[i]]++;
			if (mostkeyforsolution < chests[i]) mostkeyforsolution = chests[i];
			if (chestkeys[i]) keysinside[i] = new int[chestkeys[i]];
			for (j=0; j<chestkeys[i]; j++) {
				fscanf(ifp, "%d", &keysinside[i][j]);
				keysforsolution[keysinside[i][j]]++;
				if (chests[i] != keysinside[i][j]) keysexcept[keysinside[i][j]]++;
				if (mostkeyforsolution < keysinside[i][j]) mostkeyforsolution = keysinside[i][j];
			}
		}
		bool impossible = 0;
		for (i=0; i<=mostkeyforsolution; i++) {
			if (keysforsolution[i] < 0) {impossible=1; break;}
		}
		int* solution = new int[n];
		int sn = 0;
		fprintf(ofp, "Case #%d: ", nc);
		if (impossible) {
			fprintf(ofp, "IMPOSSIBLE");
		} else if (find_solution(keys, chests, chestopened, &numberopened, keysinside, chestkeys, solution, n, &sn, &k, keysexcept, keychestremained)) {
			for (i=0; i<n; i++)
				fprintf(ofp, "%d ", solution[i]+1);
		} else {
			fprintf(ofp, "IMPOSSIBLE");
		}
		fprintf(ofp, "\n");
		delete [] chests;
		delete [] chestkeys;
		//for (i=0; i<n; i++)
			//delete [] keysinside[i];
		delete[] keysinside;
		delete[] solution;
	}

	fclose(ifp);
	fclose(ofp);
	return 0;

}