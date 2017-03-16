#include <cstdio>

int T, t;
int n;
int s[500];
int r[200];

main()
{
	int i, j;
	int x, min;
	double ans[300], m;
	scanf("%d", &T);
	for(t = 1; t <= T; ++t){
		scanf("%d", &n);
		for(i = 0; i <= 100; ++i)
			r[i] = 0;
		x = 0;
		min = 999;
		for(i = 0; i < n; ++i){
			scanf("%d", &s[i]);
			x += s[i];
			if(s[i] < min)
				min = s[i];
			++r[s[i]];
		}
		j = 0;
		m = 0;
		for(i = 0; i < n; ++i){
			//--r[s[i]];
			
			//for(j = min; j <= 100 && r[j] == 0; ++j)
			//	;
			//printf("\nmin %d s[i] %d ", min, s[i]);
			//printf(">> %d %d %d\n", j, s[i], x);
			
			//ans = ((j+s[i]+x)/2.0-s[i])/x;
			ans[i] = ((2.0*x/n)-s[i])/x;
			if(ans[i] < 0){
				m -= ans[i];
				++j;
			}
			//printf(" [%lf]", ans[i]);
			//++r[s[i]];
		}
		printf("Case #%d:", t);
		for(i = 0; i < n; ++i)
			if(ans[i] < 0)
				printf(" %lf", 0.00);
			else if(j > 0)
				printf(" %lf", (ans[i]-m/(n-j))*100);
			else
				printf(" %lf", ans[i]*100);
		printf("\n");
	}
}
