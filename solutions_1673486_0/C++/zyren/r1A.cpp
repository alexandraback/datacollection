#include <stdio.h>
#define MAX 4//小数据
#define MAX 100000//小数据

double p[MAX];
 int main()
 {
	 freopen("C:\\A-small-attempt0.in", "r", stdin);
	 freopen("C:\\1.out", "w", stdout);
	 int i,j,k, A, B,T, cases=0;
	 double expected, min, pp;
	 scanf("%d", &T);
	 while (++cases <= T)
	 {
		 scanf("%d%d", &A, &B);
			for(i=0; i<A; i++)	
			 scanf("%lf", &p[i]);
		//min = A+B+10;
		pp = 1;
		//继续typing(不退)
		j = 0;
		while(j<A)
			pp *= p[j++];
		min = pp*(B-A+1)+(1-pp)*(B-A+1+B+1);
		//直接回车肯定错，A<B
		expected = 1+B+1;
		if(min > expected)
			min = expected;
		
		pp = 1;
		for (j=0; j<A-1; j++)//退A-j-1格，还有j+1个(退全单独考虑)//不退???
		{
			k = A-j-1;
			pp *= p[j];
			expected = pp*(B-(j+1)+1)+(1-pp)*(B-(j+1)+1+B+1);//优化
			if(min > expected+k)
				min = expected+k;
		}
		if(min > A+B+1)//退全
			min = A+B+1;
		 printf("Case #%d: %.6lf\n", cases, min);
	 }
	 return 0;
 }