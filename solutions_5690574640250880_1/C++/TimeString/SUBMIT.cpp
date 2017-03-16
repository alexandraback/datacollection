#include <stdio.h>

char pr8[3][4] = {
	"*..",
	"...",
	"..c",
};

char pr6[3][4] = {
	"***",
	"...",
	"..c",
};

char pr4[3][4] = {
	"***",
	"*..",
	"*.c",
};


void fill(char array[100][100], int er, int ec, int em) {
	if (em == 0)
		return;
	for (int i = 0; i < er - 2; i++)
		for (int j = 0; j < ec - 2; j++) {
			array[i][j] = '*';
			em--;
			if (em == 0)
				return;
		}
	if (em % 2 == 1) {
		array[er - 3][ec - 3] = '.';
		em++;
	}
	for (int i = 0; i < er - 3; i++) {
		array[i][ec - 1] = array[i][ec - 2] = '*';
		em -= 2;
		if (em == 0)
			return;
	}
	for (int i = 0; i < ec - 3; i++) {
		array[er - 1][i] = array[er - 2][i] = '*';
		em -= 2;
		if (em == 0)
			return;
	}
	if (em != 0)
		printf("WHAT THY\n");
}

void attach(char array[100][100], int er, int ec, char pattern[3][4]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[er - 3 + i][ec - 3 + j] = pattern[i][j];
}
int main(int argc, char *argv[]) {
	int ecase, ecount;
	int caseStart = -1, caseEnd = 9999999;
	scanf("%d", &ecase);

	if (argc > 1) {
		if (sscanf(argv[1], "%d", &caseStart) == 1) {
			if (argc > 2)
				sscanf(argv[2], "%d", &caseEnd);
		}
		if (caseEnd < caseStart)
			caseEnd = caseStart;
		if (caseEnd != 9999999 && caseEnd >= 1 && caseStart <= 0)
			caseStart = 1;
		if (caseStart > 0)
			fprintf(stderr, "....................DEBUG MODE ENABLED (FROM CASE %d to %d)\n", caseStart, caseEnd);
	}

	char array[100][100];
	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		int er, ec, em;
		scanf("%d%d%d", &er, &ec, &em);
		
		printf("Case #%d:\n", ecount);
		int remain = er * ec - em;
		if (remain == 1) {
			for (int i = 0; i < er; i++) {
				for (int j = 0; j < ec; j++) {
					printf("%c", ((i == 0 && j == 0) ? 'c': '*'));
				}
				printf("\n");
			}
		}
		else if (er == 1) {
			for (int i = 0; i < ec; i++) {
				if (i < em)
					printf("*");
				else if (i != ec - 1)
					printf(".");
				else
					printf("c");
			}
			printf("\n");
		}
		else if (ec == 1) {
			for (int i = 0; i < er; i++) {
				if (i < em)
					printf("*");
				else if (i != er - 1)
					printf(".");
				else
					printf("c");
				printf("\n");
			}
		}
		else if (ec == 2) {
			if (remain == 2 || remain % 2 == 1)
				printf("Impossible\n");
			else {
				for (int i = 0; i < er; i++) {
					if (i < em / 2)
						printf("**\n");
					else if (i == er - 1)
						printf(".c\n");
					else
						printf("..\n");
				}
			}
		}
		else if (er == 2) {
			if (remain == 2 || remain % 2 == 1)
				printf("Impossible\n");
			else {
				for (int i = 0; i < er; i++) {
					for (int j = 0; j < ec; j++) {
						if (j < em / 2)
							printf("*");
						else if (i == 1 && j == ec - 1)
							printf("c");
						else
							printf(".");
					}
					printf("\n");
				}
			}
		}
		else {
			if (remain == 2 || remain == 3 || remain == 5 || remain == 7)
				printf("Impossible\n");
			else {
				for (int i = 0; i < er; i++)
					for (int j = 0; j < ec; j++)
						array[i][j] = '.';
				array[er-1][ec-1] = 'c';
				if (remain >= 9) {
					fill(array, er, ec, em);
				}
				else {
					fill(array, er, ec, er*ec - 9);
					if (remain == 8)
						attach(array, er, ec, pr8);
					if (remain == 6)
						attach(array, er, ec, pr6);
					if (remain == 4)
						attach(array, er, ec, pr4);
				}
				for (int i = 0; i < er; i++) {
					for (int j = 0; j < ec; j++) 
						printf("%c", array[i][j]);
					printf("\n");
				}
			}
		}

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
