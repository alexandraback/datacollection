// time out!!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <utility>

#define MAX_STR_NUM 256
#define MAX_NUM 1024
#define MAX_2D 2 * 50

template <class T> T gcd(const T & a, const T & b) { if(b == 0) return a; else return gcd(b, a % b); }
template <class T> T lcm(const T & a, const T & b) { return a / gcd(a, b) * b; }
template <class T> T sign(const T & a) { return a < 0 ? -1 : 1; }
template <class T> T abs(const T & a) { return a * sign(a); }
template <class T> T max(const T & a, const T & b) { if(a > b) return a; else return b; }
template <class T> T min(const T & a, const T & b) { if(a < b) return a; else return b; }

typedef long long TLL;
typedef std::pair <TLL, TLL> PLL;

PLL fsABS(const PLL & p)
{
	return std::make_pair(p.first < 0 ? -p.first : p.first, p.second < 0 ? -p.second : p.second);
}

PLL fsADD(const PLL & p1, const PLL & p2)
{
	PLL p(p1.first * p2.second + p2.first * p1.second, p1.second * p2.second);
	TLL tgcd = gcd(abs(p.first), abs(p.second)) * (p.second < 0 ? -1 : 1);
	p.first /= tgcd;
	p.second /= tgcd;
	return p;
}

PLL fsMUL(const PLL & p1, const PLL & p2)
{
	return std::make_pair(p1.first * p2.first, p1.second * p2.second);
}

int fsCMP(const PLL & p1, const PLL & p2)
{
	return p1.first * p2.second - p1.second * p2.first;
}

char grids[MAX_NUM][MAX_NUM];
int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "D-small-attempt3.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	bool vp[MAX_2D + 1][MAX_2D + 1];
	memset(vp, 0, sizeof(vp));
	for (int i = 0; i <= MAX_2D; ++i)
		for (int j = i; j <= MAX_2D; ++j)
			if (gcd(i, j) == 1)
				vp[i][j] = vp[j][i] = true;

	int T, H, W, D;
	fscanf(input, "%d", &T);
	for (int i = 0; i < T; ++i)
	{
		int pR = -1, pC = -1, ret = 0;
		fscanf(input, "%d %d %d", &H, &W, &D);
		fgets(grids[0], MAX_NUM, input);
		for (int j = 0; j < H; ++j)
		{
			fgets(grids[j], MAX_NUM, input);
			grids[j][W] = '\0';
			for (int k = 0; pR == -1 && k < W; ++k)
				if (grids[j][k] == 'X')
				{
					pR = j;
					pC = k;
				}
		}

		PLL bound(D * D * 4, 1);
		for (int dr = -D; dr <= D; ++dr)
			for (int dc = -D; dc <= D; ++dc)
				if ((dr || dc) && vp[abs(dr)][abs(dc)])
				{
//					printf("dr:%d dc:%d\n", dr, dc);
					int pos[2] = {pR, pC}, dir[2] = {dr, dc};
					PLL path[2], coord[2];
					path[0] = path[1] = PLL(0, 1);
					coord[0] = coord[1] = PLL(0, 1);
					bool search = true;
					while (search)
					{
						if (dir[0] == 0)
						{
							++path[1].first;
							coord[1].first += dir[1];
//							printf("pa:%lld %lld|%lld %lld\n", path[0].first, path[0].second, path[1].first, path[1].second);
						}
						else if (dir[1] == 0)
						{
							++path[0].first;
							coord[0].first += dir[0];
//							printf("pa:%lld %lld|%lld %lld\n", path[0].first, path[0].second, path[1].first, path[1].second);
						}
						else
						{
							PLL go[2], dirFS((TLL)dir[0], (TLL)dir[1]);
							for (int j = 0; j < 2; ++j)
							{
//								printf("cd:%lld %lld|", coord[j].first, coord[j].second);
								go[j].second = coord[j].second;
								if (dir[j] > 0)
								{
									if (coord[j].first < 0) go[j].first = -coord[j].first;
									else go[j].first = go[j].second - coord[j].first;
								}
								else
								{
									if (coord[j].first > 0) go[j].first = -coord[j].first;
									else go[j].first = -go[j].second - coord[j].first;
								}
//								printf("go:%lld %lld|", go[j].first, go[j].second);
							}
							
							int index = -1;
							if (fsCMP(fsABS(go[0]), fsABS(fsMUL(go[1], dirFS))) < 0) { index = 0; TLL ll = dirFS.first; dirFS.first = dirFS.second; dirFS.second = ll; }
							else { index = 1; }
//							printf("%d\n", index);
							coord[index] = fsADD(coord[index], go[index]);
							coord[1 - index] = fsADD(coord[1 - index], fsMUL(go[index], dirFS));
							path[index] = fsADD(path[index], fsABS(go[index]));
							path[1 - index] = fsADD(path[1 - index], fsABS(fsMUL(go[index], dirFS)));
						}

						if (fsCMP(fsADD(fsMUL(path[0], path[0]), fsMUL(path[1], path[1])), bound) > 0) break;

						if (coord[0].first == 0 && coord[1].first == 0)
						{
							if (pos[0] == pR && pos[1] == pC)
								search = false;
						}
						else if (abs(coord[0].first) == coord[0].second && abs(coord[1].first) == coord[1].second)
						{
							int up = (coord[0].first < 0 ? -1 : 1), left = (coord[1].first < 0 ? -1 : 1);
							if (grids[pos[0] + up][pos[1] + left] == '#')
							{
								if (grids[pos[0] + up][pos[1]] != '#' && grids[pos[0]][pos[1] + left] != '#')
								{
									break;
								}
								else if (grids[pos[0] + up][pos[1]] == '#' && grids[pos[0]][pos[1] + left] != '#')
								{
									pos[1] += left;
									dir[0] *= -1;
									coord[1].first *= -1;
								}
								else if (grids[pos[0] + up][pos[1]] != '#' && grids[pos[0]][pos[1] + left] == '#')
								{
									pos[0] += up;
									dir[1] *= -1;
									coord[0].first *= -1;
								}
								else
								{
									dir[0] *= -1;
									dir[1] *= -1;
								}
							}
							else
							{
								pos[0] += up;
								pos[1] += left;
								coord[0].first *= -1;
								coord[1].first *= -1;
							}
						}
						else if (abs(coord[0].first) == coord[0].second)
						{
							int up = (coord[0].first < 0 ? -1 : 1);
							if (grids[pos[0] + up][pos[1]] == '#')
							{
								dir[0] *= -1;
							}
							else
							{
								pos[0] += up;
								coord[0].first *= -1;
							}
						}
						else if (abs(coord[1].first) == coord[1].second)
						{
							int left = (coord[1].first < 0 ? -1 : 1);
							if (grids[pos[0]][pos[1] + left] == '#')
							{
								dir[1] *= -1;
							}
							else
							{
								pos[1] += left;
								coord[1].first *= -1;
							}
						}
					}
					ret += !search;
//					printf("=:%d\n", ret);
				}
		printf("Case #%d: %d\n", i + 1, ret);
		fprintf(output, "Case #%d: %d\n", i + 1, ret);
	}

	fclose(output);
	fclose(input);

//	system("pause");
	return 0;
}