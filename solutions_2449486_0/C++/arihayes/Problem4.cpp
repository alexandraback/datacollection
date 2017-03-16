#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

struct {
	unsigned short keys[200];
	unsigned short need;
	bool open;
} typedef Chest;

Chest chests[200];
int answer[200];
unsigned short keys[200];
int numChests;
int numKeysStart;
int depth;

bool findSolution() {
	if(depth == numChests) {
		return true;
	}
	
	bool success = false;
	for(int x = 0; x < numChests; x++) {
		if(keys[chests[x].need] && !chests[x].open) {
			chests[x].open = true;
			keys[chests[x].need]--;
			for(int y = 0; y < 200; y++) {
				keys[y] += chests[x].keys[y];
			}
			depth++;
			success = findSolution();
			depth--;
			for(int y = 0; y < 200; y++) {
				keys[y] -= chests[x].keys[y];
			}
			keys[chests[x].need]++;
			chests[x].open = false;
			
			if(success) {
				answer[depth] = x + 1;
				return success;
			}
		}
	}
	
	return false;
}

int main(int argc, char ** argv) {
	int numCases;
	
	cin >> numCases;
	for(int x = 0; x < numCases; x++) {
		memset(keys, 0, sizeof(keys));
		cin >> numKeysStart;
		cin >> numChests;
		for(int y = 0; y < numKeysStart; y++) {
			short key;
			cin >> key;
			keys[key-1]++;
		}
		for(int y = 0; y < numChests; y++) {
			cin >> chests[y].need;
			chests[y].need--;
			short numChestKeys;
			cin >> numChestKeys;
			memset(chests[y].keys, 0, sizeof(chests[y].keys));
			chests[y].open = false;
			
			for(int z = 0; z < numChestKeys; z++) {
				short num;
				cin >> num;
				chests[y].keys[num-1]++;
			}
		}
		
		depth = 0;
		bool solvable = findSolution();
		cout << "Case #" << (x+1) << ": ";
		if(solvable) {
			cout << answer[0];
			for(int y = 1; y < numChests; y++) {
				cout << " ";
				cout << answer[y];
			}
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	}
}
