#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(){
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i){
		int k, l, s;
		scanf("%d%d%d", &k, &l, &s);
		int arrK[27] = { 0 }; // A == 65
		int arrL[27] = { 0 };
		char strL[101] = { 0 };
		char temp[101] = { 0 };
		char arrS[100] = { 0 };
		char ch;
		getchar();
		while ((ch = getchar()) != '\n'){
			++arrK[ch - 64];
		}
		scanf("%s", strL);
		for (int j = 0; j < l; ++j){
			ch = strL[j];
			++arrL[ch - 64];
		}
		int max;
		double res = 1;
		char *strLpointer = strL;
		int same;
		strcpy(temp, strL);
		int j;
		for (j = 1; j < l; ++j){
			temp[l - j] = '\0';
			if (strcmp(temp, strL + j) == 0){
				break;
			}
		}
		same = l - j;
		max = (s - same) / (l - same);
		res = (s - l + 1);
		for (int j = 1; j <= 26; ++j){
			if (arrL[j] != 0){
				if (arrK[j] == 0){
					res = 0;
					max = 0;
				}
				else{
					for (int a = 0; a < arrL[j]; ++a){
						res *= (double)arrK[j] / k;
					}
				}
			}
		}

		printf("Case #%d: %lf\n", i + 1, (double)max - res);
	}
	return 0;
}