#include<cstdio>
#include<algorithm>

double _tab1[1010], _tab2[1010];

int main()
{
	int T; scanf("%d",&T);
	for(int ii = 0; ii < T; ii++)
	{
		int N; scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%lf", _tab1+i);
		for(int i = 0; i < N; i++)
			scanf("%lf", _tab2+i);
		std::sort(_tab1,_tab1+N);
		std::sort(_tab2,_tab2+N);
		printf("Case #%d: ",ii+1);
		double *tab1 = _tab1, *tab2 = _tab2;
		int j = N-1;
		for(int i = N-1; i >= 0; i--)
		{
			while(j >= 0 && tab2[j] > tab1[i]) j--;
			if(j < 0) {printf("%d ",N-i-1); break;}
			j--;
			if(i == 0) printf("%d ",N);
		}
		tab1 = _tab2; tab2 = _tab1;
		j = N-1;
		for(int i = N-1; i >= 0; i--)
		{
			while(j >= 0 && tab2[j] > tab1[i]) j--;
			if(j < 0) {printf("%d ",i+1); break;}
			j--;
			if(i == 0) printf("%d ",0);
		}
		printf("\n");
	}
	return 0;
}
