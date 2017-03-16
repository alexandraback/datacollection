/*
Author: 67h2gak
*/
#include <cstdio>
#include <cstring>

using namespace std;

int x, y;

void init()
{
	scanf("%d%d", &x, &y);
}

void print(int t)
{
	printf("Case #%d: ", t + 1);
	int tx = x > 0 ? x : -x;
	for (int i = 0; i < tx; i ++)
		printf("%s", x > 0 ? "WE" : "EW");
	int ty = y > 0 ? y : -y;
	for (int i = 0; i < ty; i ++)
		printf("%s", y > 0 ? "SN" : "NS");
	puts("");
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t ++){
		init();
		print(t);
	}
	return 0;
}
