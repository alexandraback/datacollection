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
#define eps      1e-6
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

int dp[2000002], etiket;

int check(int a, int n) {
	int res = 0;
	int ten = 1;
	int len = 0;
	++etiket;
	int temp = n;
	while (temp) {
		ten *= 10;
		temp /= 10;
		++len;
	}

	ten /= 10;
	int curr = n;
	for (int i = 1; i < len; ++i) {
		curr = (curr % 10) * ten + curr / 10;

		if (curr < n && curr >= a && curr / ten > 0) {
			if (dp[curr] != etiket) {
				++res;
				dp[curr] = etiket;
			}
		}
	}

	return res;
}

int main() {
	int k, T;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%d", &T);

	for(k = 1 ; k <= T ; ++k) {
		int a, b;
		scanf("%d%d", &a, &b);
		long long result = 0;

		for (int i = a; i <= b; ++i) {
			result += check(a, i);
		}

		cout << "Case #" << k << ": " << result << endl;
	}

	return 0;
}

