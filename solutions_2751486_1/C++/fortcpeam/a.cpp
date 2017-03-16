/*
Author: 67h2gak
*/
#include <cstdio>
#include <cstring>

using namespace std;

const int maxN = 1000005;

inline bool check(char ch){
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

char st[maxN];
int lat[maxN], N;
long long ret;

void init()
{
	scanf("%s%d", st + 1, &N);
}

void work()
{
	int len = strlen(st + 1); ret = 0;
	for (int i = 1; i <= len; i ++){
		if (check(st[i])) lat[i] = i; else lat[i] = lat[i - 1];
	}
	int p = len + 1;
	for (int i = len - N + 1; i >= 1; i --){
		if (lat[i + N - 1] < i) p = i + N - 1;
		if (p < len + 1) ret += len - p + 1;
	}
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t ++){
		init();
		work();
		printf("Case #%d: %I64d\n", t + 1, ret);
	}
	return 0;
}
