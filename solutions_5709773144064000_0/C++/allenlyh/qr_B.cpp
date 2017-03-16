//by allenlyh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <complex>

using namespace std;

typedef long long LL;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define sqr(x) (x)*(x)
#define sign(x) ((x)<-eps)?-1:(x)>eps
#define foreach(ite,s) for (__typeof(s.begin()) ite=s.begin();ite!=s.end();ite++)
#define lowbit(x) ((x) & (-(x)))
const double eps=1e-9;
const int INF=0x3f3f3f3f;

double c, f, x;
double sp;
double ans;
double cur;

void work() {
	cin>>c>>f>>x;
	sp = 2.0;
	cur = 0;
	ans = double(x / sp);
	while (sign(cur - ans) < 1) {
		if (sign(cur + (x / sp) - ans) == -1) ans = cur + (x / sp);
		cur += (c / sp);
		sp += f;
	}
	printf("%.7lf\n", ans);
}

int main() {
	int T;
	int cas=0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cas);
		work();
	}
	return 0;
}
