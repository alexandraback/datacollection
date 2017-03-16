#include <stdio.h>
int t, n;
char a[1001];
int main()
{
	FILE *fin = fopen("A.in", "r"), *fout = fopen("A.out", "w");
	fscanf(fin, "%d", &t);
	for(int t_id = 1; t_id <= t; t_id++)
	{
		fscanf(fin, "%d%s", &n, a);
		for(int i = 0; i <= n; i++)
			a[i] -= '0';
		int ans = 0;
		for(int i = 0, j = 0; i < n; i++)
		{
			if((j += a[i]) < i + 1)
				ans++, j++;
		}
		fprintf(fout, "Case #%d: %d\n", t_id, ans);
	}
	fclose(fin), fclose(fout);
	return 0;
}
