#include <stdio.h>
#include <algorithm>
using namespace std;
int t, n, p[1000], q[1000];
int main()
{
	FILE *fin = fopen("B.in", "r"), *fout = fopen("B.out", "w");
	fscanf(fin, "%d", &t);
	for(int t_id = 1; t_id <= t; t_id++)
	{
		fscanf(fin, "%d", &n);
		for(int i = 0; i < n; i++)
			fscanf(fin, "%d", &p[i]);
		int sum = 0, ans = 2147483647;
		for(int i = 0; i < n; i++)
			sum += p[i];
		sort(p, p + n);
		for(int i = 1000; i > 0; i--)
		{
			int cnt = 0;
			for(int j = 0; j < n; j++)
				q[j] = p[j];
			for(int j = n - 1; j >= 0 && q[j] > i; j--)
			{
				while(q[j] > i)
					q[j] -= min(q[j] - i, i), cnt++;
			}
			ans = min(ans, cnt + i);
		}
		fprintf(fout, "Case #%d: %d\n", t_id, ans);
	}
	fclose(fin), fclose(fout);
	return 0;
}
