#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define VEZES 1000000

int naomi[2000], ken[2000];

char x[30];

int elev(int base, int expo) {
	
	int resp = 1;
	
	int i;
	
	for (i = 0; i < expo; i++) 
		resp *= base;
	
	return resp;
	
}

int main (void)
{
	int t;
	int n;
	
	int dece, war;
	
	int i, j;
	
	FILE *fout = fopen("war.out", "w");
	
	scanf("%d", &t);
	
	for (i = 0; i < t; i++) {
		
		memset(naomi, 0, sizeof(int) * 2000);
		memset(ken, 0, sizeof(int) * 2000);
		dece = 0;
		war = 0;
		
		scanf("%d", &n);
		
		for (j = 0; j < n; j++) {
			
			scanf("%s", x);
			
			naomi[j] = atoi(x + 2) * (VEZES / elev(10, strlen(x + 2)));
			
		}
		sort(naomi, naomi + n);
		
// for (j = 0; j < n; j++) {
// 	printf("\n%d\n", naomi[j]);
// }
		
		for (j = 0; j < n; j++) {
			
			scanf("%s", x);
			
			ken[j] = atoi(x + 2) * (VEZES / elev(10, strlen(x + 2)));
		}
		sort(ken, ken + n);
// for (j = 0; j < n; j++) {
// 	printf("\n%d\n", ken[j]);
// }
		
		for (j = 0; j < n; j++) {
			
			if (naomi[j] > ken[dece])
				dece++;
			
		}
		
		for (j = 0; j < n; j++) {
			int p = 0;
			
			while (p < n && naomi[j] > ken[p]) {
				p++;
			}
			if (p == n)
				war++;
			else
				ken[p] = 0;
			
		}
		
		fprintf(fout, "Case #%d: %d %d\n", i + 1, dece, war);
	}
	
	return 0;
	
}