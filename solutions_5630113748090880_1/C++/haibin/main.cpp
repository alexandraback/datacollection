#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> rankFile(vector<int> input)
{
	vector<int> elements;
	for (size_t i = 0; i < input.size(); i++)
	{
		int isNew = 1;
		for (size_t j = 0; j < elements.size(); j++)
		{
			if (input[i] == elements[j])
			{
				isNew = 0;
				break;
			}
		}
		if (isNew == 1)
		{
			elements.push_back(input[i]);
		}
	}
	vector<int> countelementtime;
	countelementtime.resize(elements.size(), 0);
	for (size_t i = 0; i < elements.size(); i++)
	{
		for (size_t j = 0; j < input.size(); j++)
		{
			if (input[j] == elements[i])
			{
				countelementtime[i]++;
			}
		}
	}
	vector<int> res;
	for (size_t i = 0; i < elements.size(); i++)
	{
		//cout << elements[i] << " " << countelementtime[i] << endl;
		if (countelementtime[i] % 2 == 1)
		{
			res.push_back(elements[i]);
		}
	}

	sort(res.begin(), res.end());
	return res;
}

int main()
{
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");
	int digit;
	int count = 1;
	fin >> digit;
	while (fin >> digit)
	{
		vector<int> input;
		for (size_t i = 0; i < (2 * digit - 1) * digit; i++)
		{
			int num;
			fin >> num;
			input.push_back(num);
		}
		vector<int> res = rankFile(input);
		fout << "Case #" << count << ": ";
		for (int i = 0; i < res.size(); i++)
		{
			fout << res[i] << " ";
		}
		fout << endl;
		count++;
	}

	return 0;
}