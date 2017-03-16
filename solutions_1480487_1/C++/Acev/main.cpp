#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <sstream>
#include <iostream>
using namespace std;

//////////////////// Defines ////////////////////

#pragma comment(linker, "/STACK:67108864")

#define inf      2147483647
#define inf64    9223372036854775807
#define eps      1e-9
#define pi      3.14159265358
#define sqr(a) (a)*(a)
#define rall(a) a.rbegin(),a.rend()
#define all(a) a.begin(),a.end()
#define sz(a) (a).size()
#define mset(a,v) memset(a, v, sizeof(a))
#define pb push_back 
typedef long long ll;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

#define ContinueIf(x) if ((x)) continue
#define ContinueUnless(x) if(!(x)) continue

#define BreakIf(x) if ((x)) break
#define BreakUnless(x) if(!(x)) break

#define ReturnUnless(x) if (!(x)) return
#define ReturnIf(x) if ((x)) return

#define ReturnUnless2(x, ret) if (!(x)) return ret
#define ReturnIf2(x, ret) if ((x)) return ret

//////////////////// Problem Code ////////////////////


bool f(const vector<int> &scores, int ind, double x, double m) {
	double rest = 1.0 - m;
	double result = scores[ind] + x * m;

	for (int i = 0; i < (int)scores.size(); ++i) {
		if (i == ind) {
			continue;
		}

		double to_beat = result - scores[i];
		if (to_beat < eps) {
			continue;
		}

		rest -= to_beat / x;

		if (rest < -eps) {
			break;
		}
	}

	return rest < eps;
}

double solve(const vector<int> &scores, int ind, double x) {
	double l = 0.0, r = 1.0;

	for (int i = 0; i < 64; ++i) {
		double m = (l + r) / 2.0;
		if (f(scores, ind, x, m)) {
			r = m;
		} else {
			l = m;
		}
	}

	return l;
}

int main()
{
	int k, T;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%d", &T);
	for(k = 1 ; k <= T ; ++k)
	{
		int N;
		double x = 0;
		scanf("%d", &N);
		vector<double> result(N);
		vector<int> scores(N);

		for (int i = 0; i < N; ++i) {
			scanf("%d", &scores[i]);
			x += scores[i];
		}
		
		for (int i = 0; i < N; ++i) {
			result[i] = solve(scores, i, x) * 100.0;
		}
		
		printf("Case #%d:", k);
		for (int i = 0; i < N; ++i) {
			printf(" %.6lf", result[i]);
		}
		printf("\n");
	}
	return 0;
}

