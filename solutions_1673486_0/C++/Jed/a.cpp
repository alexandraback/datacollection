/*
 * $File: a.cpp
 * $Date: Sat Apr 28 09:29:30 2012 +0800
 * $Author: jiakai <jia.kai66@gmail.com>
 */

// f{{{ 

#include <stdint.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <limits>

#define ITER_VECTOR(v, var) \
	for (typeof((v).begin()) var = (v).begin(); var != (v).end(); var ++)

#define ITER_VECTOR_IDX(v, var) \
	for (typeof((v).size()) var = 0; var < (v).size(); var ++)

using namespace std;

// f}}}

namespace Solve
{
	const int PWDLEN_MAX = 100005;
	double prob[PWDLEN_MAX];
	int ntype, pwdlen;
	double work();

	void solve(FILE *fin, FILE *fout);
}

void Solve::solve(FILE *fin, FILE *fout)
{
	int ncase;
	fscanf(fin, "%d", &ncase);
	for (int casenu = 1; casenu <= ncase; casenu ++)
	{
		fscanf(fin, "%d%d", &ntype, &pwdlen);
		for (int i = 0; i < ntype; i ++)
			fscanf(fin, "%lf", &prob[i]);
		fprintf(fout, "Case #%d: %.7lf\n", casenu, work());
	}
}

double Solve::work()
{
	double ans = pwdlen + 2, p = 1;
	for (int i = 0; i <= ntype; i ++)
	{
		int nfinish = (ntype - i) + (pwdlen - i) + 1;
		ans = min(ans, p * nfinish + (1 - p) * (nfinish + pwdlen + 1));
		p *= prob[i];
	}
	return ans;
}

// f{{{ main
int main()
{
#if defined(INPUT) && defined(OUTPUT) && !defined(STDIO) && !defined(ONLINE_JUDGE)
	FILE *fin = fopen(INPUT, "r"),
		 *fout = fopen(OUTPUT, "w");
	Solve::solve(fin, fout);
	fclose(fin);
	fclose(fout);
#else
	Solve::solve(stdin, stdout);
#endif
}
// f}}}
// vim: filetype=cpp foldmethod=marker foldmarker=f{{{,f}}}

