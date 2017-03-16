#include <stdio.h>
#include <string.h>
#define N 10100
char seq[N];
int t, l, map[5][5] = {{},
					   {0, 1, 2, 3, 4},
					   {0, 2, -1, 4, -3},
					   {0, 3, -4, -1, 2},
					   {0, 4, 3, -2, -1}};
long long x;
int getval(char c)
{
	if(c == 'i') return 2;
	else if(c == 'j') return 3;
	else return 4;
}
int main()
{
	FILE *fpi = fopen("./C-large.in", "r");
	FILE *fpo = fopen("./C-large.out", "w");
	fscanf(fpi, "%d", &t);
	for(int c = 1; c <= t; ++c)
	{
		fscanf(fpi, "%d %lld", &l, &x);
		fscanf(fpi, "%s", seq);
		int rst = 1, fh = 1, ans = 0;
		for(int i = 0; i < l; ++i)
		{
			rst = map[rst][getval(seq[i])];
			rst *= fh;
			if(rst < 0) fh = -1, rst *= -1;
			else fh = 1;
		}
		if((rst * fh == -1 && x % 2) || (rst != 1 && !(x % 2) && x % 4))
		{
			int lft = 1, lfh = 1, ll = -1;
			for(int i = 0; i < l; ++i)
			{
				lft = map[lft][getval(seq[i])];
				lft *= lfh;
				if(lft < 0) lfh = -1, lft *= -1;
				else lfh = 1;
				int lsv = lft, lsf = lfh;
				for(int j = 0; j < 4; ++j)
				{
					if(lsf == 1 && lsv == 2)
					{
						int lsl = i + 1 + j * l;
						if(ll == -1 || ll > lsl)
						  ll = lsl;
						break;
					}
					lsv = map[rst][lsv];
					lsf *= fh;
					lsv *= lsf;
					if(lsv < 0) lsf = -1, lsv *= -1;
					else lsf = 1;
				}
			}
			int rgt = 1, rfh = 1, rr = -1;
			for(int i = l - 1; i >= 0; --i)
			{
				rgt = map[getval(seq[i])][rgt];
				rgt *= rfh;
				if(rgt < 0) rfh = -1, rgt *= -1;
				else rfh = 1;
				int lsv = rgt, lsf = rfh;
				for(int j = 0; j < 4; ++j)
				{
					if(lsf == 1 && lsv == 4)
					{
						int lsl = (l - i) + j * l;
						if(rr == - 1 || rr > lsl)
						  rr = lsl;
						break;
					}
					lsv = map[lsv][rst];
					lsf *= fh;
					lsv *= lsf;
					if(lsv < 0) lsf = -1, lsv *= -1;
					else lsf = 1;
				}
			}
			if(ll == -1 || rr == -1) ans = 0;
			else if(ll / l + rr / l >= x) ans = 0;
			else if(ll / l + rr / l == x - 1 && ll % l + rr % l >= l) ans = 0;
			else ans = 1;
		}
		if(ans == 1) fprintf(fpo, "Case #%d: YES\n", c);
		else fprintf(fpo, "Case #%d: NO\n", c);
	}
	return 0;
}
