#include <stdio.h>

FILE *in, *out;
char field[50][50];
int r, c, m;

void printfield() {
	int row, col;
	for(row = 0; row < r; row++) {
		for(col = 0; col < c; col++) {
			fprintf(out, "%c", field[row][col]);
		}
		fprintf(out, "\n");
	}
}

void clearfield() {
	int row, col;
	for(row = 0; row < r; row++) {
		for(col = 0; col < c; col++) {
			field[row][col] = '.';
		}
	}
}

int countbombs(int row, int col) {
	int displacements[] = {0,1 , 1,1 , 1,0 , 1,-1 , 0,-1 , -1,-1 , -1,0 , -1,1};
	int i;
	int bombcount = 0;
	for(i = 0; i < 16; i+=2) {
		int tr, tc;
		tr = row + displacements[i];
		tc = col + displacements[i+1];
		if(0 > tr || tr >= r) {
			continue;
		}
		if(0 > tc || tc >= c) {
			continue;
		}
		if(field[tr][tc] == '*') {
			bombcount++;
		}
	}
	return bombcount;
}

int validchecker(int row, int col) {
	int displacements[] = {0,1 , 1,1 , 1,0 , 1,-1 , 0,-1 , -1,-1 , -1,0 , -1,1};
	int count = 0;
	if(field[row][col] == '.') {
		count++;
		field[row][col] = 'x';
		if(countbombs(row, col) == 0) {
			int i;
			for(i = 0; i < 16; i+=2) {
				int tr, tc;
				tr = row + displacements[i];
				tc = col + displacements[i+1];
				if(0 > tr || tr >= r) {
					continue;
				}
				if(0 > tc || tc >= c) {
					continue;
				}
				count += validchecker(tr, tc);
			}
		}
	}
	return count;
}

void erasex() {
	int row, col;
	for(row = 0; row < r; row++) {
		for(col = 0; col < c; col++) {
			if(field[row][col] == 'x')
				field[row][col] = '.';
		}
	}
}

int isvalid() {
	int row, col;
	for(row = 0; row < r; row++) {
		for(col = 0; col < c; col++) {
			if(field[row][col] == '.') {
				int count = validchecker(row, col);
				erasex();
				if(count == r*c - m)
					return 1;
			}
		}
	}
	return 0;
}

int placemine(int startrow, int startcol, int placed) {
	if(placed == m) {
		if(isvalid())
			return 1;
		else
			return 0;
	}
	int row, col;
	for(row = startrow; row < r; row++) {
		for(col = startcol; col < c; col++) {
			if(field[row][col] == '.') {
				field[row][col] = '*';
				if(placemine(row, col, placed+1)) {
					return 1;
				}
				else {
					field[row][col] = '.';
				}
			}
		}
		startcol = 0;
	}
	return 0;
}

void putlc() {
	int row, col;
	for(row = 0; row < r; row++) {
		for(col = 0; col < c; col++) {
			if(field[row][col] != '*') {
				if(countbombs(row, col) == 0) {
					field[row][col] = 'c';
					return;
				}
				if(r*c - m == 1) {
					field[row][col] = 'c';
					return;
				}
			}
		}
	}
}

void runtestcase(int caseno) {
	fprintf(out, "Case #%i:\n", caseno);
	fscanf(in, "%i %i %i", &r, &c, &m);
	clearfield();
	if(placemine(0, 0, 0)) {
		putlc();
		printfield();
	}
	else {
		fprintf(out, "Impossible\n");
	}
}

void main(int argc, char *argv[]) {
	in = fopen(argv[1], "r");
	out = fopen("minesweeper.out", "w");
	
	int t;
	fscanf(in, "%i", &t);
	int i;
	for(i = 0; i < t; i++) {
		runtestcase(i+1);
	}
}