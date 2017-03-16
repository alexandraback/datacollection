#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

const int MAXCHESTSKEYS = 300;

int chests[MAXCHESTSKEYS];
int keys[MAXCHESTSKEYS];
int keyToOpen[MAXCHESTSKEYS];
int chestsToKey[MAXCHESTSKEYS];
vector<int> chestKeys[MAXCHESTSKEYS];
bitset<MAXCHESTSKEYS> visited;
bitset<MAXCHESTSKEYS> selfsustained;

bool recStep(int cur, int n, bitset<MAXCHESTSKEYS> prevChecked = 0, int prev = 0) {
	if (cur == n)
		return true;

	bitset<MAXCHESTSKEYS> checked;

	for (int i=0; i<n; i++) {
		if (visited[i])
			continue;

		if (keys[keyToOpen[i]] == 0)
			continue;

		if (!prevChecked[keyToOpen[i]] and i < prev)
			continue;

		visited[i] = true;
		--keys[keyToOpen[i]];

		if (chestKeys[i].size() > 0)
			--chestsToKey[keyToOpen[i]];

		chests[cur] = i+1;
		checked.reset();
		for (unsigned j=0; j<chestKeys[i].size(); j++) {
			++keys[chestKeys[i][j]];
			checked.set(chestKeys[i][j]);
		}

		if (recStep(cur+1, n, checked, i))
			return true;

		for (unsigned j=0; j<chestKeys[i].size(); j++) --keys[chestKeys[i][j]];
		++keys[keyToOpen[i]];
		visited[i] = false;
	
		if (chestKeys[i].size() > 0)
			++chestsToKey[keyToOpen[i]];

		if (chestsToKey[keyToOpen[i]]==0 or selfsustained[i])
			break;

		if (chestKeys[i].size() > 0 and chestsToKey[keyToOpen[i]]==1)
			break;
	}
	return false;
}


int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		fill(keys, keys+MAXCHESTSKEYS, 0);
		fill(chestsToKey, chestsToKey+MAXCHESTSKEYS, 0);
		visited.reset();
		selfsustained.reset();
		
		int k, n;
		scanf("%d %d", &k, &n);

		int t;
		for (int i=0; i<k; i++) {
			scanf("%d", &t);
			++keys[t];
		}

		for (int i=0; i<n; i++) {
			chestKeys[i].resize(0);
			scanf("%d %d", keyToOpen+i, &k);
			if (k>0)
				chestsToKey[keyToOpen[i]]++;

			for (int j=0; j<k; j++) {
				scanf("%d", &t);
				chestKeys[i].push_back(t);
				if (t == keyToOpen[i])
					selfsustained.set(i);
			}
		}

		printf("Case #%d:", iC);
		if (recStep(0, n)) {
			for (int i=0; i<n; i++)
				printf(" %d", chests[i]);
			printf("\n");
		}
		else printf(" IMPOSSIBLE\n");

	}
	return 0;
}
