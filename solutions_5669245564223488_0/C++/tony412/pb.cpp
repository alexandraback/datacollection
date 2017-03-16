#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::string;

int main()
{
	int T, C, ans;
	int i, j, k;
	int n;
	int arr[15];
	string str[15], total;
	
	scanf("%d", &T);
	for (C = 1; C <= T; C++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			cin >> str[i]; 
			str[i].resize(std::unique(str[i].begin(), str[i].end()) - str[i].begin());
			arr[i] = i;
		}
		ans = 0;
		do {
			total = "";
			for (i = 0; i < n; i++)	
				total += str[arr[i]];
			total.resize(std::unique(total.begin(), total.end()) - total.begin());
			bool flag = true;
			bool used[30] = {false};
			for (i = 0; i < total.length(); i++)
			{
				if (used[total[i]-'a'])
				{
					flag = false;
					break;
				}
				used[total[i]-'a'] = true;
			}
			if (flag) ans++;
		} while (std::next_permutation(arr, arr+n));
		printf("Case #%d: %d\n", C, ans);
	}
	return 0;
}
