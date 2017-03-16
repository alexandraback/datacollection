#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std ;

const int MAXN = 100;

int rowMax[MAXN+5];
int colMax[MAXN+5];
int grid[MAXN+5][MAXN+5];
int n,m;


int main()
{
	freopen("lawnmower.in","r",stdin);
	freopen("lawnmower.out","w",stdout);
	int c,c2;
	int tests;
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++){
		scanf("%d%d",&n,&m);
		for (c=0;c<n;c++)
			for (c2=0;c2<m;c2++)
				scanf("%d",&grid[c][c2]);
		for (int i=0;i<n;i++){
			rowMax[i] = grid[i][0];
			for (int j=1;j<m;j++)
				rowMax[i] = max(rowMax[i], grid[i][j]);
		}
		for (int j=0;j<m;j++){
			colMax[j] = grid[0][j];
			for (int i=1;i<n;i++)
				colMax[j] = max(colMax[j], grid[i][j]);
		}
		bool yes=1;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (colMax[j] > grid[i][j] && rowMax[i] > grid[i][j])
					yes=0;
		printf("Case #%d: ",test);
		if (yes)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}


