#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

void solve(int test)
{
	printf("Case #%d: ", test);
	double C, F, X, cur = 2;
	cin >> C >> F >> X;
	double ret = 0;
	for( ; ; ) {
		if (C / cur + X / (cur + F) < X / cur) {
			ret += C / cur;
			cur += F;
		} else {
			ret += X / cur;
			break;
		}
	}
	printf("%.10f\n", ret);
}

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	int testcase;
	scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) 
		solve(i);
	fclose(stdout);
	return 0;
}
