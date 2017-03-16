#include <stdio.h>
#include <algorithm>
FILE* input = fopen("input.txt", "r");
FILE* output = fopen("output.txt", "w");
int t, tt;
int p[300] = {0,};
int main(){
	fscanf(input, "%d", &t);
	for(tt = 1; tt <= t; tt++){
		int s, a;
		fscanf(input, "%d%d", &s, &a);
		int i;
		for(i = 0; i < a; i++) fscanf(input, "%d", &p[i]);
		std::sort(p, p+a);
		fprintf(output, "Case #%d: ", tt);
		int c = 0, ans = 2147483647;
		if(s == 1){
			fprintf(output, "%d\n", a);
			continue;
		}
		for(i = 0; i < a; i++){
			if(p[i] < s) s += p[i];
			else{
				if(c + a - i < ans) ans = c+a-i;
				for(;;){
					s = s * 2 - 1;
					c++;
					if(p[i] < s) break;
				}
				s += p[i];
			}
		}
		if(c < ans) ans = c;
		fprintf(output, "%d\n", ans);
	}
	return 0;
}