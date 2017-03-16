#include <cstdio>
#include <cstring>

int r,c,m,d,s;
char mp[55][55];
bool ans;
int test;

int main()
{
	freopen("C-small-attempt3.in","r",stdin);
	//freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&test);
	for (int T = 1; T <= test; T++)
	{
		scanf("%d%d%d",&r,&c,&m);
		memset(mp,0,sizeof mp);
		d = r * c - m;
		ans = true;
		s = c;
		if (r < s) s = r;
		if (s == 1)
		{
			for (int i = 0; i < d; i++) if (r > c) mp[i][0] = '.'; else mp[0][i] = '.';
			for (int i = d; i < r + c - 1; i++) if (r > c) mp[i][0] = '*'; else mp[0][i] = '*';
			mp[0][0] = 'c';
		} else
		if (s == 2)
		{
			if (d == 1)
			{
				for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) mp[i][j] = '*';
				mp[0][0] = 'c';
			} else
			if (d == 2 || d&1) ans = false; else
			{
				for (int i = 0; i < d / 2; i++)
					if (r > c) mp[i][0] = mp[i][1] = '.'; else
					mp[0][i] = mp[1][i] = '.';
				for (int i = d / 2; i < r + c - 2; i++)
					if (r > c) mp[i][0] = mp[i][1] = '*'; else
					mp[0][i] = mp[1][i] = '*';
				mp[0][0] = 'c';
			}
		} else
		if (d == 1)
		{
			for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) mp[i][j] = '*';
			mp[0][0] = 'c';
		} else
		if (d == 4 || d == 6 || d >= 8)
		{
			for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) mp[i][j] = '*';
			mp[0][1] = mp[1][0] = mp[1][1] = '.';
			mp[0][0] = 'c';
			int x = 2,y = 2;
			d -= 4;
			while (d >= 2 && (x < r || y < c))
			{
				d -= 2;
				if ((x < r) && (y == c || x < y))
				{
					mp[x][0] = mp[x][1] = '.';
					x++;
				} else
				{
					mp[0][y] = mp[1][y] = '.';
					y++;
				}
			//for (int i = 0; i < r; i++) puts(mp[i]); printf("%d\n",d);
			}
			//for (int i = 0; i < r; i++) puts(mp[i]); printf("%d\n",d);
			x = 2; y = 2;
			while (d)
			{
				//printf("%d %d\n",x,y);
				mp[x][y] = '.';
				y++;
				if (y == c)
				{
					x++; y = 2;
				}
				d--;
			}
		} else ans = false;
		printf("Case #%d:\n",T);
		if (!ans) puts("Impossible"); else
		{
			for (int i = 0; i < r; i++) puts(mp[i]);
			int x = 0;
			for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (mp[i][j] == '*')
				x++;
			//if (x != m) {printf("%d %d %d\n",r,c,m); while (1);}
		}
	}
}
