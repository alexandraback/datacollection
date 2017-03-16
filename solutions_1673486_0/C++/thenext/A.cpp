#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	FILE *fp = fopen("C:\\Users\\Jeffrey\\Desktop\\output.txt", "w");
	int T = 0;
	int t = 0;
	scanf("%d", &T);
	while(t++ < T)
	{
		int A = 0, B = 0;
		int i = 0, j = 0;
		double p = 1, pi = 0;
		double best = 0;
		int sum = 0;
		double temp = 0;
		scanf("%d%d", &A, &B);
		sum = A+B-1;
		best = B+2;
		for(i = 1; i <= A; i++)
		{
			scanf("%lf", &pi);
			p *= pi;
			temp = p*sum+(1-p)*(sum+B+1);
			if(temp-best < 0)
				best = temp;
			sum -= 2;
		}
		printf("Case #%d: %.6lf\n", t, best);
		fprintf(fp, "Case #%d: %.6lf\n", t, best);
	}
	fclose(fp);
	return 0;
}