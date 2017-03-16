#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	//C / 2 + C / (2 + F) + C / (2 + 2F) + ... + C / (2 + (c-1)F) + X / (2 + cF)
	//= C * \Sigma_{n=0}^{c-1} (1 / (2 + nF)) + X / (2 + cF)
	//収束してしまう場合があるっぽい？とりあえず最大ケースっぽいので収束するだけの十分に回せばいいかな…？
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double ans = 1e99;
		double sum = 0;
		rer(c, 0, 1000000) {
			double t = sum + X / (2 + c * F);
			amin(ans, t);
			sum += C / (2 + c * F);
		}
		printf("Case #%d: %.10f\n", ii+1, ans);
	}
	return 0;
}
