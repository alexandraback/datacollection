#include<cstdio>
#include<queue>

using namespace std;

char map[64][64];
int r, c, m, e;

typedef struct POINT
{
	int r, c;
	int pr;
	void set(int x, int y)
	{
		r = x;
		c = y;
		pr = rand();
	}
}Point;

bool operator<(Point a, Point b)
{
	return a.pr < b.pr;
}

int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void Show()
{
	int i, j;
	for(i = 0; i < r; i ++)
	{
		map[i][c] = '\0';
		puts(map[i]);
	}
}

void Init()
{
	int i, j;
	//memset(map, 0, sizeof(map));
	for(i = 0; i < r; i ++)
	{
		for(j = 0; j < c; j ++)
		{
			map[i][j] = '*';
		}
	}
}

bool valid(Point p)
{
	if(p.r < 0 || p.r >= r)return false;
	if(p.c < 0 || p.c >= c)return false;
	
	if(map[p.r][p.c] != '*')return false;
	
	//printf("r = %d c = %d (%d,%d) valid!\n", r, c, p.r, p.c);
	return true;
}

bool BFS()
{
	Point p;
	priority_queue<Point> Q;
	
	p.set(0,0);
	map[0][0] = '.';
	Q.push(p);
	
	int i, Count = 1;
	
	while(!Q.empty())
	{
		Point q = Q.top();
		//Show();
		//printf("%d %d %d %d\n", q.r, q.c, Count, e);
		Q.pop();
		
		int tmp = 0;
		for(i = 0; i < 8; i ++)
		{
			p.r = q.r + dir[i][0];
			p.c = q.c + dir[i][1];
			
			if(valid(p))tmp ++;
		}
		
		if(Count+tmp <= e)
		{
			for(i = 0; i < 8; i ++)
			{
				p.r = q.r + dir[i][0];
				p.c = q.c + dir[i][1];
			
				if(valid(p))
				{
					map[p.r][p.c] = '.';
					p.pr = rand();
					Q.push(p);
					Count ++;
				}
			}
		}
		else 
		{
			//printf("Count = %d tmp = %d e = %d\n", Count, tmp, e);
		}
		if(Count == e)return true;
	}
	return false;
}

int main()
{
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		
		scanf("%d%d%d", &r, &c, &m);
		e = r*c-m;
		
		Init();
		int i, j;
		
		printf("Case #%d:\n", cas);
		/*
		if(r == 1)
		{
			for(i = 0; i < e; i ++)
			{
				map[0][i] = '.';
			}
			map[0][0] = 'c';
			Show();
			continue;
		}
		
		if(c == 1)
		{
			for(i = 0; i < e; i ++)
			{
				map[i][0] = '.';
			}
			map[0][0] = 'c';
			Show();
			continue;
		}
		*/
		if(e == 1)
		{
			map[0][0] = 'c';
			Show();
			continue;
		}
		
		for(i = 0; i < 20; i ++)
		{
			Init();
			if(BFS())
			{
				map[0][0] = 'c';
				Show();
				break;
			}
		}
		
		if(i == 20)
		{
			puts("Impossible");
		}
	}
	return 0;
}
