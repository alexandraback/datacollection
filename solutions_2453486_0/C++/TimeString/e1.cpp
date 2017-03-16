#include <stdio.h>

int ttoi[256];

int main() {
	int ecase, ecount;
	char eb[4][6];
	char tok[2] = {'X', 'O'};
	ttoi['X'] = 0;
	ttoi['O'] = 1;
	ttoi['.'] = 2;

	scanf("%d", &ecase);
	for (ecount = 1; ecount <= ecase; ecount++) {
		for (int i = 0; i < 4; i++)
			scanf("%s", eb[i]);
		int dmany = 0;
		int tr=3, tc=4;
		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++) {
				if (eb[i][j] == '.')
					dmany++;
				if (eb[i][j] == 'T') {
					tr = i;
					tc = j;
				}
			}

		bool win[3] = {false, false, false};
		for (int k = 0; k < 2; k++) {
			int j;
			eb[tr][tc] = tok[k];
			
			for (int i = 0; i < 4; i++) {
				for (j = 1; j < 4; j++) {
					if (eb[i][j] != eb[i][0])
						break;
				}
				if (j == 4)
					win[ ttoi[ eb[i][0] ] ] = true;
			//	printf("%d %d %d\n", (int)win[0], (int)win[1], (int)win[2]);
				
				for (j = 1; j < 4; j++) {
					if (eb[j][i] != eb[0][i])
						break;
				}
				if (j == 4)
					win[ ttoi[ eb[0][i] ] ] = true;
			//	printf("%d %d %d\n", (int)win[0], (int)win[1], (int)win[2]);
			}

			for (j = 1; j < 4; j++)
				if (eb[j][j] != eb[0][0])
					break;
			if (j == 4)
				win[ ttoi[ eb[0][0] ] ] = true;
			//	printf("%d %d %d\n", (int)win[0], (int)win[1], (int)win[2]);
			
			for (j = 1; j < 4; j++)
				if (eb[j][3-j] != eb[0][3])
					break;
			if (j == 4)
				win[ ttoi[ eb[0][3] ] ] = true;
			//	printf("%d %d %d\n", (int)win[0], (int)win[1], (int)win[2]);
		}

		if (win[0] && win[1])
			fprintf(stderr, "both wins...\n");

		if (win[0])
			printf("Case #%d: X won\n", ecount);
		else if (win[1])
			printf("Case #%d: O won\n", ecount);
		else if (dmany != 0)
			printf("Case #%d: Game has not completed\n", ecount);
		else
			printf("Case #%d: Draw\n", ecount);

	}

	return 0;
}
