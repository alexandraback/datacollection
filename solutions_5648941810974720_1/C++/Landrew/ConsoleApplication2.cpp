#include "stdafx.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin("INP111.txt");

int main() 
{
	int TT;
	fin >> TT;

	for (int tt = 0; tt < TT; tt++)
	{
		string s;
		fin >> s;

		map <char, int> M;
		char st = 'A';
		for (int i = 0; i < 26; i++)
		{
			char cur = st + i;
			M[cur] = 0;
		}

		for (int i = 0; i < s.size(); i++)
		{
            M[s[i]]++;
		}

		vector <int> num;
		for (int i = 0; i < 10; i++)
			num.push_back(0);

		num[0] = M['Z'];
		M['R'] -= M['Z'];
		M['O'] -= M['Z'];
		num[2] = M['W'];
		M['O'] -= M['W'];
		num[4] = M['U'];
		M['F'] -= M['U'];
		M['O'] -= M['U'];
		M['R'] -= M['U'];
		num[3] = M['R'];
		num[5] = M['F'];
		M['I'] -= M['F'];
		num[6] = M['X'];
		M['S'] -= M['X'];
		M['I'] -= M['X'];
		num[7] = M['S'];
		num[8] = M['G'];
		M['I'] -= M['G'];
		num[9] = M['I'];
		num[1] = M['O'];

		string res="";
		for (int i = 0; i < 10; i++)
		{
			if (num[i] > 0)
			{
				char te = '0' + i;
				for (int j = 0; j < num[i]; j++)
					res += te;
			}
		}
 
	    fout << "Case #" << tt + 1 << ": " << res << "\n";
	}

	return 0;
}

