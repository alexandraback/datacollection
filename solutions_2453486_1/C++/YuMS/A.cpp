#include <cstdio>

int main() {
	int T;
	int validX;
	int validO;
	char now;
	int invalid[4][4] = {{750, 990, 958, 382}, {1005, 733, 445, 893}, {1003, 475, 699, 891}, {487, 983, 951, 631}};
	int nowInvalid;
	bool finished;
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		validX = validO = 0x3FF;
		finished = true;
		scanf("%c", &now);
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				nowInvalid = invalid[j][k];
				scanf("%c", &now);
				switch (now) {
					case 'X':
						validO &= nowInvalid;
						break;
					case 'O':
						validX &= nowInvalid;
						break;
					case '.':
						validX &= nowInvalid;
						validO &= nowInvalid;
						finished = false;
						break;
				}
				//printf("X%d\n", validX);
				//printf("O%d\n", validO);
			}
			scanf("%c", &now);
		}
		printf("Case #%d: ", i + 1);
		if (validO) {
			printf("O won\n");
		} else if (validX) {
			printf("X won\n");
		} else if (finished) {
			printf("Draw\n");
		} else {
			printf("Game has not completed\n");
		}
	}
	return 0;
}
