#include <stdio.h>

#define MAX 1000100

char s[MAX];

int main()
{
	int t, ccnt;
	scanf("%d",&t);

	int isC[256];
	for(int i='a'; i<='z'; ++i)
		isC[i]=1;
	isC['a']=isC['e']=isC['i']=isC['o']=isC['u']=0;


	for(ccnt=1; ccnt<=t; ++ccnt)
	{
		long long ret=0;
		int sbef=0;
		int n,k;
		int lb=-1;

		scanf(" ");
		scanf("%s%n",s,&n);
		scanf("%d",&k);

		for(int i=0; i<n; ++i)
		{
			if(isC[s[i]])
			{
				++sbef;
				if(sbef>=k)
				{
					ret += (i-k+1-lb)*(long long)(n-i);
					lb=i-k+1;
				}
			}
			else
				sbef=0;
		}
		printf("Case #%d: %lld\n",ccnt,ret);
	}
	return 0;
}


