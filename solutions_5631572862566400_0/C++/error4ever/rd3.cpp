#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int solve(int a[1100], int abc)
{
	int tt[1100];
	int ttt[1100];
	for (int i = 0; i < abc; i++)
		tt[i] = 0;
	std::vector<std::pair<int,int>> aaa;
	for (int i = 0; i < abc; i++)
	{
		if (a[a[i] - 1] - 1 == i&&tt[i] == 0)
		{
			aaa.push_back(std::pair<int, int>(i, a[i]-1));
			tt[i] = 1;
			tt[a[i] - 1] = 1;
		}
	}
	int zigzig[1200];
	for (int i = 0; i < 1200; i++)
		zigzig[i] = 0;
	int big_ct = 1;
	int cnt_pair = aaa.size() * 2;
	int normal_loop = 0;
	for (int i = 0; i < abc; i++)
		{
			int start = i;
			int next;
			int count=0;
			if (tt[i] == 0)
			{
				for (int i = 0; i < abc; i++)
					ttt[i] = tt[i];
				count = 1;
				next = a[i]-1;
				while (next != start&&ttt[next] == 0)
				{
					ttt[next] = 1;
					next = a[next] - 1;
					count++;
				}
			}
			if (count > 0){
				if (next == start)
				{
					normal_loop = max(normal_loop, count);
				}
				else{
					for (int i = 0; i < aaa.size(); i++)
					if (next == aaa[i].first)
						zigzig[i * 2] = max(zigzig[i * 2], count);
					else if (next == aaa[i].second)
						zigzig[i * 2 + 1] = max(zigzig[i * 2 + 1], count);
				}
			}
		}
	int tt123=0;
	for (int i = 0; i < aaa.size(); i++)
		tt123+= zigzig[i * 2] + zigzig[i * 2 + 1];
	return max(cnt_pair + tt123, normal_loop);
}

int main()
{
	ofstream fout("out.txt");
	ifstream fin("in.txt");

	//	ofstream fout1("in.txt");
	//	fout1 << 1000000 << endl;
	//	for (int i = 0; i < 1000000; i++)
	//		fout1 << i << endl;
	int test_cases;
	fin >> test_cases;
	int num123 = 1;
	while (test_cases--)
	{
		int abc1, d;
		int tt;
		//		fin >> abc1;
		fin >> tt;
		int a[1100];
		for (int i = 0; i < 1100; i++)
			a[i] = 0;

		for (int i = 0; i < tt; i++)
		{
			fin >> d;
			a[i] = d;

		}
		int result = solve(a, tt);
		fout << "Case #" << num123 << ": " << result;
		fout << endl;
		int out123 = 0;
		num123++;
	}
	return 0;
}