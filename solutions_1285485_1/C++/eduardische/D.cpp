#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define MAXN 105

using namespace std;

struct node
{
	int x, y;

    bool operator<(const node& p) const
    {
        return ((x * p.y - y * p.x) < 0);
    }
};

int GetVec (struct node a, struct node b)
{
	return a.x * b.y - a.y * b.x;
}

double GetDist (int sx, int sy, int fx, int fy)
{
	return sqrt((long double)((fx - sx) * (fx - sx)) + (long double)((fy - sy) * (fy - sy)));
}

double GetDistD (double vx, double vy)
{
	return sqrt(vx * vx + vy * vy);
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static char a[MAXN][MAXN];
	static struct node srt[MAXN*MAXN];
	int srtc;
	static struct node d[MAXN*MAXN];
	int dc;
	for (iT = 0; iT < T; iT++)
	{
		int res = 0;
		int N, M, D;
		scanf("%d %d %d\n",&N,&M,&D);
		int i, j;
		for (i = 0; i < N; i++) scanf("%s\n",a[i]);
		int sx, sy, fx, fy;
		sx = 0; sy = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				if (a[i][j] == 'X')
				{
					sx = i;
					sy = j;
				}
			}
		}
		dc = 2;
		d[0].x = 0;
		d[0].y = 1;
		d[1].x = 0;
		d[1].y = -1;
		srtc = 0;
		for (fx = sx + 1; fx <= sx + D; fx++)
		{
			for (fy = sy - D; fy <= sy + D; fy++)
			{
				if (((fx != sx) || (fy != sy)) && ((GetDist(sx,sy,fx,fy) - 1E-9) <= (long double)(D)))
				{
					srt[srtc].x = fx - sx;
					srt[srtc].y = fy - sy;
					srtc++;
				}
			}
		}
		sort(&(srt[0]),&(srt[srtc]));
		for (i = 0; i < srtc; i++)
		{
			//printf("%d %d\n",srt[i].x,srt[i].y);
			if ((i == 0) || (GetVec(srt[i], srt[i-1]) != 0))
			{
				d[dc] = srt[i];
				dc++;
			}
		}
		srtc = 0;
		for (fx = sx - D; fx <= sx - 1; fx++)
		{
			for (fy = sy - D; fy <= sy + D; fy++)
			{
				if (((fx != sx) || (fy != sy)) && ((GetDist(sx,sy,fx,fy) - 1E-9) <= (long double)(D)))
				{
					srt[srtc].x = fx - sx;
					srt[srtc].y = fy - sy;
					srtc++;
				}
			}
		}
		sort(&(srt[0]),&(srt[srtc]));
		for (i = 0; i < srtc; i++)
		{
			if ((i == 0) || (GetVec(srt[i], srt[i-1]) != 0))
			{
				d[dc] = srt[i];
				dc++;
			}
		}

		for (i = 0; i < dc; i++)
		{
			long double x, y, finx, finy;
			long double vx, vy;
			vx = (long double)(d[i].x); vy = (long double)(d[i].y);
			//printf("%.6lf %.6lf\n",(double)vx,(double)vy);
			x = (long double)(sx) - 0.5;
			y = (long double)(sy) - 0.5;
			finx = x; finy = y;
			long double T = 0.0;
			while ((T - 1E-9) <= (long double)(D))
			{
				if ((T > 0.5) && (fabs(finx - x) <= 1E-9) && (fabs(finy - y) <= 1E-9))
				{
					res++;
					//printf("%d %d @ (%.3lf; %.3lf) for %.3lf\n",d[i].x,d[i].y,(double)(x),(double)(y),(double)(T));
					break;
				}
				long double ta, tb, tres;
				ta = 1E10; tb = 1E10;
				long double bx, by;
				if (vx > 1E-9)
				{
					bx = ceil(x * 2.0 + 1E-7) / 2.0;
					ta = (bx - x) / (double)(vx);
				}
				else if (vx < -1E-9)
				{
					bx = floor(x * 2.0 - 1E-7) / 2.0;	
					ta = (bx - x) / (double)(vx);
				}
				if (vy > 1E-9)
				{
					by = ceil(y * 2.0 + 1E-7) / 2.0;
					tb = (by - y) / (double)(vy);
				}
				else if (vy < -1E-9)
				{
					by = floor(y * 2.0 - 1E-7) / 2.0;
					tb = (by - y) / (double)(vy);
				}
				if (ta < tb) tres = ta;
				else tres = tb;
				//printf("(%.6lf; %.6lf) -> %.6lf\n",(double)(x), (double)(y), (double)(tres));
				x += vx * tres;
				y += vy * tres;
				T += (tres * GetDistD(vx, vy));
				//if ((d[i].x == 2) && (d[i].y == 5)) printf("(%.6lf; %.6lf)\n",(double)x,(double)y);
				//printf("(%.6lf; %.6lf)\n",(double)x,(double)y);
				bool OKx, OKy;
				int X, Y;
				OKx = ((fabs(x - floor(x + 1E-7))) <= 1E-9);
				OKy = ((fabs(y - floor(y + 1E-7))) <= 1E-9);
				//printf("%d %d\n",(int)OKx,(int)OKy);
				bool decided = false;
				int cnt;
				//if ((d[i].x == 2) && (d[i].y == 5)) printf(">> %d %d\n",(int)(OKx),(int)(OKy));
				if ((OKx) && (OKy))
				{
					X = (int)(x + 0.25);
					Y = (int)(y + 0.25);
					cnt = 0;
					if (a[X][Y] == '#') cnt++;
					if (a[X][Y+1] == '#') cnt++;
					if (a[X+1][Y] == '#') cnt++;
					if (a[X+1][Y+1] == '#') cnt++;
					struct node to;
					if ((vx >= 0.0) && (vy >= 0.0))
					{
						//from.x = X; from.y = Y;
						to.x = X+1; to.y = Y+1;
					}
					else if ((vx >= 0.0) && (vy < 0.0))
					{
						//from.x = X; from.y = Y+1;
						to.x = X+1; to.y = Y;
					}
					else if ((vx < 0.0) && (vy >= 0.0))
					{
						to.x = X; to.y = Y+1;
						//from.x = X+1; from.y = Y;
					}
					else
					{
						to.x = X; to.y = Y;
						//from.x = X+1; from.y = Y+1;
					}
					if (a[to.x][to.y] == '#')
					{
						if (cnt == 1) break;
						else if (cnt == 3)
						{
							vx *= -1.0;
							vy *= -1.0;
							decided = true;
						}
					}
					else
					{
						decided = true;
					}
				}
				if (!decided)
				{
					if (OKx)
					{
						X = (int)(x + 0.25);
						if (vx >= 0.0) X++;
						if (vy >= 0.0) Y = (int)(ceil(y - 1E-7) + 1E-7);
						else Y = (int)(ceil(y + 1E-7) + 1E-7);
						if (a[X][Y] == '#')
						{
							vx *= -1.0;
							decided = true;
						}
					}
					if ((!decided) && (OKy))
					{
						Y = (int)(y + 0.25);
						if (vy >= 0.0) Y++;
						if (vx >= 0.0) X = (int)(ceil(x - 1E-7) + 1E-7);
						else X = (int)(ceil(x + 1E-7) + 1E-7);
						//if ((d[i].x == 2) && (d[i].y == 5)) printf("%d %d\n",X,Y);
						if (a[X][Y] == '#') vy *= -1.0;
					}
				}
			}
			//printf("%d %d @ (%.3lf; %.3lf) for %.3lf\n",d[i].x,d[i].y,(double)(x),(double)(y),(double)(T));
		}

		printf("Case #%d: %d\n",iT+1,res);
	}
}
