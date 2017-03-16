#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

FILE *fin = fopen("A.in", "r");
FILE *fout = fopen("A.out", "w");

char ch[111111];

bool vowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int getN(char *a, int k){
	int n = strlen(a);
	int ans = 0;

	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			int tmp = 0;
			int mx = 0;
			for (int l = i; l <= j; l++){
				if (!vowel(a[l])){
					tmp++;
				}
				else {
					mx = max(mx, tmp);
					tmp = 0;
				}
			}
			mx = max(mx, tmp);
			if (mx >= k){
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	int t;
	fscanf(fin, "%d", &t);

	for (int test = 1; test <= t; test++){
		int k;
		fscanf(fin, "%s%d", ch, &k);
		fprintf(fout, "Case #%d: %d\n", test, getN(ch, k));
	}
}