#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
// #define TEST


using namespace std;
const int MAX_HEIGHT = 2505;
int n;
int height[MAX_HEIGHT];

void solve(int testCase)
{
	cin >> n;
	for (int i = 0; i < MAX_HEIGHT; i++)
		height[i] = 0;

	int h;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> h;
			height[h]++;
		}
	}

	vector<int> file;
	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		if (height[i] % 2 == 1)
			file.push_back(i);
	}

	sort(file.begin(), file.end());
	cout << "Case #" << testCase << ":";
	for (int a : file)
		cout << " " << a;
	cout << endl;
}

int main()
{
	#ifndef TEST
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	int test;
	cin >> test;
	for (int tt = 1; tt <= test; tt++)
		solve(tt);
}
