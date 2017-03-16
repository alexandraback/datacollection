#include <cstdio>
#include <cstring>

int map[1010][1010];
int mp[1010][1010];
int ans,as;
int n,m,k;

void check(int x,int y)
{
	map[x][y] = -1;
	int a = ans - 1;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (map[i][j] == 0)
	{
		if (map[i - 1][j] == -1 || map[i + 1][j] == -1 || map[i][j - 1] == -1 || map[i][j + 1] == -1)
			a++;
	}
	if (a < as)
	{
		as = a;
		memcpy(mp,map,sizeof map);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (mp[i][j] == 0)
		{
			if (mp[i - 1][j] == -1 || mp[i + 1][j] == -1 || mp[i][j - 1] == -1 || mp[i][j + 1] == -1)
				mp[i][j] = 1;
		}
	}
	map[x][y] = 1;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	int test; scanf("%d",&test);
	for (int T = 1; T <= test; T++)
	{
		scanf("%d%d%d",&n,&m,&k);
		k = n * m - k;
		memset(map,0,sizeof map);
		ans = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
			map[i][j] = 1,ans++;
		//printf("%d\n",ans);
		while (k)
		{
			k--;
			as = ans + 10;
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (map[i][j] == 1) check(i,j);
			if (as < ans) ans = as;
			memcpy(map,mp,sizeof mp);
			//for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) printf("% 2d%c",map[i][j],j == m - 1 ? '\n' : ' ');
			//printf("%d\n",as);
		}
		printf("Case #%d: %d\n",T,ans);
	}
}
