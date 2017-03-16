#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


int T, n, m;
string s[108];
void work()
{
	int A, B, K;
	map<int, int> s;
	scanf("%d%d%d", &A, &B, &K);
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			if ((i & j) <= K)	{
				s[i&j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < K; i++) {
		ans += s[i];
	}
	printf("%d\n", ans);
}
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		work();
	}
}
