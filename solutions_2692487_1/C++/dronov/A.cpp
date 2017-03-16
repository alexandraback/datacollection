#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

#define MAXN 1000
#define INF 1000000000

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int test = 0; test < tests; test++) {
		int A;
		int N;
		scanf("%d%d", &A, &N);
		vector < int > a(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		sort(a.begin(), a.end());
		int i = 0;
		int cnt1 = 0;
		int cnt2 = INF;
		for (; i < a.size(); i++) {
			if (A > a[i]) {
				A += a[i];
				continue;
			} else {
				if (A + (A - 1) > a[i]) {
					cnt1++;
					A += (A - 1) + a[i];
				} else {
					if (a[i] == 1 || A == 1) {
						cnt1 += a.size() - i;
						break;
					}
					cnt2 = cnt1;
					cnt1 += a.size() - i;
					for (int j = i; j < a.size(); j++) {
						if (A  > a[j]) {
							A += a[j];
							continue;
						} else {
							cnt2++;
							A = A + A - 1;
							j--;
						}
					}
				}

			}
			
		}
		printf("Case #%d: %d\n", test + 1, min(cnt1, cnt2)); 
	}

	return 0;
}