#include <stdio.h>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int t;
int p[110][110] = {0,};
int c[110] = {0,};
int main(){
	fscanf(input, "%d",&t);
	int tt;
	for(tt = 1; tt <= t; tt++){
		fprintf(output, "Case #%d: ", tt);
		int a, b;
		fscanf(input, "%d%d", &a, &b);
		int i, j, k;
		for(i = 0; i < a; i++){
			for(j = 0; j < b; j++){
				fscanf(input, "%d", &p[i][j]);
				c[p[i][j]]++;
			}
		}
		int count = a*b, min = 0;
		for(;count;){
			int ch1 = 0;
			for(;min<110;min++) if(c[min] > 0) break;
			for(i = 0; i < a; i++){
				for(j = 0; j < b; j++){
					if(p[i][j] == min){
						int ch = 0;
						for(k = 0; k < b; k++) if(p[i][k] > min) ch = 1;
						if(ch == 0){
							for(k = 0; k < b; k++){
								if(p[i][k] != 0){
									c[p[i][k]]--;
									count--;
									p[i][k] = 0;
								}
							}
							ch1 = 1;
							break;
						}
						ch = 0;
						for(k = 0; k < a; k++) if(p[k][j] > min) ch = 1;
						if(ch == 0){
							for(k = 0; k < a; k++){
								if(p[k][j] != 0){
									c[p[k][j]]--;
									count--;
									p[k][j] = 0;
								}
							}
							ch1 = 1;
							break;
						}
					}
				}
				if(ch1 == 1) break;
			}
			if(ch1 == 0) break;
		}
		if(count == 0) fprintf(output, "YES\n");
		else fprintf(output, "NO\n");
		for(i = 0; i < 110; i++) c[i] = 0;
	}
	return 0;
}