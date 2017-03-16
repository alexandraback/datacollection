#include <stdio.h>

int n, m;
int data[110][110];

int main()
{
	FILE *ifp=fopen("b.in" ,"r");
	FILE *ofp=fopen("b.out" ,"w");

	int t, tt=0;
	fscanf(ifp, "%d", &t);
	while (t--) {
		fscanf (ifp, "%d%d", &n, &m);
		for (int i=0; i<n; i++) for (int j=0; j<m; j++)
			fscanf(ifp, "%d", &data[i][j]);

		bool ans=true;
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
			bool f1=false, f2=false;
			for (int k=0; k<m; k++) {
				if (data[i][j] < data[i][k])
					f1=true;
			}
			for (int k=0; k<n; k++) {
				if (data[i][j] < data[k][j])
					f2=true;
			}

			if (f1&&f2)
				ans=false;
		}

		fprintf (ofp, "Case #%d: %s\n", ++tt, ans? "YES" : "NO");
	}

	return 0;
}
