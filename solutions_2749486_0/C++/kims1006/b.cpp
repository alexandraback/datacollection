#include <stdio.h>

int xx, yy;

FILE *in = fopen("B-small-attempt1.in", "r");
FILE *out = fopen("output.txt", "w");

int main(){

	int T, i, j;

	fscanf(in, "%d", &T);

	for (i = 1; i <= T; i++){
	
		int x, y;

		fscanf(in, "%d %d", &x, &y);
		
		int ch = 1;

		fprintf(out, "Case #%d: ", i);
		
		int cc, ccc;
		xx = 0; yy = 0;
		if (x > 0) cc = 1;
		else cc = 0;
		if (y > 0) ccc = 1;
		else ccc = 0;
		for (j = 1; ; j++){
		
			if (xx == x && yy == y) break;
			if (ch == 1){
				if (cc == 1){
					
					if (xx + j > x) break;
					xx += j;
					fprintf(out, "E");
				
				}else {
					
					if (xx - j < x) break;
					xx -= j;
					fprintf(out, "W");
				
				}
				ch = 0;
			}
			else if (ch == 0){
				
				if (ccc == 1){
					
					if (yy + j > y) break;
					yy += j;
					fprintf(out, "N");
				
				}else {
					
					if (yy - j < y) break;
					yy -= j;
					fprintf(out, "S");
				
				}
				ch = 1;
			}

		}
	
		for (j += 1;; j+=2){
		
			if (xx == x) break;
			if (cc == 1){
				fprintf(out, "WE");
				xx += 1;
			}else {
				fprintf(out, "EW");
				xx -= 1;
			}
		
		}
		for (j += 1;; j+=2){
		
			if (yy == y) break;
			if (ccc == 1){
				fprintf(out, "SN");
				yy += 1;
			}else {
				fprintf(out, "NS");
				yy -= 1;
			}
		
		}
	
		fprintf(out, "\n");

	}

}