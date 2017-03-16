#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

typedef long long LL;

const int maxn = 1000 + 10;
const double eps = 1e-8;
int s[maxn], n, Sum;

bool check(int st, int Mid)
{
	double now = double(Mid)*double(Sum) / 1000000000;
	double G = 0, C = now + s[st];
	for (int j = 1; j <= n; j++)
		if (j!=st && s[j]<C) {
			G += C - s[j];
		}
	if (G > Sum - now) return true;
	else return false;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int TextN, TT = 0;
	scanf("%d", &TextN);
	while (TextN--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
		printf("Case #%d:", ++TT);
		
		Sum = 0;
		for (int i = 1; i <= n; i++) Sum += s[i];
		for (int st = 1; st <= n; st++) {
			int Left = 0, Right = 1000000000, Mid, Ans = Right;
			while (Left <= Right) {
				Mid = (Left + Right) / 2;
				if (check(st, Mid)) {
					Right = Mid - 1;
					Ans = Mid;
				} else Left = Mid + 1;
			}
			printf(" %.6lf", (double)Ans/10000000);
		}
		printf("\n");
	}
	return 0;
}
