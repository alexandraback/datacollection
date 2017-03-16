#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int ds[1024];
int covers[1024];
int c, d, v;

void search(int lv, int current_val)
{
	if (lv == d)
	{
		covers[current_val]++;
		return;
	}

	search(lv + 1, current_val);
	search(lv + 1, current_val + ds[lv]);
}
int main()
{
	int cc, tt, ans;
	cin >> tt;
	for (int cc = 0; cc < tt; cc++)
	{
		cin >> c >> d >> v;
		for (int i = 0; i < d; i++)
			cin >> ds[i];

		memset(covers, 0, sizeof(covers));
		search(0,0);

		ans = 0;
		for (int i = 1; i <= v;)
		if (covers[i])i++;
		else
		{
			//i = i * 2;
			ds[d++] = i;
			//cout << " $" << i;
			memset(covers, 0, sizeof(covers));
			search(0, 0);
			ans++;
		}

		cout << "Case #" << cc+1 << ": " << ans<<endl;
	}
	return 0;
}