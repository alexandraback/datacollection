#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool Check(char ch){
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

char st[1000005]; int N;
int lat[1000005], nxt[1000005];

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a2.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i ++){
		scanf("%s", st + 1);
		scanf("%d", &N);
		int len = strlen(st + 1); long long ret = 0;
		for (int i = 1; i <= len; i ++){
			if (Check(st[i])) lat[i] = i;
				else lat[i] = lat[i - 1];
		}
		int p = len + 1;
		for (int i = len - N + 1; i >= 1; i --){
			if (lat[i + N - 1] < i) p = i + N - 1;
			if (p < len + 1)
				ret += len - p + 1;
		}
		printf("Case #%d: %lld\n", i + 1, ret);
	}
	return 0;
}
