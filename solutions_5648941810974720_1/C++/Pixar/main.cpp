#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;

	int num[256] = {};
	num['G'] = 8;
	num['U'] = 4;
	num['W'] = 2;
	num['X'] = 6;
	num['Z'] = 0;
	num['H'] = 3;
	num['O'] = 1;
	num['F'] = 5;
	num['I'] = 9;
	num['S'] = 7;

	string letters[256];
	letters['G'] = "EIGHT";
	letters['U'] = "FOUR";
	letters['W'] = "TWO";
	letters['X'] = "SIX";
	letters['Z'] = "ZERO";
	letters['H'] = "THREE";
	letters['O'] = "ONE";
	letters['F'] = "FIVE";
	letters['I'] = "NINE";
	letters['S'] = "SEVEN";

	for (int t = 1; t <= T; t++)
	{
		string s;
		cin >> s;

		int occurences[10] = {};
		int cnt[256] = {};
		for (auto& c : s)
			cnt[c]++;

		for (auto c : { 'G', 'U', 'W', 'X', 'Z' })
		{
			while (true)
			{
				if (cnt[c])
				{
					occurences[num[c]]++;
					for (auto cc : letters[c])
						cnt[cc]--;
				}
				else
				{
					break;
				}
			}
		}

		for (auto c : { 'H' })
		{
			while (true)
			{
				if (cnt[c])
				{
					occurences[num[c]]++;
					for (auto cc : letters[c])
						cnt[cc]--;
				}
				else
				{
					break;
				}
			}
		}

		for (auto c : { 'O' })
		{
			while (true)
			{
				if (cnt[c])
				{
					occurences[num[c]]++;
					for (auto cc : letters[c])
						cnt[cc]--;
				}
				else
				{
					break;
				}
			}
		}

		for (auto c : { 'F' })
		{
			while (true)
			{
				if (cnt[c])
				{
					occurences[num[c]]++;
					for (auto cc : letters[c])
						cnt[cc]--;
				}
				else
				{
					break;
				}
			}
		}

		for (auto c : { 'I' })
		{
			while (true)
			{
				if (cnt[c])
				{
					occurences[num[c]]++;
					for (auto cc : letters[c])
						cnt[cc]--;
				}
				else
				{
					break;
				}
			}
		}

		for (auto c : { 'S' })
		{
			while (true)
			{
				if (cnt[c])
				{
					occurences[num[c]]++;
					for (auto cc : letters[c])
						cnt[cc]--;
				}
				else
				{
					break;
				}
			}
		}

		cout << "Case " << "#" << t << ": ";
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j < occurences[i]; j++)
				cout << i;

		cout << "\n";
	}


}