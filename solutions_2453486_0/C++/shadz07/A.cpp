#include <stdio.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <utility>
#include <algorithm>

#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se seconda
#define ll long long
#define mp make_pair
#define pb push_back
#define REP(a, b) for (int a = 0; a < b; ++a)
#define FORU(a, b, c) for (int a = b; a <= c; ++a)
#define FORD(a, b, c) for (int a = b; a >= c; --a)
using namespace std;

char ar[7][7];

bool isFull() {
	FORU(i, 1, 4)
		FORU(j, 1, 4)
			if (ar[i][j] == '.')
				return false;
	
	return true;
}

bool isXWin() {
	bool win;
	
	FORU(i, 1, 4) {
		win = true;
		
		FORU(j, 1, 4)
			if ((ar[i][j] == '.') || (ar[i][j] == 'O'))
				win = false;
		
		if (win)
			return true;
	}
	
	FORU(j, 1, 4) {
		win = true;
		
		FORU(i, 1, 4)
			if ((ar[i][j] == '.') || (ar[i][j] == 'O'))
				win = false;
		
		if (win)
			return true;
	}
	
	win = true;
	
	FORU(i, 1, 4)
		if ((ar[i][i] == '.') || (ar[i][i] == 'O'))
			win = false;
	
	if (win)
		return true;
		
	win = true;
	
	FORU(i, 1, 4)
		if ((ar[i][4-i+1] == '.') || (ar[i][4-i+1] == 'O'))
			win = false;
	
	if (win)
		return true;
	
	return false;
}

bool isOWin() {
	bool win;
	
	FORU(i, 1, 4) {
		win = true;
		
		FORU(j, 1, 4)
			if ((ar[i][j] == '.') || (ar[i][j] == 'X'))
				win = false;
		
		if (win)
			return true;
	}
	
	FORU(j, 1, 4) {
		win = true;
		
		FORU(i, 1, 4)
			if ((ar[i][j] == '.') || (ar[i][j] == 'X'))
				win = false;
		
		if (win)
			return true;
	}
	
	win = true;
	
	FORU(i, 1, 4)
		if ((ar[i][i] == '.') || (ar[i][i] == 'X'))
			win = false;
	
	if (win)
		return true;
		
	win = true;
	
	FORU(i, 1, 4)
		if ((ar[i][4-i+1] == '.') || (ar[i][4-i+1] == 'X'))
			win = false;
	
	if (win)
		return true;
	
	return false;
}

int main() {
	int T;
	char st[7];
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		FORU(i, 1, 4) {
			scanf("%s", st);
			
			FORU(j, 1, 4)
				ar[i][j] = st[j-1];
		}
		
		printf("Case #%d: ", tc);
		
		if (isXWin())
			printf("X won\n");
		else if (isOWin())
			printf("O won\n");
		else if (isFull())
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	
	return 0;
}