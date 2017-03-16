#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

#define ll long long

const int MN = 100 + 10;

int arr[MN];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int k = 0; k < t; k ++) {
		int a, n;
		cin >> a >> n;
		for(int i = 0; i < n; i ++)
			cin >> arr[i];
		sort(arr, arr + n);
		int ans = n;
		for(int add = 0; add <= n; add ++) {
			int cur = a;
			int s = 0;
			for(int i = 0; i < n; i ++) {
				while (s < add && cur <= arr[i]) {
					cur += (cur - 1);
					s ++;
				}
				if (s == add && cur <= arr[i]) {
					s += (n - i);
					break;
				}
				cur += arr[i];
			}
			ans = min(ans, s);
		}
		printf("Case #%d: %d\n", k + 1, ans);
	}
	return 0;
}