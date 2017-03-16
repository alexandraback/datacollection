#include <cmath>
#include <queue>
#include <deque>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100000 + 10;
int A, B;
double p[MAX_N];

void inputData()
{
	scanf("%d%d", &A, &B);
	p[0] = 1;
	for(int i = 1; i <= A; ++ i) {
		scanf("%lf", &p[i]);
		p[i] *= p[i - 1];
	}
}

void calcAns()
{
	double ret = B + 2;
	ret = min(ret, (B - A + 1) + (1 - p[A]) * (B + 1));
	for(int x = 0; x <= A; ++ x) 
		ret = min(ret, x * 2 + B - A + 1 + (1 - p[A - x]) * (B + 1));
	printf("%.10f\n", ret);
}

void solve(int t)
{
	printf("Case #%d: ", t);
	inputData();
	calcAns();
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T; 
	scanf("%d", &T);
	for(int i = 1; i <= T; ++ i) 
		solve(i);
	return 0;
}