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

using namespace std;
using namespace std::chrono;

typedef long long ll;

const int N = 16005;
const int K = 605;
const ll InfL = 1000000000000000000LL;
const int MOD = 1000000007;


//#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		double X, C, F;
		cin >> C >> F >> X;
		double perSec = 2;
		double ans = X / perSec;
		double tm = 0;
		for (int i = 0; i < 1000000; ++i) {
			tm += C / perSec;
			perSec += F;
			double cur = tm + X / perSec;
			if (cur < ans)
				ans = cur;
			else
				break;
		}
		cout << "Case #" << t + 1 << ": " << fixed << setprecision(10) << ans << endl;
	}
	return 0;
}