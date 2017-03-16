#include <stdio.h>

int main()
{
	int cn, cc;
	freopen("l.in", "r", stdin);
	freopen("l.out", "w", stdout);
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int row, col;
		int mtr[100][100];
		int reach[100][100] = {0};
		int ar;
		int i,j;

		scanf("%d%d", &row, &col);

		for (i=0; i<row; i++){
			for (j=0; j<col; j++)
				scanf("%d", mtr[i]+j);
		}

		for (i=0; i<row; i++)
		{
			int max = 1;

			for (j=0; j<col; j++){
				if (mtr[i][j] > max)
					max = mtr[i][j];
			}

			for (j=0; j<col; j++){
				if (mtr[i][j] == max)
					reach[i][j] = 1;
			}
		}

		for (j=0; j<col; j++)
		{
			int max = 1;
			
			for (i=0; i<row; i++){
				if (mtr[i][j] > max)
					max = mtr[i][j];
			}

			for (i=0; i<row; i++){
				if (mtr[i][j] == max)
					reach[i][j] = 1;
			}
		}

		ar = 1;
		for (i=0; i<row; i++){
			for (j=0; j<col; j++)
				if (!reach[i][j])
					ar = 0;
		}

		printf("Case #%d: %s\n", cc, ar ? "YES" : "NO");
	}

	return 0;
}