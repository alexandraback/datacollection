#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
bool isvalid(vector<int> idlist, vector<int> bfflist)
{
	bool valid = true;
	for (size_t i = 0; i < idlist.size(); i++)
	{
		int currenID = i;
		int pervioud = i - 1;
		if (pervioud < 0)
		{
			pervioud = idlist.size() - 1;
		}
		int next = i + 1;
		if (next == idlist.size())
		{
			next = 0;
		}
		if (bfflist[idlist[i]] != idlist[pervioud] && bfflist[idlist[i]] != idlist[next])
		{
			return false;
		}
	}
	return true;
}

int getCircle(int id, vector<int> bfflist)
{
	vector<int> res;
	res.push_back(id);
	vector<bool> isvisited;
	isvisited.resize(bfflist.size(), false);
	isvisited[id - 1] = true;
	int addsize = 1;
	while (addsize > 0)
	{
		addsize = 0;
		int nextId = bfflist[res.back() - 1];
		if (!isvisited[nextId - 1])
		{
			res.push_back(nextId);
			isvisited[nextId - 1] = true;
			addsize++;
		}
	}
	vector<vector<int>> addRes;
	addRes.push_back(res);
	int checkcouldAdded = 1;
	while (checkcouldAdded > 0)
	{
		checkcouldAdded = 0;
		vector<vector<int>> ResBack = addRes;
		addRes.clear();
		for (size_t i = 0; i < ResBack.size(); i++)
		{
			vector<bool> isvisitedNew;
			isvisitedNew.resize(bfflist.size(), false);
			for (size_t j = 0; j < ResBack[i].size(); j++)
			{
				isvisitedNew[ResBack[i][j] - 1] = true;
			}
			for (size_t j = 0; j < bfflist.size(); j++)
			{
				if (!isvisitedNew[j] && bfflist[j] == ResBack[i].back())
				{
					vector<int> newCircle = ResBack[i];
					newCircle.push_back(j + 1);
					addRes.push_back(newCircle);
					checkcouldAdded++;
				}
			}
		}
	}
	if (addRes.size() == 0)
	{
		return res.size();
	}
	int max = 0; 
	for (size_t i = 0; i < addRes.size(); i++)
	{
		if (max < addRes[i].size())
		{
			max = addRes.size();
		}
	}
	return max;
	
}

int main()
{

	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");
	int digit;
	int count = 1;
	fin >> digit;
	while (fin >> digit)
	{
		vector<int> id;
		vector<int> bff;
		for (size_t i = 0; i < digit; i++)
		{
			id.push_back(i + 1);
		}

		vector<int> input;
		for (size_t i = 0; i < digit; i++)
		{
			int num;
			fin >> num;
			bff.push_back(num);
		}
		int maxSt = 0;
		for (size_t i = 0; i < id.size(); i++)
		{
			if (maxSt <  getCircle(id[i], bff))
			{
				maxSt = getCircle(id[i], bff);
			}
		}
		fout << "Case #" << count << ": " << maxSt << endl;;
		count++;
	}
	return 0;
}