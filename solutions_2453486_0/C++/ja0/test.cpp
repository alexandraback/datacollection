#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s[4];

bool won(char ch){
	for(int i = 0; i < 4; i++){
		int cnt = 0;
		for(int j = 0; j < 4; j++)if(s[i][j] == ch || s[i][j] == 'T')cnt++;
		if(cnt == 4)return 1;
		cnt = 0;
		for(int j = 0; j < 4; j++)if(s[j][i] == ch || s[j][i] == 'T')cnt++;
		if(cnt == 4)return 1;
	}
	int cnt = 0;
	for(int i = 0, j = 0; i < 4; i++, j++)
		if(s[i][j] == ch || s[i][j] == 'T')cnt++;
	if(cnt == 4)return 1;
	cnt = 0;
	for(int i = 0, j = 3; i < 4; i++, j--)
		if(s[i][j] == ch || s[i][j] == 'T')cnt++;
	if(cnt == 4)return 1;
	return 0;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		for(int i = 0; i < 4; i++)cin >> s[i];
		int f = 0;
		for(int i = 0; i < 4 && !f; i++)
			for(int j = 0; j < 4 && !f; j++)
				if(s[i][j] == '.')f = 1;
		if(won('X'))puts("X won");
		else if(won('O'))puts("O won");
		else if(f)puts("Game has not completed");
		else puts("Draw");
	}
	
	return 0;
}
