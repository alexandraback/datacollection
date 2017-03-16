#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
using namespace std;
#define maxn 100000

int A, B;
double p[maxn];
double giveup, keep, back[maxn];
double con[maxn], ans[maxn];

void getkeep()
{
	int i;
	double pro = 1;
	for (i = 0; i < A; ++i)
		pro *= p[i];
	keep = pro * (B - A + 1) + (1 - pro) * (2 * B - A + 2);
}

void init()
{
	int i;
	con[0] = p[0];
	for (i = 1; i < A; ++i) {
		con[i] = con[i - 1] * p[i];
		//printf("%.6f\n", con[i]);
	}
}

double getback()
{
	int i;
	double mini = 100000000;
	for (i = 1; i < A; ++i) 
		ans[i - 1] = con[A - i - 1] * (B - A + 2 * i + 1) + (1 - con[A - i - 1]) * (2 * i + 2 * B - A + 2);
	ans[i - 1] = A + B + 1;
	for (i = 0; i < A; ++i)
		if (ans[i] < mini) mini = ans[i];
	return mini;
}

int main()
{
	freopen("A-small-attempt0.in.txt", "r", stdin);
	freopen("aout.txt", "w", stdout);
	int i, t, c = 0;
	double mini, tmp;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &A, &B);
		for (i = 0; i < A; ++i)
			scanf("%lf", &p[i]);
		giveup = B + 2;
		init();
		getkeep();
		mini = getback();
		printf("Case #%d: ", ++c);
		//printf("giveup = %.6f\n", giveup);
		//printf("keep = %.6f\n", keep);
		//printf("mini = %.6f\n", mini);
		printf("%.6f\n", min(giveup, min(keep, mini)));
	}
	return 0;
}
