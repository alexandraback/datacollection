#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>

using namespace std;

int freq[2600];

void clear()
{
	for (int i = 0; i < 2600; i++)
		freq[i] = 0;
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		clear();
		for (int j = 0; j < 2 * N - 1; j++)
		{
			for (int k = 0; k < N; k++)
			{
				int n;
				cin >> n;
				freq[n]++;
			}
		}
		set<int> ans;
		for (int j = 0; j < 2600; j++)
		{
			if (freq[j] % 2 != 0)
				ans.insert(j);
		}

		cout << "Case #" << i + 1 << ": ";
		for (auto j : ans)
		{
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}