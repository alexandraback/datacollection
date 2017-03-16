#include <cstdio>
#include <map>
using namespace std;

const int MAXN=505;

map<int,int> have;
//////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int num[MAXN],N;

void output(int S)
{
	bool first=true;
	for(int i=0;i<N;i++)
		if (S&(1<<i))
		{
			if (first) 
			{
				printf("%d",num[i]);
				first=false;
			}
			else 
				printf(" %d",num[i]);
		}
	printf("\n");
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d:\n",i);
		have.clear();
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d",num+i);
		for(int i=0;i<(1<<N);i++)
		{
			int sum=0;
			for(int j=0;j<N;j++)
				if (i&(1<<j))
				{
					sum+=num[j];
				}
			if (have.count(sum))
			{
				int that=have[sum];
				output(that);
				output(i);
				break;
			}
			else
				have[sum]=i;
		}
	}
	return 0;
}