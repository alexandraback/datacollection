
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
#include <iomanip>
using namespace std;

class Solution
{
public:
	void run(int test)
	{
		int r, c, w;
		cin >> r >> c >> w;
		int ans = r * ((c - 1) / w + w);
		cout << "Case #" << test << ": " << ans << endl;
	}
private:

};

int main(void)
{
#if 1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution test;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		test.run(i);
	}
	return 0;
}