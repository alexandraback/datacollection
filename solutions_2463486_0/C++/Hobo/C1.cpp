#include <cstdio>

void work()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int cnt = 0;
	if(1 >= a && 1 <= b) cnt ++;
	if(4 >= a && 4 <= b) cnt ++;
	if(9 >= a && 9 <= b) cnt ++;
	if(121 >= a && 121 <= b) cnt ++;
	if(484 >= a && 484 <= b) cnt ++;
	printf("%d\n", cnt);
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int i = 1; i <= _; i ++)
		printf("Case #%d: ", i), work();
	return 0;
}
