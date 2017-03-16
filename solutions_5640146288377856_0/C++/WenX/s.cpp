#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int main()
{
	int cc, tt, r, c, w, ans;
	cin >> tt;
	for (int cc = 0; cc < tt; cc++)
	{
		cin >> r >> c >> w;

		int first_approach = r*(c / w);
		if (c%w == 0)
			ans = first_approach + w - 1;
		else
			ans = first_approach + w;

		cout << "Case #" << cc+1 << ": " << ans<<endl;
	}
	return 0;
}