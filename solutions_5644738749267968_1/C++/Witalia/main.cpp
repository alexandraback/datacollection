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
		cout << "Case #" << t + 1 << ": ";

		int n;
		cin >> n;
		vector<double> a(n), b(n);
		for (auto &i : a) cin >> i;
		for (auto &i : b) cin >> i;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int ans = 0;
		int fst = 0, lst = n - 1;
		for (int i = n - 1; i >= 0; --i) {
			if (a[lst] > b[i]) {
				ans++;
				--lst;
			}
			else ++fst;
		}
		cout << ans << " ";

		ans = 0;
		fst = 0;
		for (int i = 0; i < n; ++i) {
			while (fst < n && (b[fst] < a[i] || b[fst] < 0)) ++fst;
			if (fst == n) {
				fst = 0;
				while (b[fst] < 0) ++fst;
			}
			ans += b[fst] < a[i];
			b[fst] = -1;
		}
		cout << ans << endl;
	}
	return 0;
}