#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <bitset>
using namespace std;
int c, d, v;
int ds[111];
int main()
{
	int tt, ans;
	cin >> tt;
	for (int cc = 0; cc < tt; cc++)
	{
		cin >> c >> d >> v;

		for (int i = 0; i < d; i++)
		{
			cin >> ds[i];
		}
		sort(ds, ds + d);

		ans = 0;
		int current_present = 0;
		int ds_index = 0;
		while (current_present < v)
		{
			if (ds_index<d)
			if (ds[ds_index] <= current_present + 1)
			{
				current_present += ds[ds_index++] * c;
				continue;
			}
			
			ans++;
			current_present += (current_present + 1)*c;
		}

		cout << "Case #" << cc+1 << ": " << ans<<endl;
	}
	return 0;
}