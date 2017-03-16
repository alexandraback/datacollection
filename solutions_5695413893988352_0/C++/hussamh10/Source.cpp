#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<int> a;

void recurse(string s, int index, int val, vector<string>& v)
{
	if (index < 0)
		return;
	for (int i = 0; i < 10; i++)
	{
		s[a[index]] = i + 48;
		v.push_back(s);
		if (index == 1)
			recurse(s, index - 1, 1, v);
		else
			recurse(s, index - 1, 0, v);
	}
}

void genCombos(string s, vector<string>& v)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '?')
		{
			s[i] = '0';
			a.push_back(i);
		}
	}
	if (a.size() == 0)
	{
		v.push_back(s);
		return;
	}
	for (int i = a.size() - 1; i >= 0; i--)
	{
		//		for(int j = 0; j < 10; j++)
		recurse(s, i, 0, v);
	}
}

int main()
{
	int tc = 0;
	vector<string> v, v2;
	string s1, s2;
	string c1, c2;
	ifstream file("input.txt");
	file >> tc;
	int min, minC, minJ;
	int c_val, j_val;
	int diff;
	bool replace;
	for (int i = 1; i <= tc; i++)
	{
		v.clear();
		v2.clear();
		file >> s1 >> s2;
		a.clear();
		genCombos(s1, v);
		a.clear();
		genCombos(s2, v2);
		min = 100000000;
		minC = 10000000;
		minJ = 10000000;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v2.size(); j++)
			{
				replace = false;
				c_val = stoi(v[i]);
				j_val = stoi(v2[j]);
				diff = abs(c_val - j_val);
				if (diff < min)
				{
					replace = true;
					minC = c_val;
					minJ = j_val;
				}
				else if (diff == min && c_val < minC)
				{
					minC = c_val;
					replace = true;
				}
				else if (diff == min && j_val < minJ)
				{
					replace = true;
					minJ = j_val;
				}
				if (replace == true)
				{
					min = diff;
					c1 = v[i];
					c2 = v2[j];
				}
			}
		}
		cout << "Case #" << i << ": " << c1 << " " << c2 << endl;
	}
	file.close();
	return 0;
}