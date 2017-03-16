#include<stdio.h>

int main(void) {
	FILE* ifp = fopen("input.txt", "r");
	FILE* ofp = fopen("output.txt", "w");

	int c, nc = 0;
	int n, m, i, j, k;
	fscanf(ifp, "%d", &c);
	while(c--) {
		nc++;
		fscanf(ifp, "%d %d", &n, &m);
		int a[100][100] = {0,};
		bool b[100][100] = {0,};
		bool canYou = 1;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				fscanf(ifp, "%d", &a[i][j]);
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				for (k=0; k<m; k++)
					if (a[i][j] < a[i][k])
						b[i][j] = true;
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
					for (k=0; k<n; k++)
						if (a[i][j] < a[k][j] && b[i][j])
							canYou = 0;

		fprintf(ofp, "Case #%d: ", nc);
		if (canYou)
			fprintf(ofp, "YES");
		else
			fprintf(ofp, "NO");
		fprintf(ofp, "\n");
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}