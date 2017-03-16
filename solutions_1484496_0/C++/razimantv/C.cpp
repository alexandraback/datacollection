# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>
# include <queue>
# include <string>

using namespace std;

char invpow[1<<20];
char LSB[1<<20];
int subset[2000000];
int subsum[1<<20];
int ar[20];

void work(int i)
{
	if(i==0)
	{
		printf("\n");
		return;
	}
	int bit=LSB[i];
	printf("%d ",ar[bit]);
	work(i^(1<<bit));
}

int main()
{
	for(int i=0;i<20;i++)
		invpow[1<<i]=i;
	for(int i=1;i<(1<<20);i++)
		LSB[i]=invpow[i^(i&(i-1))];
		
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d:\n",t);
		
		int N;
		scanf("%d",&N);
		
		int tot=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",ar+i);
			tot+=ar[i];
		}
		
		memset(subset,0,(tot+1)<<2);
		bool flag=false;
		for(int i=1;i<(1<<N);i++)
		{
			int bit=LSB[i];
			subsum[i]=ar[bit]+subsum[i^(1<<bit)];
			if(subset[subsum[i]]!=0)
			{
				work(i);
				work(subset[subsum[i]]);
				flag=true;
				break;
			}
			subset[subsum[i]]=i;
		}
		if(flag==false)printf("Impossible\n");
	}
	return 0;
}
