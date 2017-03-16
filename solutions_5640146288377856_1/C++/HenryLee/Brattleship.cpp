#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	int t;

	cin >> t;
	
	for (int idx=0; idx<t; idx++)
	{
		int r, c, w;
		int ans;
		int hit;

		cin >> r >> c >> w;

		hit = (r-1)*(c/w);
		hit += (c+w-1)/w;

		ans = hit + w - 1;

		printf("Case #%d: %d\n", idx+1, ans);
	}
}
