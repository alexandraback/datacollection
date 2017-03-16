#include <stdio.h>
#include <string.h>

char a[1001000];
int n, v[1001000], ans;

FILE *in = fopen("A-large.in", "r");
FILE *out = fopen("output.txt", "w");

int max(int aa, int bb){

	if (aa > bb) return aa;
	return bb;

}
int check(char e){

	if (e == 'a') return 0;
	if (e == 'e') return 0;
	if (e == 'i') return 0;
	if (e == 'o') return 0;
	if (e == 'u') return 0;
	return 1;

}
int main(){

	int T, i;
	fscanf(in, "%d", &T);

	for (i = 1; i <= T; i++){
	
		fscanf(in, "%s %d", &a, &n);
	
		int j;

		ans = 0;
		v[0] = check(a[0]);
		int x = strlen(a);
		
		for (j = 1; j < x; j++){
		
			if (check(a[j]) == 1) v[j] = v[j - 1] + 1; 
			else v[j] = 0;

		}
		
		int s = 0, e = x - 1;

		for (j = x - 1; j >= 0; j--){
		
			if (v[j] >= n) {
				s = j;
				ans += (j - n + 2) * (e - s + 1);
				e = s - 1;
			}
		
		}

		fprintf(out, "Case #%d: %d\n", i, ans);

		for (j = 0; j <= x; j++){
		
			v[j] = 0;
		
		}

	}

}