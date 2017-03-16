#include <iostream>
#include <fstream>
#include <utility>
#include <list>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
		return a.second > b.second;
	return a.first > b.first;
}

int main()
{
	ifstream in("king.in");
	ofstream out("king.out");

	int T;
	in >> T;
	for (int C = 0; C < T; C++)
	{
		list<pair<int, int> > levels;
		int n;
		in >> n;
		for (int i = 0; i < n; i++)
		{
			pair<int, int> a;
			in >> a.first >> a.second;
			levels.push_back(a);
		}
		levels.sort(cmp);
		int ans = 0;
		int stars = 0;
		bool good = true;
		while (!levels.empty())
		{
			int starGain = 0;
			list<pair<int, int> >::iterator toErase = levels.end();
			list<pair<int, int> >::iterator toNeg = levels.end();
			for (list<pair<int, int> >::iterator it = levels.begin(); it != levels.end(); it++)
			{
				//if can get two
				if (stars >= it->second && it->first != -1)
				{
					starGain = 2;
					levels.erase(it);
					toErase = levels.end();
					toNeg = levels.end();
					break;
				}
				//if can get one from a two star
				if (stars >= it->second)
				{
					starGain = 1;
					toErase = it;
					toNeg = levels.end();
				}
				//if can get one from one star
				else if (stars >= it->first && starGain == 0 && it->first != -1)
				{
					starGain = 1;
					toNeg = it;
				}
			}
			if (toErase != levels.end())
				levels.erase(toErase);
			else if (toNeg != levels.end())
				toNeg->first = -1;
			if (starGain == 0)
			{
				good = false;
				break;
			}
			stars += starGain;
			ans++;
		}
		if (good)
			out << "Case #" << C + 1 << ": " << ans << "\n";
		else
			out << "Case #" << C + 1 << ": Too Bad\n";
	}
}
