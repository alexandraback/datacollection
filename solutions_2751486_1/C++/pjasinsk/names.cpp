//#include <algorithm>
//#include <string>
#include <stdio.h>
//#include <set>



char S[1000001];

int main()
{
	int N;
	int t, n;
	scanf("%d", &t);
	
	for (int k=1;k<=t;++k)
	{
		long long int res= 0;
		int last = 0;
		scanf("%s %d", S, &n);
		int counter = 0;
		for(N=0;S[N]!=0;++N)
		{}
		--N;
		for(int i=0;i <= N;++i)
		{
			if(S[i]=='a' || S[i]=='e' || S[i]=='o' || S[i]=='u' || S[i]=='i')
			{
				counter = 0;
			}
			else
			{
				counter++;
				if(counter>=n)
				{
					printf("%d %d %d %d\n", i, n ,last, N);
					res += ((i-n+2)-last)*(N-i+1);
					last = i-n+2;
				}
			}
		}
		printf("Case #%d: %lld\n",k, res);
	}
	return 0;
}