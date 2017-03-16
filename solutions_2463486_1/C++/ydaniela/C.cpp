#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	long long int i, j, k, l, m, n, o, p, q, r, s, t, X, O;
	char vet[50];
	long long int col[150];
	
	t = 10000000;
	p = 0;
	for (i = 1; i <= t; i++) {
		sprintf(vet, "%I64d", i);
		s = strlen(vet);
		k = 1;
		for (j = 0; j < s; j++) {
			if (vet[j] != vet[s-j-1]) {
				k = 0;
				break;
			}
		}
		if (k) {
			l = i*i;
			sprintf(vet, "%I64d", l);
			s = strlen(vet);
			k = 1;
			for (j = 0; j < s; j++) {
				if (vet[j] != vet[s-j-1]) {
					k = 0;
					break;
				}
			}
			if (k) {
				col[p++] = l;
			}
		}
	}
	scanf(" %I64d ", &t);
	for (o = 1; o <= t; o++) {
		scanf(" %I64d %I64d ", &n, &m);
		for (s = 0; s < p; s++) {
			if (col[s] >= n) {
				break;	
			}
		}
		i = s;
		for (; s < p; s++) {
			if (m < col[s]) {
				break;	
			}
		}
		printf("Case #%I64d: %I64d\n", o, s-i);
	}
	
	return 0;
}
