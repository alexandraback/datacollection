#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 150

int main()
{
	int t;
	scanf("%d",&t);

	for(int tcnt=1; tcnt<=t;++tcnt)
	{
		int s,p,n;
		int scores[MAX];
		int res = 0;
		scanf("%d %d %d",&n,&s,&p);
		for(int i=0; i<n; ++i)
			scanf("%d",&scores[i]);
		for(int i=0; i<n; ++i)
		{
			if( (scores[i]+2)/3 >= p )
				++res;
			else if(s && (scores[i]+1)/3 >= p-1 && scores[i]>=2)
			{
				++res;
				--s;
			}
		}

		printf("Case #%d: %d\n",tcnt,res);
	}
	return 0;
}


