#include "cstdio"
#include "cstring"
#include "algorithm"

using namespace std;

int main(void)
{
	int t;
	scanf("%d", &t);
	for(int test = 1;test<=t;test++)
	{
		int w,r,c;
		scanf("%d%d%d", &r, &c, &w);

		int steps = c/w;

		printf("Case #%d: %d\n", test, steps*r + w - (c%w == 0));
	}

	return 0;
}
