#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> input;

#define DIV 1000000007

int testCase()
{
	int n;
	scanf("%d", &n);

	input = vector<string>(n);
	vector<int> p(n);

	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		input[i] = a;
		p[i] = i;
		for (int j = 0; j < input[i].length(); j++)
		{
			input[i][j] -= 'a';
		}
	}
	
	int count = 0;
	do
	{
		string current;
		for (int i = 0; i < n; i++)
		{
			current += input[p[i]];
		}

		vector<bool> test(26, 0);
		char prev = -1;
		int i;
		for (i = 0; i < current.length(); i++)
		{
			if (prev != current[i])
			{
				if (test[current[i]])
				{
					break;
				}
				prev = current[i];
			}
			test[current[i]] = true;
		}
		if (i < current.length() == false)
		{
			count++;
			count %= DIV;
		}

	} while (next_permutation(p.begin(), p.end()));

	return count;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: %d\n", i, testCase());
	}

	return 0;
}