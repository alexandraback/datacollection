#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int was[1500];
vector<int> a[1500];

bool rec(int x,int y,int K)
{
	if (was[x] == K) return true;
	was[x] = K;
	for (int i = 0; i < a[x].size(); i++)
	{
		if (a[x][i] == y) continue;
		if (rec(a[x][i],x,K)) return true;
	}
	return false;
};

int main()
{
	int T;
	scanf("%d",&T);	
	for (int T_t = 1; T_t <= T; T_t++)
	{
		printf("Case #%d: ",T_t);
  		int n;
	        scanf("%d",&n);
		for (int i = 0; i < n; i++)
			a[i].clear();
		for (int i = 0; i < n; i++)
		{
			int m;
			scanf("%d",&m);
			for (int j = 0; j < m; j++)
			{
				int x;
				scanf("%d",&x);
				x--;
				a[i].push_back(x);
			}
			was[i] = -1;
		}
		int o = 0;
		for (int i = 0; i < n; i++)
		{
			if (rec(i,-1,i)) { o = 1; printf("Yes\n"); break; }
		}
		if (o == 0) printf("No\n");
	}

	return 0;	
}
