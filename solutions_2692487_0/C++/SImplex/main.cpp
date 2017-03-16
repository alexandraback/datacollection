#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;

int const MAX_SIZE = 105;
int arr[MAX_SIZE] = {};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
	int t = 0;
	cin >> t;
	for (int step = 1; step <= t; ++step)
	{
		int a, n;
		cin >> a >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		if (a == 1)
		{
			cout << "Case #" << step << ": " << n << "\n";
			continue;
		}
		int count = 0;
		sort(arr,arr+n);
		int cur = 0;
		int ans = n;
		while (cur < n)
		{
			while (a <= arr[cur])
			{
				++count;
				a = a + a - 1;
			}
			a += arr[cur];
			++cur;			
			if (ans > (count + n - cur))
				ans = count + n - cur;
		}
		cout << "Case #" << step << ": " << ans << "\n";
	}
	
    return 0;
}