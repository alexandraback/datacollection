#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);

	for(int cn=1; cn<=t; cn++)
	{

		int k,c,s;
		scanf("%d %d %d",&k,&c,&s);
		int num = (k+c-1)/c;
		printf("Case #%d:",cn);
		if(num>s)
		{
			printf(" IMPOSSIBLE\n");
			continue;
		}

		int curr = 0;
		for(int i=0; i<num; i++)
		{
			long long total = 0;
			for(int j=0; j<c; j++)
			{
				total = total*k + (curr%k);
				curr++;
			}

			printf(" %lld",total+1);
		}
		printf("\n");
	}
}