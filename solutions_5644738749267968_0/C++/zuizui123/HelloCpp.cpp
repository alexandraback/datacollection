#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

#define fi "D-small-attempt0.in"
#define fo "out.txt"
const int MAXN = 1000 + 5;
const int INF = 1e9;

double naomi[MAXN], ken[MAXN];

int main() {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);
	int T;
	cin >> T;
	int N;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> naomi[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> ken[i];
		}
		sort(naomi, naomi + N);
		sort(ken, ken + N);
		int deceitRes, warRes;
		deceitRes = warRes = 0;
		int k = N - 1;
		for (int i = N - 1; i >= 0; --i) {
			while (k >= 0 && ken[k] > naomi[i]) {
				--k;
			}
			if (k >= 0) {
				++deceitRes;
				--k;
			} else break;
		}
		k = 0;
		for (int i = 0; i < N; ++i) {
			while (k < N && ken[k] < naomi[i]) {
				++k;
			}
			//cout << i << " " << k << endl;
			if (k < N) {
				++warRes;
				++k;
			} else break;
		}
		warRes = N - warRes;
		cout << deceitRes << " " << warRes << endl;
//		for (int i = 0; i < N; ++i) {
//			cout << naomi[i] << " ";
//		}
//		cout << endl;
//		for (int i = 0; i < N; ++i) {
//			cout << ken[i] << " ";
//		}
//		cout << endl;
	}
}
