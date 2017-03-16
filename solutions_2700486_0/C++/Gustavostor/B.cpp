#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define maxn 1111111
typedef long long ll;

using namespace std;

int N, NIV, X, Y;
double prob(int niv, int left, int right, int cnt) {
	if (niv == NIV && ((X <= 0 && left == Y) || (X > 0 && right == Y))) return 1.0;
	if (cnt >= N) return 0.0;
	if (left > niv) return prob(niv+2, 0, 0, cnt);
	else if (left < niv && right < niv) {
		double p = 0.5*prob(niv, left+1, right, cnt+1) + 0.5*prob(niv, left, right+1, cnt+1);
		//printf("1. %d %d %d %d = %lf\n", niv, left, right, cnt, p);
		return p;
	}
	else if (left < niv) {
		double p = prob(niv, left+1, right, cnt+1);
		//printf("2. %d %d %d %d = %lf\n", niv, left, right, cnt, p);
		return prob(niv, left+1, right, cnt+1);
	}
	else if (right < niv) {
		double p = prob(niv, left, right+1, cnt+1);
		//printf("3. %d %d %d %d = %lf\n", niv, left, right, cnt, p);
		return prob(niv, left, right+1, cnt+1);
	}
	else return prob(niv, left+1, right, cnt+1);
}

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &N, &X, &Y);
		NIV = (abs(X)+abs(Y));
		Y++;
		printf("Case #%d: %.8lf\n", cas++, prob(0,0,0,0));
	}
	return 0;
}