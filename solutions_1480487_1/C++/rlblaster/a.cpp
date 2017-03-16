#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
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
#include <valarray>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define SZ(x) ((int) (x).size())
#define maxit(x,y) ((x) = max((x),(y)))
#define minit(x,y) ((x) = min((x),(y)))
typedef long long LL;

int N;
double X;
pair<int,int> S[210];
double res[210];

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int ctc = 1; ctc <= TC; ++ctc) {
		scanf("%d", &N);
		X = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &S[i].first);
			S[i].second = i;
			X += S[i].first;
		}
		sort(S, S+N);
		memset(res, 0, sizeof res);
		double allX = X;
		for (int i = 1; i < N && X > 0.0; ++i) {
			double pp = (S[i].first - S[i-1].first) * i;
			minit(pp, X);
			X -= pp;
			double t = (pp/i) / allX * 100.0;
			for (int j = 0; j < i; ++j) {
				res[S[j].second] += t;
			}
		}
		double t = ((X/N) / allX) * 100.0;
		for (int j = 0; j < N; ++j) {
			res[S[j].second] += t;
		}
		printf("Case #%d:", ctc);
		for (int i = 0; i < N; ++i)
			printf(" %0.9lf", res[i]);
		puts("");
	}
	return 0;
}
