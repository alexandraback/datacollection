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

long double score[200];
long double need[200];

long double find(int index, long double tot, int N)
{
	long double start=0,end=1,mid;
	while(end-start>1e-8)
	{
		mid=(start+end)/2;
		long double cur=score[index]+mid*tot;
		bool flag=true;
		long double thisp=mid;
		for(int i=0;i<N&&flag==true;i++)
		{
			if(i==index||score[i]>=cur)continue;
			thisp+=(cur-score[i])/tot;
			if(thisp>1)flag=false;
		}
		if(flag)start=mid;
		else end=mid;
	}
	return mid;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int N;
		scanf("%d",&N);
		
		long double tot=0;
		for(int i=0;i<N;i++)
		{
			scanf("%Lf",score+i);
			tot+=score[i];
		}
		
		printf("Case #%d:",t);
		for(int i=0;i<N;i++)
			printf(" %.8Lf",100*find(i,tot,N));
		printf("\n");
	}
	return 0;
}
