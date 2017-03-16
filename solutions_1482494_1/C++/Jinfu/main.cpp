#include <iostream>
#include <vector>
using namespace std;
int level[1010][2];
const int finish=4000;
int N;
int cnt;
int star;
bool Search()
{
	for(int i=0;i<N;i++)
	{
		if(level[i][1]!=finish&&star>=level[i][1])
		{
			if(level[i][0]!=finish) star+=2;
			else star+=1;
			level[i][0]=level[i][1]=finish;
			cnt++;			
			return true;
		}
	}

	int index=-1;
	int mm=-1;
	for(int i=0;i<N;i++)
	{
		if(level[i][0]!=finish&&star>=level[i][0])
		{			
			if(level[i][1]>mm)
			{
				mm=level[i][1];
				index=i;
			}
		}
	}
	if(index!=-1)
	{
		level[index][0]=finish;
		star+=1;
		return true;
	}
	
	return false;
}
int main()
{
	freopen("d:\\in.txt","r",stdin);
	freopen("d:\\out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d %d",&level[i][0],&level[i][1]);
		}
		cnt=0;
		star=0;
		int ans=0;
		while(Search())
		{
			ans++;
		}
		if(cnt==N)
			printf("%d\n",ans);
		else
			printf("Too Bad\n");
	}
	return 0;
}