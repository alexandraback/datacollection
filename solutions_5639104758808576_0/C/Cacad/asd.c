#include <stdio.h>

int main()
{
	char num[7];
	int size, smax, sum, i, j, ans;

	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);


	scanf("%d", &size);
	for (i=0; i<size ; i++)
	{
		scanf("%d",&smax);
		scanf("%s", num);
		sum=0;
		ans=0;
		for (j=0; j<smax+1 ; j++)
		{
			if(num[j]=='0' && j+1>sum)
			{
				ans+=1;
				sum+=1;
			}
			else
				sum+=num[j]-'0';
		}
		printf("Case #%d: %d\n",i+1,ans);
	}

}