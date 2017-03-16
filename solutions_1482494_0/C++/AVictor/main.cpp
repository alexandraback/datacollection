#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<iomanip>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<memory.h>
#include<iomanip>
using namespace std;

typedef pair<int,int> ii;

const int size = 1005;
int N;
int a[size], b[size];
int todo[size];

int main()
{
	int T;
	cin>>T;
	for(int test=1;test<=T;test++)
	{
		cin>>N;
		set< ii > x2;
		for(int i=0;i<N;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			todo[i]=0;
			x2.insert(ii(b[i], i));
		}

		int M = 0;
		int x = 0;
		bool change = true;
		while(change)
		{
			change=false;
			while(!x2.empty())
			{
				set< ii >::iterator it = x2.begin();
				if (it->first<=x)
				{
					change=true;
					x+=2-todo[it->second];
					todo[it->second]=2;
					M++;
					x2.erase(it);
				}
				else
					break;
			}

			int best=-1;
			for(int i=0;i<N;i++)
			{
				if (todo[i]>0) continue;
				if (a[i]>x) continue;
				if (best==-1 || (b[best]<b[i])) best=i;
			}
			if (best>-1)
			{
				change=true;
				M++;
				x+=1;
				todo[best]=1;
			}
		}

		if (x<2*N)
			printf("Case #%d: Too Bad\n", test);
		else
			printf("Case #%d: %d\n", test, M);

	}
	
	return 0;
}