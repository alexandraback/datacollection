#include <cstdio>
#include <cstring>
#include <algorithm>
// 0, 1, 2, 3,  4,  5,  6,  7
// 1, i, j, k, -1, -i, -j, -k
const int mul[8][8] = {
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 4, 3, 6, 5, 0, 7, 2},
	{2, 7, 4, 1, 6, 3, 0, 5},
	{3, 2, 5, 4, 7, 6, 1, 0},
	{4, 5, 6, 7, 0, 1, 2, 3},
	{5, 0, 7, 2, 1, 4, 3, 6},
	{6, 3, 0, 5, 2, 7, 4, 1},
	{7, 6, 1, 0, 3, 2, 5, 4}
};

int getID(char p)
{
	if(p == '1') return 0;
	if(p == 'i') return 1;
	if(p == 'j') return 2;
	if(p == 'k') return 3;
}

const int N = 10000 + 10;

long long n, m;
int a[N], single;

int pow(int x, int y)
{
	if(y == 0) return getID('1');
	if(y & 1) return mul[pow(mul[x][x], y / 2)][x];
	return pow(mul[x][x], y / 2);
}

bool solve()
{
	int op_find = 1;
	int nowI = 0, nowJ = 0, nowK = 0;
	for(long long i = 1; i <= std::min(m, 10ll); i++)
		for(long long j = 1; j <= n; j++)
		{
			if(op_find == 1)
			{ // find I
				nowI = mul[nowI][a[j]];
				if(nowI == 1) op_find++;
			}
			else if(op_find == 2)
			{ // find J
				nowJ = mul[nowJ][a[j]];
				if(nowJ == 2) op_find++;
			}
			else { // calc K
				for(int k = j; k <= n; k++)
					nowK = mul[nowK][a[k]];
				nowK = mul[nowK][pow(single, m - i)];
				return nowK == 3;
			}
		}
	return 0;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%lld%lld", &n, &m);
		single = 0;
		for(int i = 1; i <= n; i++)
		{
			char ch; scanf(" %c", &ch);
			a[i] = getID(ch);
			single = mul[single][a[i]];
		}
		if(solve()) printf("Case #%d: YES\n", cas);
		else printf("Case #%d: NO\n", cas);
	}
	return 0;
}
