#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int  grid[100][100];
bool proc[100][100];

typedef pair<int, int> PAIR;
typedef pair<int, PAIR> TRIPLE;

void markRow(int row){
	for(int i = 0; i < M; i++)
		proc[row][i] = true;
}

void markCol(int col){
	for(int i = 0; i < N; i++)
		proc[i][col] = true;
}

bool checkRow(int row, int val){
	for(int i = 0; i < M; i++)
		if(!proc[row][i] && grid[row][i] != val)
			return false;
	return true;
}

bool checkCol(int col, int val){
	for(int i = 0; i < N; i++)
		if(!proc[i][col] && grid[i][col] != val)
			return false;
	return true;
}

bool possible(){
	vector<TRIPLE> entries;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			entries.push_back(TRIPLE(grid[i][j], PAIR(i, j)));
	}
	sort(entries.begin(), entries.end());
	for(int i = 0; i < entries.size(); i++){
		PAIR coords = entries[i].second;
		if(proc[coords.first][coords.second])
			continue;
		
		if(checkRow(coords.first, entries[i].first))
			markRow(coords.first);
		else if (checkCol(coords.second, entries[i].first))
			markCol(coords.second);
		else 
			return false;
	}
	return true;
}

int main(){
	int T; cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N; cin >> M;
		memset(proc, false, sizeof(proc));
		
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				int h; cin >> h;
				grid[j][k] = h;
			}
		}
		
		if(possible())
			cout << "Case #" << (i+1) << ": YES" << endl;
		else
			cout << "Case #" << (i+1) << ": NO" << endl;
	}
}
