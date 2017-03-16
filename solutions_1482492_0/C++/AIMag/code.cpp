#include <iostream>
#include <memory.h>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

struct item {
	item *L, *R;
	int val, pr, cnt;
	item(int _val, int _pr) {
		val = _val; pr = _pr;
	}
};

typedef item* pitem;

void reCalc(pitem& root)
{
	if (!root) return;
}

void merge(pitem& T, pitem L, pitem R)
{
	if (!L) T = R; else
		if (!R) T = L; else
			if (L->pr > R->pr) {
				merge(L->R, L->R, R); T = L;
			}
			else {
				merge(R->L, L, R->L); T = R;
			}
	reCalc(R);
}

void printTree(pitem& root)
{
	if (!root) return;
	printTree(root->L);
	printf("%d ", root->val);
	printTree(root->R);
}

int N, A;
double T[2222], X[2222];
double a[512], D;

double Calc(double g)
{
	double XX = 0;
	double v0 = 0;
	double TT = 0;
	FOR(i, 1, N-1)
	{
		double dt = T[i]-T[i-1];
		double S = v0*dt + 0.5*g*dt*dt;
		if (XX+S > X[i]) {
			v0 = max((X[i]-X[i-1])/(T[i]-T[i-1]), sqrt(2.0*g*(X[i]-XX))); XX = X[i];
		}
		else {
			XX = XX+S;
			v0 += dt*g;
		}
		TT = TT+dt;
	}
	double A = 0.5*g;
	double B = v0;
	double C = XX-D;
	double DD = B*B-4.0*A*C;

	double tt = (-B+sqrt(DD))/(2.0*A);

	double V = (X[N-1]-X[N-2])/(T[N-1]-T[N-2]);
	double t2 = (D-X[N-2])/V;

	return TT+max(tt, t2);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		scanf("%lf", &D);
		scanf("%d %d", &N, &A);
		FOR(i, 0, N) scanf("%lf %lf", T+i, X+i);
		FOR(i, 0, A) scanf("%lf", a+i);

		while (N>1 && X[N-2]>=D) N--;

		printf("Case #%d:\n", ++ind);
		FOR(i, 0, A)
			printf("%.10lf\n", Calc(a[i]));
	}

	return 0;
}