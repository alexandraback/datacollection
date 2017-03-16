#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <string.h>

int main () {
	int i, j, k, l, m, n, o, p, q, r, s, t, X, O;
	std::set<int> col;
	char vet[6];
	std::set<int>::iterator it;
	
	col.clear();
	t = 33;
	for (i = 1; i <= t; i++) {
		sprintf(vet, "%d", i);
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
			sprintf(vet, "%d", l);
			s = strlen(vet);
			k = 1;
			for (j = 0; j < s; j++) {
				if (vet[j] != vet[s-j-1]) {
					k = 0;
					break;
				}
			}
			if (k) {
				col.insert(l);
			//	printf("%d\n", l);
			}
		}
	}
	
	scanf(" %d ", &t);
	for (o = 1; o <= t; o++) {
		scanf(" %d %d ", &n, &m);
		s = 0;
		for ( i = n; i <= m; i++) {
			it = col.find(i);
			if (it != col.end()) {
				s++;	
			}
		}
		printf("Case #%d: %d\n", o, s);
	}
	
	return 0;
}
