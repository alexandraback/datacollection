#include <cstdio>

const char *ans_str[]={
	"X won",
	"O won",
	"Draw",
	"Game has not completed"
};

char a[8][8];
int n = 4;

bool
go (int x, int y, char ch, int dx, int dy, int cnt)
{
	//printf ("%d %d %c %d %d %d\n",x,y,ch,dx,dy,cnt);
	if (x >= n || y >= n) return cnt == 4;
	if (a[x][y] == ch || a[x][y] == 'T')
		return go (x+dx, y+dy, ch, dx, dy, cnt+1);
	return cnt == 4;
}

int
main ()
{
	freopen ("As.in","r",stdin);
	freopen ("As.out","w",stdout);
	int t;
	scanf ("%d", &t);
	
	for (int tc = 1; tc <= t; tc ++){
		for (int i = 0; i < n; i ++)
			scanf ("%s", a[i]);

		int ans = 3;
		int cnt_empty = 0;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++){
				if (go (i,j,'X',1,1,0) || go (i,j,'X',1,0,0) || go (i,j,'X',0,1,0) || go (i,j,'X',1,-1,0))
					ans = 0;
				if (go (i,j,'O',1,1,0) || go (i,j,'O',1,0,0) || go (i,j,'O',0,1,0) || go (i,j,'O',1,-1,0))
					ans = 1;
				if (a[i][j] == '.')
					cnt_empty ++;
			}
		if (ans == 3 && cnt_empty == 0)
			ans = 2;

		printf ("Case #%d: %s\n", tc, ans_str[ans]);
	}
	return 0;
}