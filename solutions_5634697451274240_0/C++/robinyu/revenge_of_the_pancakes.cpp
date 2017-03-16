#include <fstream>
#include <string>
#include <utility>
#include <queue>
#include <set>

std::queue<std::pair<std::string, int> > bfs;
std::set<std::string> seen;

int main()
{
	std::ifstream fin ("B-small-attempt1.in");
	std::ofstream fout("B-small-attempt1.out");
	std::string k, d, tmp, what;
	int tc, tmpdist;
	
	fin >> tc;
	for (int t = 0; t < tc; t++)
	{
		seen.clear();
		fout << "Case #" << t+1 << ": ";
		fin >> k;
		
		d = "";
		for (int i = 0; i < k.length(); i++) d += '+';
		
		bfs.push(std::make_pair(k, 0));
		while (!bfs.empty())
		{
			tmp = bfs.front().first;
			tmpdist = bfs.front().second;
			bfs.pop();
			if (seen.find(tmp) == seen.end())
			{
				seen.insert(tmp);
				if (tmp == d)
				{
					fout << tmpdist << '\n';
					break;
				}
				for (int i = 0; i < tmp.length(); i++)
				{
					what = "";
					for (int j = i; j >= 0; j--)
					{
						if (tmp.at(j) == '+') what += '-';
						else what += '+';
					}
					for (int j = i+1; j < tmp.length(); j++)
						what += tmp.at(j);
					bfs.push(std::make_pair(what, tmpdist+1));
				}
			}
		}
		while (!bfs.empty()) bfs.pop();
	}
}
