#define _USE_MATH_DEFINES

#ifdef ONLINE_JUDGE
#define FINPUT(file) 0
#define FOUTPUT(file) 0
#else
#define FINPUT(file) freopen(file,"r",stdin)
#define FOUTPUT(file) freopen(file,"w",stdout)
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

typedef long long ll;
static const int M = 110;
static const int N = 1010;
static const int LEN = 4;
static const int MAX = 0x7fffffff;
static const int MIN = ~MAX;
static const double EPS = 1e-8;

void solve(int ncase)
{
	int n;
	scanf("%d", &n);

	double naomi[N], ken[N];
	for (int i = 0; i < n; i++) {
		scanf("%lf", &naomi[i]);
	}
	
	for (int i = 0; i < n; i++) {
		scanf("%lf", &ken[i]);
	}

	std::sort(naomi, naomi + n);
	std::sort(ken, ken + n);

	int idx_naomi = 0, idx_ken = 0;
	int decipher = 0;
	while (idx_naomi < n && idx_ken < n) {
		if (naomi[idx_naomi] < ken[idx_ken]) {
			idx_naomi++;
		}
		else {
			decipher++;
			idx_naomi++; 
			idx_ken++;
		}
	}

	idx_naomi = 0;
	idx_ken = 0;
	int war = 0;
	while (idx_naomi < n && idx_ken < n) {
		if (ken[idx_ken] < naomi[idx_naomi]) {
			idx_ken++;
		}
		else {
			war++;
			idx_naomi++;
			idx_ken++;
		}
	}

	printf("Case #%d: %d %d\n", ncase, decipher, n - war);
}

int main()
{
	FINPUT("in.txt");
	FOUTPUT("out.txt");

	int c, ncase = 1;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		solve(ncase++);
	}
	return 0;
}