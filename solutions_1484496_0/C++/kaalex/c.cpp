//Aleksander "kaalex" Kramarz

#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <map>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#define x first
#define y second
using namespace std;

int z, n, val[1000];
vector<pair<int,int> > V;

int main()
{
	scanf("%d",&z);
	for(int f = 1; f <= z; f++)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d",val+i);
		for(int i = 1; i < 1<<n; i++)
		{
			int v = 0;
			for(int j = 0; j < n; j++)
				if((1<<j)&i)
					v += val[j];
			V.push_back(make_pair(v,i));
		}
		sort(V.begin(),V.end());
		printf("Case #%d:\n", f);
		bool c = 0;
		for(int i = 1; i < V.size(); i++)
		{
			if(V[i].x == V[i-1].x)
			{
				for(int j = 0; j < n; j++)
					if(V[i].y & (1<<j))
						printf("%d ", val[j]);
				printf("\n");
				for(int j = 0; j < n; j++)
					if(V[i-1].y & (1<<j))
						printf("%d ", val[j]);
				c = 1;
				printf("\n");
				break;
			}
		}
		if(!c)
			printf("Impossible\n");
		V.clear();
	}
}
