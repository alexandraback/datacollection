#include <stdio.h>
#include <string.h>

int map[100][100];
int m, r, c;
FILE *fp,*fout;
int ind=0;

void printimpossible() {
    fprintf(fout, "Impossible\n");
}

void printmap() {
	for (int y=0; y<r;y++) {
		for (int x=0; x<c; x++) {
			if (x==c-1&&y==r-1) fprintf(fout, "c");
			else if (map[x][y]==0) fprintf(fout, ".");
			else fprintf(fout, "*");
		}
		fprintf(fout, "\n");
	}
}

void fillmap() {
	if (r*c-m == 1) {
		for (int y=0; y<r; y++) {
			for (int x=0; x<c; x++) {
				map[x][y] = 1;
			}
		}
		return;
	}

	// fill to r-2
	for (int y=0; y<r-2 && m>0; y++) {
		for (int x=0; x<c && m>0; x++) {
			map[x][y] = 1;
			m--;

			if (y == r-3 && x == c-4 && m%2 == 0)
				break;
			if (x == c-3 && m == 1)
				break;
		}
	}
	
	for (int x=0; x<c && m>0; x++) {
		for (int y=r-2; y<r && m>0; y++) {
			if (y < 0) y=0;
			map[x][y] = 1;
			m--;
		}
	}
}

void process() {
	// init map
	memset(map, 0, sizeof(map));
	ind++;
	fprintf(fout, "Case #%d:\n", ind);

	// check case
	if (r*c<=m) {
		printimpossible();
		return;
	} else if (r>=2 && c>=2 && r*c-m<4 && r*c-m != 1) {
		printimpossible();
		return;
	} else if ((r == 2 || c == 2) && (m%2==1) && r*c-m != 1) {
		printimpossible();
		return;
	} else if ((r >= 2 && c >= 2) && (r*c-m == 5 || r*c-m == 7)) {
		printimpossible();
		return;
	}

	fillmap();
	printmap();
}

int main() {
	fp = fopen("3.input", "r");
	fout = fopen("3.output", "w");

	int cnt;
	fscanf(fp, "%d", &cnt);

	for (int i=0; i<cnt; i++) {
		fscanf(fp, "%d %d %d", &r, &c, &m);
		process();
	}

	fclose(fp);
	fclose(fout);

	return 0;	
}
