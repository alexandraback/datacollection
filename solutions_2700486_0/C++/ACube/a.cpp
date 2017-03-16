#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)

typedef long long ll;
typedef double ld;

int	fx[] = {-1, 0, +1, 0}, fy[] = {0, +1, 0, -1},
	ex[] = {-1, -1, 0, +1, +1, +1, 0, -1}, ey[] = {0, +1, +1, +1, 0, -1, -1, -1};

using namespace std;

int test_num, case_number;

#define gout case_number++, printf("Case #%d: ",case_number), cout

const int mid = 1000;

int n, X, Y;
int amo, tot, was;
int d[2000];

void dfs(int u, int x, int was) {
	if (u == n) {
	 	amo += was; tot++;
	 	return;
	}

	if (d[x-1] >= d[x] && d[x+1] >= d[x]) {
		int v1 = d[x-1], v2 = d[x], v3 = d[x+1];
		if (x == X && d[x]+1 == Y) was = 1;
		d[x] += 2; d[x-1] = d[x]-1; d[x+1] = d[x]-1;
		dfs(u+1, mid, was);
		d[x-1] = v1; d[x] = v2; d[x+1] = v3;
		return;
	}

	if (d[x-1] < d[x]) {
		dfs(u, x-1, was);
	}
	if (d[x+1] < d[x]) {
	 	dfs(u, x+1, was);
	}
}

void main2()
{
	scanf("%d%d%d", &n, &X, &Y); X += mid;

	memset(d, -1, sizeof(d));
	tot = 0; amo = 0;
	dfs(0, mid, 0);
	gout;
	printf("%.7lf\n", 1.*amo/tot);
}

int main()
{
	scanf("%d", &test_num);

	for (int i = 0; i < test_num; i++)
		main2();

	return 0;
}
