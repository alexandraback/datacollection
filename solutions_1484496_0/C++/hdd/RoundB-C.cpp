#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define maxn 505
using namespace std;

bool bigs1[maxn],bigs2[maxn];
pair<map<int,int>::iterator,bool> mybpair;
int number[maxn];
map<int,int> hddmaps;

void hddsolution(int icas)
{
	int n,num,sum,i,j,tmp;
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		scanf("%d",number+i);
	}
	hddmaps.clear();
	num=1<<n;
	for(i=0; i<num; i++)
	{
		sum=0;
		for(j=0; j<n; j++)
		{
			if((1<<j)&i)
			{
				sum+=number[j];
			}
		}
		mybpair=hddmaps.insert(make_pair(sum,i));
		if(!mybpair.second)
		{
			memset(bigs1,0,sizeof(bigs1));
			memset(bigs2,0,sizeof(bigs2));
			tmp=hddmaps[sum];
			for(j=0; j<n; j++)
			{
				if((1<<j)&i) bigs1[j]=1;
			}
			for(j=0; j<n; j++)
			{
				if((1<<j)&tmp) bigs2[j]=1;
			}
			printf("Case #%d:\n",icas);
			for(j=0; j<n; j++)
			{
				if(bigs1[j] && !bigs2[j])
				{
					printf("%d",number[j]);
					break;
				}
			}
			j++;
			for(; j<n; j++)
			{
				if(bigs1[j] && !bigs2[j]) printf(" %d",number[j]);
			}
			puts("");
			for(j=0; j<n; j++)
			{
				if(bigs2[j] && !bigs1[j])
				{
					printf("%d",number[j]);
					break;
				}
			}
			j++;
			for(; j<n; j++)
			{
				if(bigs2[j] && !bigs1[j]) printf(" %d",number[j]);
			}
			puts("");
			break;
		}
	}
}

int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-small-attempt0.out","w",stdout);
	int cas,icas=0;
	scanf("%d",&cas);
	while(cas--)
	{
		icas++;
		hddsolution(icas);
	}
	system("pause");
	return 0;
}
