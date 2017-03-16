#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int D[][2] = {{0,1},{1,0},{0,-1},{-1,0},{1,1}, {1,-1}, {-1,-1}, {-1,1}};
bool map[18][18];
int R,C,M;
int CR, CC;
static inline int count(int r, int c)
{
	int ret = 0;
	for(int i = 0; i < 8; i ++)
	{
		int rr = r + D[i][0];
		int cc = c + D[i][1];
		if(rr < 0 || rr >= R) continue;
		if(cc < 0 || cc >= C) continue;
		if(map[rr][cc]) ret ++;
	}
	return ret;
}
bool check()
{
	static int F[18][18] = {};
	static int TRUE = 0;
	for(int r = 0; r < R; r ++)
		for(int c = 0; c < C; c ++)
		{
			if(map[r][c]) continue;
			TRUE ++;
			int Q[80][2];
			int front = 0, rear = 1;
			Q[0][0] = r;
			Q[0][1] = c;
			int cnt = 1;
			F[r][c] = TRUE;
			while(front < rear)
			{
				int cr = Q[front][0];
				int cc = Q[front][1];
				front ++;
				if(count(cr,cc) == 0)
				{
					for(int i = 0; i < 8; i ++)
					{
						int nr = cr + D[i][0];
						int nc = cc + D[i][1];
						if(nr < 0 || nr >= R) continue;
						if(nc < 0 || nc >= C) continue;
						if(F[nr][nc] == TRUE) continue;
						Q[rear][0] = nr;
						Q[rear][1] = nc;
						F[nr][nc] = TRUE;
						rear ++;
						cnt ++;
					}

				}
			}
			CR = r;
			CC = c;
			if(cnt == R * C - M) return true;
		}
	return false;
}
bool search(int m, int r = 0, int c = 0)
{
	if(m == 0)
	{
		if(check())
		{
			for(int i = 0; i < R; i ++)
			{
				for(int j = 0; j < C; j ++)
				{
					if(map[i][j])putchar('*');
					else if(i == CR && j == CC) putchar('c');
					else putchar('.');
					if(j == C-1)  putchar('\n');
				}
			}
			return true;
		}
	}
	int nc = c + 1;
	int nr = r;
	if(nc == C) nc = 0, nr ++;
	if(nr == R) return false;
	if(search(m, nr, nc)) return true;
	map[r][c] = true;
	if(search(m-1, nr, nc)) return true;
	map[r][c] = false;
	return false;
}
void solve()
{
	scanf("%d%d%d", &R,&C,&M);
	memset(map, 0, sizeof(map));
	if(!search(M)) puts("Impossible!");
}
int main()
{
	/*int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i ++)
	{
		printf("Case #%d:\n", i + 1);
		solve();
	}*/
	for(R = 1; R <= 5; R ++)
		for(C = 1; C <= 5; C ++)
			for(M = 0; M <= R * C; M ++)
			{
				printf("%d %d %d\n", R, C, M);
				if(!search(M)) puts("Impossible");
			}
	return 0;
}
/*
 * python code

from sys import stdout
fin = file("data.txt")
data = {}
while True:
	L = fin.readline()
	if not L: break
	r,c,m = map(int, L.strip().split())
	ans = ""
	for k in range(r):
		L = fin.readline().strip()
		ans += L + "\n"
		if L == "Impossible": break
	data[(r,c,m)] = ans
T = int(raw_input().strip())
for i in range(1, T + 1):
	R,C,M = map(int, raw_input().strip().split())
	stdout.write("Case #%d:\n%s"%(i,data[(R,C,M)]))


 */
