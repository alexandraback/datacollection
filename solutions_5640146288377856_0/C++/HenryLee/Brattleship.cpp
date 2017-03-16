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

		hit = (c+w-1)/w;

		ans = hit + w - 1;

		if (ans > c)
			ans = c;
		
		printf("Case #%d: %d\n", idx+1, ans);
	}
}
