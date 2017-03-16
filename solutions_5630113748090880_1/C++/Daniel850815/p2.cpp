#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

map<int,int>m;
map<int,int>::iterator it;

int main()
{
	//freopen("result.txt","w",stdout);
	int cas,all[3000];
	scanf("%d",&cas);
	for(int t=0;t<cas;t++)
	{
		int n;
		m.clear();
		scanf("%d",&n);
		for(int i=0;i<(2*n-1)*n;i++)
		{
			int temp;
			scanf("%d",&temp);
			m[temp]++;
		}
		printf("Case #%d:",t+1);
		for(it=m.begin();it!=m.end();it++)
			if((*it).second%2!=0)
				printf(" %d",(*it).first);
		printf("\n");
	}
	return 0;
}
