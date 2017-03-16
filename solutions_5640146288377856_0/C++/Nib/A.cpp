#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int t, r, c, w, ans;
	scanf("%d", &t);
	for (int rep = 1;rep <= t;rep++)
	{
		scanf("%d%d%d", &r, &c, &w);
		ans = c / w*r;
		ans += w-1;
		if(c % w) ans++; //I hate this
		printf("Case #%d: %d\n", rep, ans);
	}
}