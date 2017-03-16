#include <stdio.h>

char board[51][51];

int possible(int r, int c, int m){
	int i, j;
	
	int l = r*c - m;
	
	
	if (l == 1){
		for (j = 0; j < r; ++j)
			for (i = 0; i < c; ++i)
				board[j][i] = '*';
		board[0][0] = 'c';
		return 1;
	}
	else if (r == 1){
		board[0][0] = 'c';
		for (i = 1; i < l; ++i)
			board[0][i] = '.';
		for (i = l; i < c; ++i)
			board[0][i] = '*';
		return 1;
	}
	else if (r == 2){
		if ((l%2) || (l < 4))
			return 0;
		
		board[0][0] = 'c';
		for (i = 1; i < l/2; ++i)
			board[0][i] = '.';
		for (i = l/2; i < c; ++i)
			board[0][i] = '*';
		for (i = 0; i < l/2; ++i)
			board[1][i] = '.';
		for (i = l/2; i < c; ++i)
			board[1][i] = '*';
		
		return 1;
	}
	else if (c < 3) // The inverted case will take care of it
		return 0;
	else if (m%c == c-1){
		if (m/c == r-3){
			if (c == 3)
				return 0;
			
			for (j = 0; j < m/c; ++j){
				for (i = 0; i < c; ++i)
					board[j][i] = '*';
			}
			
			board[j][0] = '.';
			board[j][1] = '.';
			board[j][2] = '.';
			for (i = 3; i < c; ++i)
				board[j][i] = '*';
			
			++j;
			for (i = 0; i < c-1; ++i)
				board[j][i] = '.';
			board[j][i] = '*';
			
			++j;
			for (i = 1; i < c-1; ++i)
				board[j][i] = '.';
			board[j][i] = '*';
			
			board[j][0] = 'c';
			return 1;
		}
		else if (m/c < r-3){
			for (j = 0; j < m/c; ++j){
				for (i = 0; i < c; ++i)
					board[j][i] = '*';
			}
		
			board[j][0] = '.';
			board[j][1] = '.';
			for (i = 2; i < c; ++i)
				board[j][i] = '*';
		
			++j;
			for (i = 0; i < c - 1; ++i)
				board[j][i] = '.';
			board[j][c-1] = '*';
		
			++j;
			for (; j < r; ++j)
				for (i = 0; i < c; ++i)
					board[j][i] = '.';
		
			board[r-1][0] = 'c';
		
			return 1;
		}
		// the case m/c == r-2 is the same as l <= 2*c
		// the case m/c == r-1 is the same as l == 1
	}
	
	if ((l == 2) || (l == 3) || (l == 5) || (l == 7))
		return 0;
	else if (l > 2*c){
		for (j = 0; j < m/c; ++j)
			for (i = 0; i < c; ++i)
				board[j][i] = '*';
		
		for (i = 0; i < c-m%c; ++i)
			board[j][i] = '.';
		for (; i < c; ++i)
			board[j][i] = '*';
		++j;
		for (; j < r; ++j)
			for (i = 0; i < c; ++i)
				board[j][i] = '.';
		board[r-1][0] = 'c';
		
		return 1;
	}
	
	if (l%2 == 0){
		for (j = 0; j < r-2; ++j)
			for (i = 0; i < c; ++i)
				board[j][i] = '*';
		
		for (; j < r; ++j){
			for (i = 0; i < l/2; ++i)
				board[j][i] = '.';
			for (; i < c; ++i)
				board[j][i] = '*';
		}
		
		board[r-1][0] = 'c';
		
		return 1;
	}
	else{
		for (j = 0; j < r-2; ++j)
			for (i = 0; i < c; ++i)
				board[j][i] = '*';
		
		board[j-1][0] = board[j-1][1] = board[j-1][2] = '.';
		
		for (; j < r; ++j){
			for (i = 0; i < l/2-1; ++i)
				board[j][i] = '.';
			for (; i < c; ++i)
				board[j][i] = '*';
		}
		
		board[r-1][0] = 'c';
		
		return 1;
	}
		
}

int main(void){
	int t, tn;
	scanf("%d\n", &t);
	
	for (tn = 1; tn <= t; ++tn){
		int r, c, m;
		
		scanf("%d %d %d\n", &r, &c, &m);
		
		printf("Case #%d:\n", tn);
		int invert = 0;
		int result = possible(r, c, m);
		if (!result){
			result = possible(c, r, m);
			invert = 1;
		}
		
		if (!result)
			printf("Impossible\n");
		else{
			int i, j;
			for (i = 0; i < r; ++i){
				for (j = 0; j < c; ++j)
					printf("%c", invert ? board[j][i] : board[i][j]);
				printf("\n");
			}
		}
	}
	
	return 0;
}