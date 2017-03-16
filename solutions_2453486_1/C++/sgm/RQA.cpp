#include <stdio.h>

int T;
char bo[4][10];

int main(void) {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%s", bo[0]);
		scanf("%s", bo[1]);
		scanf("%s", bo[2]);
		scanf("%s", bo[3]);

		bool x = false;
		bool o = false;

		for(int i = 0; i < 4; i++) {
			bool lx = true;
			bool lo = true;
			for(int j = 0; j < 4; j++) {
				char v = bo[i][j];
				if(v == '.' || v == 'O') lx = false;
				if(v == '.' || v == 'X') lo = false;
			}
			if(lx) x = true;
			if(lo) o = true;
		}

		for(int j = 0; j < 4; j++) {
			bool lx = true;
			bool lo = true;
			for(int i = 0; i < 4; i++) {
				char v = bo[i][j];
				if(v == '.' || v == 'O') lx = false;
				if(v == '.' || v == 'X') lo = false;
			}
			if(lx) x = true;
			if(lo) o = true;
		}

		{
			bool lx = true;
			bool lo = true;
			for(int k = 0; k < 4; k++) {
				char v = bo[k][k];
				if(v == '.' || v == 'O') lx = false;
				if(v == '.' || v == 'X') lo = false;
			}
			if(lx) x = true;
			if(lo) o = true;
		}

		{
			bool lx = true;
			bool lo = true;
			for(int k = 0; k < 4; k++) {
				char v = bo[k][3 - k];
				if(v == '.' || v == 'O') lx = false;
				if(v == '.' || v == 'X') lo = false;
			}
			if(lx) x = true;
			if(lo) o = true;
		}

		if(x) {
			printf("Case #%d: X won\n", t);
		}else if(o) {
			printf("Case #%d: O won\n", t);
		}else {
			bool draw = true;
			for(int i = 0; i < 4; i++) {
				for(int j = 0; j < 4; j++) {
					if(bo[i][j] == '.') {
						draw = false;
					}
				}
			}
			if(draw) {
				printf("Case #%d: Draw\n", t);
			}else {
				printf("Case #%d: Game has not completed\n", t);
			}
		}
	}
	return 0;
}
