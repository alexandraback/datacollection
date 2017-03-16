#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

char map[5][5];

int main(){
	int i, j, k, T, ans;
//	freopen("A-large.in","r", stdin);
//	freopen("A.out","w", stdout);
	
	while(scanf("%d", &T) != EOF){
		for (k = 1; k <= T; k++){
			for (i = 0; i < 4; i++){
				getchar();
				for (j = 0; j < 4; j++){
					map[i][j] = getchar();
//					printf("%c", map[i][j]);
				}
			}
			getchar();
			ans = 0;
			for (i = 0; i < 4; i++){
				for (j = 0; j < 4; j++)
					if (!(map[i][j] == 'X' || map[i][j] == 'T')) break; 
				if (j >= 4){ ans = 1; break;}
				for (j = 0; j < 4; j++)
					if (!(map[i][j] == 'O' || map[i][j] == 'T')) break;
				if (j >= 4){ ans = 2; break;}
				
				for (j = 0; j < 4; j++)
					if (!(map[j][i] == 'X' || map[j][i] == 'T')) break;
				if (j >= 4){ ans = 1; break;}
				for (j = 0; j < 4; j++)
					if (!(map[j][i] == 'O' || map[j][i] == 'T')) break;
				if (j >= 4){ ans = 2; break;}
			}
			if (ans == 0){
				for (j = 0; j < 4; j++)
					if (!(map[j][j] == 'X' || map[j][j] == 'T')) break;
				if (j >= 4) ans = 1;
			}
			if (ans == 0){
				for (j = 0; j < 4; j++)
					if (!(map[j][3 - j] == 'X' || map[j][3 - j] == 'T')) break;
				if (j >= 4) ans = 1;
			}
			if (ans == 0){
				for (j = 0; j < 4; j++)
					if (!(map[j][j] == 'O' || map[j][j] == 'T')) break;
				if (j >= 4) ans = 2;
			}
			if (ans == 0){
				for (j = 0; j < 4; j++)
					if (!(map[j][3 - j] == 'O' || map[j][3 - j] == 'T')) break;
				if (j >= 4) ans = 2;
			}
			if (ans == 0){
				for (i = 0; i < 4 && ans == 0; i++)
					for (j = 0; j < 4 && ans == 0; j++)
						if (map[i][j] == '.') ans = -1;
			}
			printf("Case #%d: ", k);
			if (ans == 0) printf("Draw\n");
			else if (ans == 1) printf("X won\n");
			else if (ans == 2) printf("O won\n");
			else if (ans == -1) printf("Game has not completed\n");
		}
	}
	return 0;
}
