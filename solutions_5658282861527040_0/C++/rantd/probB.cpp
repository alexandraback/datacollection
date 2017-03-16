#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;
typedef long long int64;
typedef pair<int, int> PII;
const int MOD = 1000000007;
const double EPSILON = 1e-10;

#define FORU(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define SIZE(A) ((int) A.size())
#define PB(X) push_back(X)
#define MP(A, B) make_pair(A, B)

template<class T> inline T tmin(T a, T b) {return (a < b) ? a : b;}
template<class T> inline T tmax(T a, T b) {return (a > b) ? a : b;}
template<class T> inline T tabs(T a) {return (a > 0) ? a : -a;}
template<class T> T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}

int main(int argc, char const *argv[])
{
	/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	*/
	ios_base::sync_with_stdio(false);
	int ntest;
	int64 A, B, K;
	cin >> ntest;
	FORU(t, 1, ntest) {
		cin >> A >> B >> K;
		A--; B--; K--;
		int64 ans = 0;
		for (int64 i = 0; i <= A; ++i) {
			for (int64 j = 0; j <= B; ++j) {
				if ((i & j) <= K) ans++;
			}
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}