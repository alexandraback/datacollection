#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

const char valueTable[4][4] =
		{
				{ '1', 'i', 'j', 'k' },
				{ 'i', '1', 'k', 'j' },
				{ 'j', 'k', '1', 'i' },
				{ 'k', 'j', 'i', '1' }
		};

const bool negativeTable[4][4] =
		{
				{ 0, 0, 0, 0 },
				{ 0, 1, 0, 1 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 1 }
		};

pair<char, bool> merge(const string& str, int start, int end)
{
	if (start == end)
		return make_pair(str[start], false);

	int mid = (start + end) / 2;
	const auto& left = merge(str, start, mid);
	const auto& right = merge(str, mid + 1, end);

	bool negative = left.second != right.second;
	if (left.first == '1')
		return make_pair(right.first, negative);
	if (right.first == '1')
		return make_pair(left.first, negative);

	return make_pair(valueTable[left.first - 'i' + 1][right.first - 'i' + 1],
					 negativeTable[left.first - 'i' + 1][right.first - 'i' + 1] != negative);
}

int main()
{
	string blank;
	int numCases = 0;
	cin >> numCases;
	
	for (int iCase = 1; iCase <= numCases; iCase++)
	{
		int L = 0;
		cin >> L;

		uint64_t X;
		cin >> X;

		getline(cin, blank);

		string letters;
		getline(cin, letters);

		if (L * X < 3)
		{
			cout<<"Case #" << iCase << ": " << "NO" << endl;
			continue;
		}

		const auto& merged = merge(letters, 0, letters.size() -1);

		const bool isXEven = (X % 2 == 0);
		bool good = false;
		if (merged.first == '1')
			good = merged.second && !isXEven;
		else
			good = isXEven && (X % 4 != 0);

		if (!good)
		{
			cout << "Case #" << iCase << ": " << "NO" << endl;
			continue;
		}

		char find = 'i';
		char llll = '1';
		for (int i = 0; i < X && i < 10 && find <= 'k'; i++)
		{
			for (auto& ch : letters)
			{
				if (llll == '1')
					llll = ch;
				else
					llll = valueTable[llll-'i'+1][ch-'i'+1];
				if (llll == find)
				{
					llll = '1';
					find++;
					if (find == 'l')
						break;
				}
			}
			if (find == 'l')
				break;
		}
		if (find == 'l')
			cout<<"Case #" << iCase << ": " << "YES" << endl;
		else
			cout<<"Case #" << iCase << ": " << "NO" << endl;
	}

	return 0;
}