#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>

#define Cpp11
#ifdef Cpp11
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>
using namespace std::chrono;
#endif
using namespace std;

typedef long long ll;

const int N = 1001;
const int K = 105;
const int Inf = 1000000000;
const ll InfL = 1000000000000000000LL;
const int MOD = 1000000007;

ll Abs(ll a) { return a < 0 ? -a : a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

//int mx[] = { 1, 1, 2,2, -1, -1, -2, -2 };
//int my[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

//#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";

		ll p, q;
		scanf("%I64d/%I64d", &p, &q);
		ll g = gcd(p, q);
		p /= g; q /= g;
		int ans = 0;
		while (q % 2 == 0 && q > p) {
			++ans;
			q /= 2;
		}
		if (q & (q - 1))
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}