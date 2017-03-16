#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int cnt[2505];

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		int n, tmp;
		cin >> n;
		for (int i = 0; i < 2502; ++i)
			cnt[i] = 0;
		for (int i = 1; i < n * 2; ++i)
			for (int j = 0; j < n; ++j)
			{
				cin >> tmp;
				cnt[tmp]++;
			}
		cout << "Case #" << t << ":";
		for (int i = 1; i <= 2500; ++i)
			if (cnt[i] % 2 == 1)
				cout << " " << i;
		cout << endl;
	}

    return 0;
}
