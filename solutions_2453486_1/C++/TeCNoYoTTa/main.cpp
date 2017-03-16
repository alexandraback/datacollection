#include <iostream>
using namespace std;

char grid[4][4];

bool isWinner(char V) {
	bool D1Check = true, D2Check = true;
	for (int i=0;i<4;i++) {
		bool HCheck = true, VCheck = true;
		for (int j=0;j<4;j++) {
			if (grid[i][j] != V && grid[i][j] != 'T') HCheck = false;
			if (grid[j][i] != V && grid[j][i] != 'T') VCheck = false;
		}
		if (HCheck || VCheck)
			return true;
		
		if (grid[i][i] != V && grid[i][i] != 'T') D1Check = false;
		if (grid[i][3-i] != V && grid[i][3-i] != 'T') D2Check = false;
	}
	if (D1Check || D2Check)
		return true;
	return false;
	
}

int main() {
	freopen("Text.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	cin.ignore();
	for(int c=1;c<=T;c++) {
		bool emptyFound = false;
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				scanf("%c", grid[i] + j);
				if (grid[i][j] == '.')
					emptyFound = true;
			}
			cin.ignore();
		}
		cin.ignore();
		printf("Case #%d: ", c);
		if (isWinner('X'))
			printf("X won\n");
		else if(isWinner('O'))
			printf("O won\n");
		else if(emptyFound)
			printf("Game has not completed\n");
		else
			printf("Draw\n");

	}
	return 0;
}