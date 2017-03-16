#include<stdio.h>
#include<string.h>

bool isvowel(char a) {
	return (a == 'a' || a == 'e' || a == 'i' ||a == 'o' || a == 'u');
}

int main(void) {
	FILE* ifp = fopen("input.txt", "r");
	FILE* ofp = fopen("output.txt", "w");

	int t, cn, n, nv, l, i, sum;
	char* name;
	int* namevalue;

	fscanf(ifp, "%d", &t);
	for (cn=1; cn<=t; cn++) {
		name = new char[101];
		namevalue = new int[101];
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

		fprintf(ofp, "Case #%d: %d\n", cn, nv);
		delete [] name;
		delete [] namevalue;
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}