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

long long ar[500];
map<long long,int>summap;

void work(int t)
{
	if(t==0){printf("\n");return;}
	printf("%Ld ",ar[(t%501)-1]);
	work(t/501);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		printf("Case #%d:\n",tt);
		
		int N;
		scanf("%d",&N);
		
		for(int i=0;i<N;i++)
			scanf("%Ld",ar+i);
		
		sort(ar,ar+N);
		summap.clear();
		
		for(int i=0;i<N;i++)
		{
			summap[ar[i]]=i;
		}
		
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
			{
				long long s=ar[i]+ar[j];
				int t=(i+1)+(j+1)*501;
				if(summap.count(s)!=0)
				{
					work(summap[s]);
					work(t);
					goto BPP;
				}
				else summap[s]=t;
			}
			
		for(int i=0;i<N;i++)
			for(int j=i+1;j<N;j++)
				for(int k=j+1;k<N;k++)
				{
					long long s=ar[i]+ar[j]+ar[k];
					int t=(i+1)+(j+1)*501+(k+1)*501*501;
					if(summap.count(s)!=0)
					{
						work(summap[s]);
						work(t);
						goto BPP;
					}
					else summap[s]=t;
				}
		BPP:;
	}
	return 0;
}
