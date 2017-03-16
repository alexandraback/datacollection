#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;


int p1[1001];
int p2[1001];

int st[1001];

int main()
{
	int t;
	scanf("%d", &t);
	for(int it=1;it<=t;it++)
	{
		int ans = 0;
		int N;
		scanf("%d", &N);
		memset(st, 0, sizeof(int)*N);
		for(int i=0; i<N; i++)
			scanf("%d %d",&p1[i], &p2[i]);
		int cs = 0;
		bool g = true;
		while(cs < 2*N && g)
		{
			g = false;
			for(int i=0; i<N; i++)
			{
				if(st[i]<2 && p2[i]<=cs){
					g = true;
					cs += 2-st[i];
					st[i] = 2;
					ans++;
				}
			}
			if(!g){
				int bid = -1;
				int bp = -1;
				for(int i=0; i<N; i++)
				{
					if(st[i] == 0 && p1[i]<=cs && p2[i]>bp){
						bid = i;
						bp = p2[i];
					}
				}
				if(bid != -1)
				{
					st[bid] = 1;
					ans++;
					cs++;
					g = true;
				}
			}
		}
		if(cs == 2*N)
			printf("Case #%d: %d\n",it, ans);
		else
			printf("Case #%d: Too Bad\n",it);
	}
	return 0;
}
