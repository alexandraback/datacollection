										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int r, c, m;
char mat[60][60];

int main(){
	freopen("C-Small.in", "r", stdin);
	freopen("C-Small.out", "w", stdout);
	int T, test = 0;
	for(cin >> T; T--; ){
		cout << "Case #" << ++test << ":" << endl;
		cin >> r >> c >> m;
		int rem = r * c - m;
		if(rem == 1){
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++)
					cout << (i == 0 && j == 0 ? 'c' : '*');
				cout << endl;
			}
		}
		else if(r == 1 || c == 1){
			cout << 'c';
			if(c == 1)
				cout << endl;
			for(int i = 0; i < rem - 1; i++){
				cout << '.';
				if(c == 1)
					cout << endl;
			}
			for(int i = 0; i < m; i++){
				cout << '*';
				if(c == 1)
					cout << endl;
			}
			if(c != 1)
				cout << endl;
		}
		else if(r == 2 || c == 2){
			if(m % 2 || rem == 2){
				cout << "Impossible" << endl;
				continue;
			}
			if(r == 2){
				for(int i = 0; i < 2; i++){
					cout << (i == 0 ? 'c' : '.');
					for(int j = 1; j < c; j++)
						cout << (j < rem / 2 ? '.' : '*');
					cout << endl;
				}
			}
			else{
				cout << "c." << endl;
				for(int i = 1; i < r; i++)
					cout << (i < rem / 2 ? ".." : "**") << endl;
			}
		}
		else{
			if(rem == 2 || rem == 3 || rem == 5 || rem == 7){
				cout << "Impossible" << endl;
				continue;
			}
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
					mat[i][j] = '*';
			if(rem > 2 * c + 1){
				int i = 0, j = 0;
				for(int i = 0; i < rem; i++)
					mat[i / c][i % c] = '.';
				if(rem % c == 1){
					mat[rem / c - 1][c - 1] = '*';
					mat[rem / c][1] = '.';
				}	
			}
			else{
				for(int i = 0; i < rem / 2 - 1; i++)
					mat[0][i] = mat[1][i] = '.';
				if(rem % 2)
					mat[2][0] = mat[2][1] = mat[2][2] = '.';
				else mat[0][rem / 2 - 1] = mat[1][rem / 2 - 1] = '.';
			}
			mat[0][0] = 'c';
			for(int i = 0; i < r; i++){
				for(int j = 0; j < c; j++)
					cout << mat[i][j];
				cout << endl;
			}
		}
	}
	return 0;
}
