#include<cstdio>
#include<cstring>

const int N = 128;

int n, m;
int map[N][N];

bool con[4][N][N];

void CheckLeft(bool left[N][N])
{
	int i, j, mx;
	for(i = 0; i < n; i ++)
	{
		left[i][0] = true;
		mx = map[i][0];
		for(j = 1; j < m; j ++)
		{
			if(map[i][j] >= mx)
			{
				left[i][j] = true;
				mx = map[i][j];
			}
			else 
			{
				left[i][j] = false;
			}
		}
	}
}

void CheckRight(bool right[N][N])
{
	int i, j, mx;
	for(i = 0; i < n; i ++)
	{
		right[i][m-1] = true;
		mx = map[i][m-1];
		for(j = m-2; j >= 0; j --)
		{
			if(map[i][j] >= mx)
			{
				right[i][j] = true;
				mx = map[i][j];
			}
			else 
			{
				right[i][j] = false;
			}
		}
	}
}

void CheckTop(bool top[N][N])
{
	int i, j, mx;
	for(i = 0; i < m; i ++)
	{
		top[0][i] = true;
		mx = map[0][i];
		for(j = 1; j < n; j ++)
		{
			if(map[j][i] >= mx)
			{
				top[j][i] = true;
				mx = map[j][i];
			}
			else 
			{
				top[j][i] = false;
			}
		}
	}
}

void CheckBottom(bool bottom[N][N])
{
	int i, j, mx;
	for(i = 0; i < m; i ++)
	{
		bottom[n-1][i] = true;
		mx = map[n-1][i];
		for(j = n-2; j >= 0; j --)
		{
			if(map[j][i] >= mx)
			{
				bottom[j][i] = true;
				mx = map[j][i];
			}
			else 
			{
				bottom[j][i] = false;
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	
	int Case;
	for(Case = 1;  Case <= T; Case ++)
	{
		int i, j, k;
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i ++)
		{
			for(j = 0; j < m; j ++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		CheckLeft(con[0]);
		CheckRight(con[1]);
		CheckTop(con[2]);
		CheckBottom(con[3]);
		
		bool ok = true;
		for(i = 0; i < n; i ++)
		{
			for(j = 0; j < m; j ++)
			{
				bool ok1 = (con[0][i][j] && con[1][i][j]);
				bool ok2 = (con[2][i][j] && con[3][i][j]);
				if(ok1 == false && ok2 == false)
				{
					ok = false;
					//printf("%d %d %d %d\n", i, j, ok1, ok2);
				}
			}
		}
		
		char Ans[8];
		if(ok)
		{
			strcpy(Ans, "YES");
		}
		else 
		{
			strcpy(Ans, "NO");
		}
		printf("Case #%d: %s\n", Case, Ans);
	}
	return 0;
}
