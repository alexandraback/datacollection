#include<stdio.h>
#include<string.h>

__int64 namevalue[1000001];

bool isvowel(char a) {
	return (a == 'a' || a == 'e' || a == 'i' ||a == 'o' || a == 'u');
}

int main(void) {
	FILE* ifp = fopen("A-large.in", "r");
	FILE* ofp = fopen("output.txt", "w");

	int t, cn, n, l, i, sum;
	char* name;
	__int64 nv;

	fscanf(ifp, "%d", &t);
	for (cn=1; cn<=t; cn++) {
		name = new char[1000001];
		fscanf(ifp, "%s", name);
		fscanf(ifp, "%d", &n);
		l = strlen(name);
		sum=0;
		if (isvowel(name[0])) {
			sum = 0;
			namevalue[0] = 0;
		} else {
			sum++;
			if (sum >= n) 
				namevalue[0] = 1;
			else 
				namevalue[0] = 0;
		}
		if (isvowel(name[1])) {
			sum = 0;
			namevalue[1] = 2 * namevalue[0];
		} else {
			sum++;
			if (sum >= n) 
				namevalue[1] = namevalue[0] + 3-n;
			else 
				namevalue[1] = 2 * namevalue[0];
		}
		for (i=2; i<l; i++) {
			if (isvowel(name[i])) {
				namevalue[i] = 2 * namevalue[i-1] - namevalue[i-2];
				sum = 0;
			} else {
				sum++;
				if (sum >= n) 
					namevalue[i] = i-(n-2) + namevalue[i-1];
				else 
					namevalue[i] = 2 * namevalue[i-1] - namevalue[i-2];
			}
		}
		nv = namevalue[l-1];

		fprintf(ofp, "Case #%d: %I64d\n", cn, nv);
		delete [] name;
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}