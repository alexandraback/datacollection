#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
void solve()
{
	int R,C,M;
	scanf("%d%d%d", &R, &C, &M);
	if(C == 1 || R == 1)
	{
		if(R * C == M) puts("Impossible");
		else
		{
			int K = R * C - M - 1;
			putchar('c');
			for(int r = 0; r < R; r ++)
			{
				for(int c = (r == 0); c < C; c ++)
					if(K > 0) putchar('.'), K --;
					else putchar('*');
				puts("");
			}
		}
	}
	else
	{
		M = R * C - M;
		if(M < 4)
		{
			if(M != 1)
				puts("Impossible");
			else
			{
				for(int r = 0; r < R; r ++)
				{
					for(int c = 0; c < C; c ++)
						if(r == R -1 && c == C - 1)
							putchar('c');
						else 
							putchar('*');
					puts("");
				}
			}
		}
		else
		{
			bool found = false;
			int rem, r , c;
			for(rem = 2; rem <= C; rem ++)
				for(c = rem; c <= C; c ++)
					if((M - rem)%c == 0 && M / c > 1 && (M - rem)/c < R)
					{
						found = true, r = (M - rem)/c;
						goto F1;
					}
F1:
			if(!found)
			{
				rem = 1;
				for(c = 3; c <= C; c ++)
					if(M%c == 1 && M/c < R && M/c > 2)
					{
						found = true;
						r = M / c;
						break;
					}
			}
			if(found) 
			{
				r = R - r - 1;
				c = C - c;
				rem = C - rem;
				for(int rr = 0; rr < R; rr ++)
				{
					for(int cc = 0; cc < C; cc ++)
					{
						if(rr == R - 1 && cc == C - 1)
						{
							putchar('c');
						}
						else
						{
							if(rr < r) putchar('*');
							else if(rr == r)
							{
								if(rem == C - 1 && cc >= C-2) putchar('.');
								else if(cc >= rem) putchar('.');
								else putchar('*');
							}
							else if(rem == C - 1 && cc == c && rr == r + 1) putchar('*');
							else if(cc >= c) putchar('.');
							else putchar('*');
						}
					}
					puts("");
				}
			}
			else
			{
				for(rem = 2; rem <= R; rem ++)
					for(r = rem; r <= R; r ++)
						if((M - rem)%r == 0 && M / r > 1 && (M-rem)/r < C)
						{
							found = true, c = (M - rem)/r;
							goto F2;
						}
F2:
				if(!found)
				{
					rem = 1;
					for(r = 3; r <= R; r ++)
						if(M%r == 1 && M/r < C && M/r > 2)
						{
							found = true;
							c = M / r;
							break;
						}
				}
				if(found)
				{
					r = R - r;
					c = C - c;
					rem = R - rem;
					for(int rr = 0; rr < R; rr ++)
					{
						for(int cc = 0; cc < C; cc ++)
						{
							if(rr == R - 1 & cc == C - 1)
							{
								putchar('c');
							}
							else
							{
								if(rr < r) putchar('*');
								else
								{
									if(rem == R - 1 && rr == rem-1 &&  cc == c - 1) putchar('.');
									else if(rem == R - 1 && cc == c && rr == r ) putchar('*');
									else if((rr >= rem) + cc >= c) putchar('.');
									else putchar('*');
								}
							}
						}
						puts("");
					}
				}
			}
			if(!found) puts("Impossible");

		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i ++)
	{
		printf("Case #%d:\n", i + 1);
		solve();
	}
}
