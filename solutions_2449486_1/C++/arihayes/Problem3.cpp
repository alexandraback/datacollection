#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char ** argv) {
	unsigned short field[100][100];
	int numCases;
	
	cin >> numCases;
	for(int x = 0; x < numCases; x++) {
		//memset(keys, 0, sizeof(keys));
		int m;
		int n;
		cin >> m;
		cin >> n;
		for(int y = 0; y < m; y++) {
			for(int z = 0; z < n; z++) {
				cin >> field[y][z];
			}
		}
		
		bool solvable = true;
		for(int y = 0; y < m && solvable; y++) {
			for(int z = 0; z < n && solvable; z++) {
				bool horizontal = true;
				bool vertical = true;
				for(int a = 0; a < m && vertical; a++) {
					vertical = field[a][z] <= field[y][z];
				}
				
				for(int a = 0; a < n && horizontal; a++) {
					horizontal = field[y][a] <= field[y][z];
				}
				
				solvable = horizontal || vertical;
			}
		}
		
		cout << "Case #" << (x+1) << ": ";
		if(solvable) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}
