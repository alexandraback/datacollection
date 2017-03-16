#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

#define MAXCHESTS 20
#define MAXKEYS 20

struct {
	unsigned short keys[MAXKEYS];
	int id;
	unsigned short need;
	bool open;
} typedef Chest;

Chest goodChests[MAXCHESTS];
Chest badChests[MAXCHESTS];
unsigned short prelim[MAXCHESTS];
unsigned short answer[MAXCHESTS];
unsigned short keys[MAXKEYS];
unsigned short leftoverKeys[MAXKEYS];
int numTotalChests;
int numGoodChests;
int numBadChests;
int depth;

bool maybePossible() {
	signed short final[MAXKEYS];
	for(int x = 0; x < MAXKEYS; x++) {
		final[x] = keys[x];
	}
	
	for(int x = 0; x < numBadChests; x++) {
		final[badChests[x].need]--;
	}
	for(int x = 0; x < numGoodChests; x++) {
		final[goodChests[x].need]--;
		for(int y = 0; y < MAXKEYS; y++) {
			final[y] += goodChests[x].keys[y];
		}
	}
	
	for(int x = 0; x < MAXKEYS; x++) {
		if(final[x] < 0)
			return false;
	}
	
	return true;
}

bool canOpenEmptyChests() {
	for(int x = 0; x < numBadChests; x++) {
		if(leftoverKeys[badChests[x].need]) {
			leftoverKeys[badChests[x].need]--;
		}
		else {
			return false;
		}
	}
	return true;
}

bool possible() {
	if(depth == numGoodChests) {
		for(int x = 0; x < MAXKEYS; x++) {
			leftoverKeys[x] = keys[x];
		}
		return true;
	}
	
	bool success = false;
	for(int x = 0; x < numGoodChests; x++) {
		if(keys[goodChests[x].need] && !goodChests[x].open) {
			goodChests[x].open = true;
			keys[goodChests[x].need]--;
			for(int y = 0; y < MAXKEYS; y++) {
				keys[y] += goodChests[x].keys[y];
			}
			depth++;
			success = possible();
			depth--;
			for(int y = 0; y < MAXKEYS; y++) {
				keys[y] -= goodChests[x].keys[y];
			}
			keys[goodChests[x].need]++;
			goodChests[x].open = false;
			
			if(success) {
				prelim[depth] = x;
				return success;
			}
		}
	}
	
	return false;
}

bool findSolution(int index) {
	if(depth == numGoodChests + numBadChests) {
		return true;
	}
	
	int pre = prelim[index];
	bool success = false;
	for(int x = 0; x < numBadChests; x++) {
		if(index != numGoodChests && badChests[x].id > goodChests[pre].id) {
			break;
		}
		if(keys[badChests[x].need] && !badChests[x].open) {
			badChests[x].open = true;
			keys[badChests[x].need]--;
			for(int y = 0; y < MAXKEYS; y++) {
				keys[y] += badChests[x].keys[y];
			}
			depth++;
			success = findSolution(index);
			depth--;
			for(int y = 0; y < MAXKEYS; y++) {
				keys[y] -= badChests[x].keys[y];
			}
			keys[badChests[x].need]++;
			badChests[x].open = false;
			
			if(success) {
				answer[depth] = badChests[x].id + 1;
				return success;
			}
		}
	}
	
	if(index == numGoodChests) {
		return false;
	}
	
	if(keys[goodChests[pre].need] && !goodChests[pre].open) {
		goodChests[pre].open = true;
		keys[goodChests[pre].need]--;
		for(int y = 0; y < MAXKEYS; y++) {
			keys[y] += goodChests[pre].keys[y];
		}
		depth++;
		success = findSolution(index + 1);
		depth--;
		for(int y = 0; y < MAXKEYS; y++) {
			keys[y] -= goodChests[pre].keys[y];
		}
		keys[goodChests[pre].need]++;
		goodChests[pre].open = false;
		
		if(success) {
			answer[depth] = goodChests[pre].id + 1;
			return success;
		}
	}
	
	return false;
}

int main(int argc, char ** argv) {
	int numCases;
	
	cin >> numCases;
	for(int x = 0; x < numCases; x++) {
		memset(keys, 0, sizeof(keys));
		int numKeysStart;
		cin >> numKeysStart;
		cin >> numTotalChests;
		numGoodChests = 0;
		numBadChests = 0;
		for(int y = 0; y < numKeysStart; y++) {
			short key;
			cin >> key;
			keys[key-1]++;
		}
		for(int y = 0; y < numTotalChests; y++) {
			int need;
			short numChestKeys;
			cin >> need;
			cin >> numChestKeys;
			need--;
			if(numChestKeys) {
				goodChests[numGoodChests].need = need;
				memset(goodChests[numGoodChests].keys, 0, sizeof(goodChests[0].keys));
				goodChests[numGoodChests].open = false;
				goodChests[numGoodChests].id = y;
				
				for(int z = 0; z < numChestKeys; z++) {
					short num;
					cin >> num;
					goodChests[numGoodChests].keys[num-1]++;
				}
				numGoodChests++;
			}
			else {
				badChests[numBadChests].need = need;
				memset(badChests[numBadChests].keys, 0, sizeof(badChests[0].keys));
				badChests[numBadChests].open = false;
				badChests[numBadChests].id = y;
				numBadChests++;
			}
		}
		
		depth = 0;
		bool solvable = maybePossible();
		if(solvable) solvable = possible();
		if(solvable) solvable = canOpenEmptyChests();
		
		/*cout << numGoodChests << ": " << (prelim[0] + 1);
		for(int y = 1; y < numBadChests + numGoodChests; y++) {
			cout << " ";
			cout << (prelim[y] + 1);
		}cout << "\n";fflush(stdout);*/
		
		cout << "Case #" << (x+1) << ": ";
		if(solvable) {
			depth = 0;
			if(!findSolution(0)) {
				cout << "SANITY CHECK FAILED9\n";
			}
			cout << answer[0];
			for(int y = 1; y < numBadChests + numGoodChests; y++) {
				cout << " ";
				cout << answer[y];
			}
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << "\n";fflush(stdout);
	}
}
