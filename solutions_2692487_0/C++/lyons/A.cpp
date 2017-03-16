#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxN = 110;
int s[maxN];
int A, N;

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w+", stdout);
	int T;
	cin >> T;
	for (int tcase = 1; tcase <= T; ++ tcase) {
		cin >> A >> N;
		for (int i = 0; i < N; ++ i)
			cin >> s[i];
		sort(s, s + N);
		int count = 0;
		int mincount = N;
		for (int i = 0; i < N; ++ i) {
			while (A > 1 && A <= s[i]) {
				A += A - 1;
				++ count;
			}
			if (A > s[i])
				A += s[i];
			else break;
			if (count + (N - i - 1) < mincount)
				mincount = count + N - i - 1;
		}
		cout << "Case #" << tcase << ": " << mincount << endl;
	}
	return 0;
}
