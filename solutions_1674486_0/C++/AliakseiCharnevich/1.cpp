#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
const int max_n = 1000;
int n , k;
bool mas[max_n][max_n], is_used[max_n];
map <int, map <int, int>> mp;
bool ans_flag;
void init()
{
	for (int i = 0 ; i < max_n; i++)
		for (int j = 0 ; j < max_n; j++)
			mas[i][j] = false;
	for (int i = 0 ; i < max_n; i++)
		is_used[i] = false;
	mp.clear();
	ans_flag = false;
}
void dfs(int t)
{
	is_used[t] = true;
	for (int i =0 ; i < n ; i++)
		if (mas[t][i])
		{
			if (mp[t][i] + 1 > 1)
				ans_flag = true;
			else
				mp[t][i] += 1;
			if (!is_used[i])
				dfs(i);
			if (ans_flag)
				return;
			for (map<int, int>::iterator it = mp[i].begin(); it != mp[i].end(); it++)
			{
				pair < int , int > p = (*it);
				if (mp[t].find(p.first) == mp[t].end())
					mp[t][p.first] = p.second;
				else
					if (mp[t][p.first] + p.second > 1)
						ans_flag = true;
					else
						mp[t][p.first] += p.second;
			}
		}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test_count = 0;
	cin >> test_count;
	for (int  test = 1; test <= test_count; test++)
	{
		init();
		cin >> n;
		for (int i = 0 ; i < n; i++)
		{
			
			cin >> k;
			for (int j = 0 ; j < k; j++)
			{
				int temp;
				cin >> temp;
				temp--;
				mas[i][temp] = true;
			}

		}
		for (int i = 0 ; i < n && ans_flag == false; i++)
			if (is_used[i] == false)
				dfs(i);
		if (ans_flag == false)
		{
			for (map <int, map<int, int>>::iterator it = mp.begin(); it!= mp.end() && ans_flag == false; it++)
			{
				map < int ,int > pp = (*it).second;
				for (map <int, int>::iterator it2 = pp.begin(); it2 != pp.end() && ans_flag == false; it2++)
					if ((*it2).second >= 2)
						ans_flag = true;
			}
		}

		cout << "Case #" << test << ": ";
		if (ans_flag)
			cout << "Yes\n";
		else
			cout << "No\n";

	}
	return 0;
}