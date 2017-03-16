#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[4][10];
bool flag;
int cnt;

int main() {
	int T;
	scanf("%d", &T);
	
	for (int ca = 1; ca <= T; ca++) {
		printf("Case #%d: ", ca);
	
		for (int i = 0; i < 4; i++)
			scanf("%s", s[i]);
		
		flag = false;
		for (int i = 0; i < 4; i++) {
		    cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (s[i][j] == 'X') cnt++;
				if (s[i][j] == '.') cnt = -4;
				if (s[i][j] == 'O') cnt = -4;
			}
			if (cnt == 3 || cnt == 4) {
				printf("X won\n");
				flag = true;
				break;
			}
			
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (s[j][i] == 'X') cnt++;
				if (s[j][i] == '.') cnt = -4;
				if (s[j][i] == 'O') cnt = -4;
			}
			if (cnt == 3 || cnt == 4) {
				printf("X won\n");
				flag = true;
				break;
			}
			
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (s[j][j] == 'X') cnt++;
				if (s[j][j] == '.') cnt = -4;
				if (s[j][j] == 'O') cnt = -4;
			}
			if (cnt == 3 || cnt == 4) {
				printf("X won\n");
				flag = true;
				break;
			}
			
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (s[j][3 - j] == 'X') cnt++;
				if (s[j][3 - j] == '.') cnt = -4;
				if (s[j][3 - j] == 'O') cnt = -4;
			}
			if (cnt == 3 || cnt == 4) {
				printf("X won\n");
				flag = true;
				break;
			}			
		}
		if (flag) continue;
		    
		flag = false;
		for (int i = 0; i < 4; i++) {
		    cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (s[i][j] == 'O') cnt++;
				if (s[i][j] == '.') cnt = -4;
				if (s[i][j] == 'X') cnt = -4;
			}
			if (cnt == 3 || cnt == 4) {
				printf("O won\n");
				flag = true;
				break;
			}
			
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (s[j][i] == 'O') cnt++;
				if (s[j][i] == '.') cnt = -4;
				if (s[j][i] == 'X') cnt = -4;
			}
			if (cnt == 3 || cnt == 4) {
				printf("O won\n");
				flag = true;
				break;
			}
			
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (s[j][j] == 'O') cnt++;
				if (s[j][j] == '.') cnt = -4;
				if (s[j][j] == 'X') cnt = -4;
			}
			if (cnt == 3 || cnt == 4) {
				printf("O won\n");
				flag = true;
				break;
			}
			
			cnt = 0;
			for (int j = 0; j < 4; j++) {
				if (s[j][3 - j] == 'O') cnt++;
				if (s[j][3 - j] == '.') cnt = -4;
				if (s[j][3 - j] == 'X') cnt = -4;
			}
			if (cnt == 3 || cnt == 4) {
				printf("O won\n");
				flag = true;
				break;
			}			
		}
		if (flag) continue;
		
		bool full = true;
		for (int i = 0; i < 4; ++i)
		    for (int j = 0; j < 4; ++j)
			    if (s[i][j] == '.')
				    full = false;				
		if (!full) printf("Game has not completed\n");
		else printf("Draw\n");
	}
	
	return 0;
}