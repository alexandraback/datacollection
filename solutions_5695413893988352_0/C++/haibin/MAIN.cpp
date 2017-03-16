#include <string>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ifstream fin("B-small-attempt2.in");
	ofstream fout("B-small-attempt2.out");
	int digit;
	int count = 1;
	fin >> digit;
	string s1, s2;
	while (fin >> s1 >> s2)
	{
		int n = s1.size();
		vector<int> value;
		vector<string> score;
		for (int i = 0; i < pow(10, n); i++)
		{
			value.push_back(i);
			//cout << to_string(i) << endl;
			string s = to_string(i);
			while (s.size() < n)
			{
				s.insert(s.begin(), '0');
			}
			//cout << s << endl;
			score.push_back(s);
		}
		vector<int> valids1;
		vector<int> valids2;
		for (size_t i = 0; i < score.size(); i++)
		{
			bool isSame = true;
			for (size_t j = 0; j < score[i].size(); j++)
			{
				if (s1[j] != '?' && s1[j] != score[i][j])
				{
					isSame = false;
					break;
				}
			}
			if (isSame)
			{
				//cout << value[i] << endl;
				valids1.push_back(value[i]);
			}
		}
		//cout << valids1.size() << endl;
		for (size_t i = 0; i < score.size(); i++)
		{
			bool isSame = true;
			for (size_t j = 0; j < score[i].size(); j++)
			{
				if (s2[j] != '?' && s2[j] != score[i][j])
				{
					isSame = false;
					break;
				}
			}
			if (isSame)
			{
				//cout << value[i] << endl;
				valids2.push_back(value[i]);
			}
		}
		//cout << valids2.size() << endl;

		int min_diff = 100000;
		int currents1 = 0;
		int index1 = -1;
		int index2 = -1;
		int currents2 = 0;
		// find the nearest
		for (size_t i = 0; i < valids1.size(); i++)
		{
			for (size_t j = 0; j < valids2.size(); j++)
			{
				if (min_diff > abs(valids1[i] - valids2[j]))
				{
					min_diff = abs(valids1[i] - valids2[j]);
					currents1 = valids1[i];
					currents2 = valids2[j];
				}
				else if (min_diff == abs(valids1[i] - valids2[j]))
				{
					if (currents1 > valids1[i])
					{
						currents1 = valids1[i];
						currents2 = valids2[j];
					}
					else if (currents1 == valids1[i])
					{
						if (currents2 > valids2[j])
						{
							currents2 = valids2[j];
						}
					}
				}
			}
		}
		string res1 = to_string(currents1);
		while (res1.size() < n)
		{
			res1.insert(res1.begin(), '0');
		}
		string res2 = to_string(currents2);
		while (res2.size() < n)
		{
			res2.insert(res2.begin(), '0');
		}
		fout << "Case #" << count << ": " << res1 << " " << res2 << endl;
		count++;
	}
}