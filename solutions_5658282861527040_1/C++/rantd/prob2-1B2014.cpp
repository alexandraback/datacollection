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

int64 solve(int64 A, int64 B, int64 K)
{
	if (A < B) {
		int64 temp = A;
		A = B;
		B = temp;
	}
	if (B == 0) return (A+1);
	int indA, indK, indB;
	for (indA = 30; indA >= 0; --indA) {
		if (A & (1 << indA)) break;
	}
	for (indB = 30; indB >= 0; --indB) {
		if (B & (1 << indB)) break;
	}
	for (indK = 30; indK >= 0; --indK) {
		if (K & (1 << indK)) break;
	}
	if (indB < indK) return (A+1)*(B+1);
	else if (indA == indK) {
		int64 X = A^(1<<indA);
		int64 Y = B^(1<<indB);
		int64 Z = K^(1<<indK);
		return ((X+1)*(1L<<indB) + (Y+1)*(1L<<indA) + ((1L<<indA)*(1L<<indB)) + solve(X, Y, Z));
	}
	else {
		if (indB < indA) {
			int64 X = A^(1<<indA);
			return solve(X, B, K) + solve((1<<indA)-1, B, K);
		}
		else {
			int64 X = A^(1<<indA);
			int64 Y = B^(1<<indB);
			return (solve((1<<indA)-1, Y, K) +  solve(X, (1<<indB)-1, K) + solve((1<<indA)-1, (1<<indB)-1, K));
		}
	}
}

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
		printf("Case #%d: %lld\n", t, solve(A, B, K));
	}
	return 0;
}