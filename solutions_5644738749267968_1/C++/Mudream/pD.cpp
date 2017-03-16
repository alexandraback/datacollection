#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int main()
{
	double Naomi[1010];
	double Ken[1010];
	int T;scanf("%d",&T);
	for(int lT = 1;lT <= T;lT++)
	{
		int N;scanf("%d",&N);
		for(int lx = 0;lx < N;lx++)
			scanf("%lf",&Naomi[lx]);
		for(int lx = 0;lx < N;lx++)
			scanf("%lf",&Ken[lx]);
		std::sort(Naomi,Naomi + N);
		std::sort(Ken,Ken + N);
	/*	printf("Naomi: ");
		for(int lx = 0;lx < N;lx++)
			printf("%.3f ",Naomi[lx]);
		printf("\n");
		printf("Ken: ");
		for(int lx = 0;lx < N;lx++)
			printf("%.3f ",Ken[lx]);
		printf("\n");*/
		int cnt1 = 0;
		int cnt2 = 0;
		int ptrNaomi = 0, ptrKen = 0;
		while((ptrNaomi < N) and (ptrKen < N))
		{
			if(Naomi[ptrNaomi] > Ken[ptrKen])
			{
				ptrKen++;
				cnt1++;
			}
			else
			{
				ptrNaomi++;
				ptrKen++;
			}
		}
		int KenStart = 0, KenEnd = N-1;
		for(int lx = 0;lx < N;lx++)
		{
			if(Naomi[lx] > Ken[KenStart])
			{
				cnt2++;
				KenStart++;
			}
			else
				KenEnd--;
		}
		printf("Case #%d: %d %d\n",lT,cnt2,cnt1);
	}
	return 0;
}
