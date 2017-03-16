#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <ctime>

using namespace std;

#define maxn 110
#define datat int
#define ansdatat int

int n;

int f[20][20], v[maxn];

void init_deal(){
}

int main(){
	
	int tttt;
	scanf("%d", &tttt);
	for(int ttt = 1;ttt<=tttt;ttt++){
		printf("Case #%d: ",ttt);

		int e,r;
		scanf("%d%d%d", &e, &r, &n);
		memset(f, 0, sizeof(f));

		f[0][e] = 1;
		int ans = 0;

		for (int i = 1; i<=n; i++)
		{
			scanf("%d", &v[i]);
		}

		for (int i = 0; i<=n-1; i++)
		for (int j = 0; j<=e; j++)
		if(f[i][j] > 0)
		{
			for (int k = 0; k<=j; k++)
			{
				int n_e = min(j-k+r,e);
				if(f[i+1][n_e] < f[i][j] + k*v[i+1])
				   f[i+1][n_e] = f[i][j] + k*v[i+1];
			}
		}

		for (int j = 0; j<=e; j++)
		if( ans < f[n][j]-1)
		{
			ans = f[n][j]-1;
		}

		printf("%d\n", ans);

	}
	

	return 0;
};

