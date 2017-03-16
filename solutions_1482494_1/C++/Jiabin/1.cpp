#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct level
{
	int first;
	int second;
	int completed;
};

bool cmp(const level& lhs, const level& rhs)
{
	if (lhs.second == rhs.second)
		return lhs.first > rhs.first;
	else return
		lhs.second < rhs.second;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int l;
		cin >> l;
		vector<level> levels(l);
		for (int j = 0; j < l; j++)
		{
			cin >> levels[j].first >> levels[j].second;
			levels[j].completed = 0;
		}

		sort(levels.begin(), levels.end(), cmp);
		bool bad = false;
		int star = 0, step = 0;
start:		while (star < 2 * l)
		{
			for (int j = 0; ; j++)
			{
				if (levels[j].completed != 2)
				{
					if (levels[j].second > star)
						break;
					else
					{
						step += 1;
						star += (2 - levels[j].completed);
						levels[j].completed = 2;
						goto start;
					}
				}
			}

			for (int j = l - 1; j >= 0; j--)
			{
				if (levels[j].completed == 0 && levels[j].first <= star)
				{
					star += 1;
					step += 1;
					levels[j].completed = 1;
					goto start;
				}
			}

			bad = true;
			cout << "Case #" << i + 1 << ": " <<  "Too Bad" << endl;
			break;
		}

		if (!bad)
			cout << "Case #" << i + 1 << ": " << step << endl;
	}
}