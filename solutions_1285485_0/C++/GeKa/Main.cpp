#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, D;
#define MAX 3010

int SX, SY;
bool or[MAX][MAX];
bool original[MAX][MAX];
bool matr[MAX][MAX];

int gcd(int a, int b)
{
	if (a < b)
		return gcd(b, a);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int sign(int a)
{
	return a == 0 ? 0 : a < 0 ? -1 : 1;
}

int change[16][2] = 
{
	{1,1},
	{0,0},
	{0,0},
	{1,-1},
	{0,0},
	{1,1},
	{-1,1},
	{-1, -1},
	{0,0},
	{-1,1},
	{1,1},
	{-1,-1},
	{1,-1},
	{-1,-1},
	{-1,-1},
	{0,0}
};

bool f(int h, int w)
{
	long long hm = abs(w);
	long long wm = abs(h);
	if (hm == 0)
		hm = 1;
	if (wm == 0)
		wm = 1;

	int x = SX * hm;
	int y = SY * wm;
	int tx = x;
	int ty = y;
	int dirs[4][2] = {{-1, -1}, {0, -1}, {0, 0}, {-1, 0}};
	h = sign(h);
	w = sign(w);
	int hh = abs(h);
	int ww = abs(w);
	long long cnt = 0;
	long long qq = (ww * hm * hm + hh * wm * wm);
	long long zz = hm * hm * wm * wm * D * D;
	while (true)
	{
		x = x + h;
		y = y + w;
		cnt++;
		if (cnt * cnt * qq > zz)
			break;
		if (x == tx && y == ty)
			return true;

		int mask = 0;
		for (int d = 0; d < 4; d++)
		{
			mask = mask << 1;
			int xx = x + dirs[d][0];
			int yy = y + dirs[d][1];
			mask = mask + (original[xx / hm][yy / wm] ? 1 : 0);			
		}
		h = h * change[mask][0];
		w = w * change[mask][1];
		if (x == 0 && y == 0)
			return false;
	}
	return false;
}


int main()
{	
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{		
		scanf("%d%d%d", &N, &M, &D);
		for (int i = 0; i < N; i++)
		{
			char s[100];
			scanf("%s", s);
			for (int j = 0; j < M; j++)
			{
				if (s[j] == 'X')
				{
					SX = i;
					SY = j;
				}
				or[i][j] = s[j] == '#';
			}
		}

		N *= 2;
		M *= 2;
		D *= 2;
		SX = SX * 2 + 1;
		SY = SY * 2 + 1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				original[i][j] = or[i/2][j/2];



		int res = 0;

		if (f(0, 1))
			res++;
		if (f(0, -1))
			res++;
		if (f(1, 0))
			res++;
		if (f(-1, 0))
			res++;


		for (int i = 1; i <= D; i++)
			for (int j = 1; j <= D; j++)
				if (i*i + j*j <= D*D)
					if (gcd(i, j) == 1)
					{
						if (f(i, j))
							res++;
						if (f(i, -j))
							res++;
						if (f(-i, j))
							res++;
						if (f(-i, -j))
							res++;
						
					}

		res = res + 0;
		printf("Case #%d: %d\n", t+1, res);
	}

	return 0;
}