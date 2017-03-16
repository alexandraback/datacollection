#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int t;
vector< vector<double> > naomi, ken;

void read_data(char* filename)
{
	ifstream fin(filename);
	fin >> t;
	naomi.resize(t);
	ken.resize(t);
	for(int i = 0; i < t; i++)
	{
		int n;
		fin >> n;
		naomi[i].resize(n);
		ken[i].resize(n);

		for(int j = 0; j < n; j++)
		{
			fin >> naomi[i][j];
		}
		for(int j = 0; j < n; j++)
		{
			fin >> ken[i][j];
		}
		sort(naomi[i].begin(), naomi[i].end());
		sort(ken[i].begin(), ken[i].end());
	}
	fin.close();
}

void proc()
{
	for(int i = 0; i < t; i++)
	{
		int y, z;

		y = 0;
		z = 0;

		int min_index, max_index;
		min_index = 0;
		max_index = naomi[i].size() - 1;

		// Deceitful War
		for(int j = 0; j < naomi[i].size(); j++)
		{
			if(naomi[i][j] < ken[i][min_index])
			{
				max_index--;
			}
			else
			{
				min_index++;
				y++;
			}
		}

		// War
		set<int> selected;
		for(int j = 0; j < naomi[i].size(); j++)
		{
			for(int k = 0; k < ken[i].size(); k++)
			{
				if(selected.count(k) == 0 && ken[i][k] > naomi[i][j])
				{
					selected.insert(k);
					break;
				}
			}
			if(selected.size() - 1 != j)
			{
				for(int k = 0; k < ken[i].size(); k++)
				{
					if(selected.count(k) == 0)
					{
						selected.insert(k);
						z++;
						break;
					}
				}
			}
		}

		printf("Case #%d: %d %d\n", i + 1, y, z);
	}
}

int main(int argc, char** argv)
{
	read_data(argv[1]);
	proc();
	return 0;
}