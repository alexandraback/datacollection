#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int MinBanana(int s, const string &word)
{
	int start = 1;
	for (; start < word.size(); ++start)
	{
		bool flag = true;
		for (int i = 0; start + i < word.size(); ++i)
			if (word[i] != word[start + i])
			{
				flag = false;
				break;
			}
		if (flag)
			break;
	}

	return (s - word.size()) / start + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int case_count;
	cin >> case_count;
	for (int case_no = 1; case_no <= case_count; ++case_no)
	{
		cout << "Case #" << case_no << ": ";
		int k, l, s;
		cin >> k >> l >> s;
		string keyboard;
		cin >> keyboard;
		string word;
		cin >> word;
		map<char, double> alpha_p;
		for (char c : keyboard)
		{
			alpha_p[c] += 1;
		}
		for (auto it = alpha_p.begin(); it != alpha_p.end(); ++it)
			it->second /= keyboard.size();
		double p = 1;
		bool possible = true;
		for (char c : word)
		{
			if (alpha_p.find(c) == alpha_p.end())
			{
				possible = false;
				break;
			}
			p *= alpha_p[c];
		}

		if (possible)
			cout << fixed << setprecision(8) << MinBanana(s, word) - p * (s - word.size() + 1) << endl;
		else
			cout << fixed << setprecision(8) << 0.0 << endl;
	}
}
