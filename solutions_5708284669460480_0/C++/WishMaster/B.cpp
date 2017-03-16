// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int subsearch(string str)
{
	for (int i = 1; i < str.length(); i++)
	{
		if (strncmp(str.data(), str.data() + i, str.length() - i) == 0)
		{
			return i;
		}
	}
	return str.length();
}

bool can_type(string str, string keys)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (keys.find(str[i]) == string::npos)
			return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fi("b.in");
	ofstream fo("b.out");

	int t;
	fi >> t;

	for (int i = 0; i < t; i++)
	{
		int k, l, s;
		fi >> k >> l >> s;
		string keys, word;
		getline(fi, keys);
		getline(fi, keys);
		getline(fi, word);

		double res = 0;
		if (can_type(word, keys))
		{
			int r = subsearch(word);
			int ban_cnt = (s - (word.length() - r)) / r;

			int keys_cnt[26];
			memset(keys_cnt, 0, sizeof(int)* 26);
			for (int j = 0; j < keys.length(); j++)
			{
				keys_cnt[keys[j] - 65]++;
			}
			
			double prob = 1;
			//double kcnt = keys.length();
			for (int j = 0; j < word.length(); j++)
			{
				char symb = word[j];
				prob = prob * keys_cnt[symb - 65];
				//prob = prob / kcnt;
			}
			double all_prob = pow(k, l);
			res = (1.0 - (prob / all_prob)) * ban_cnt;


			//res = (1 - prob) * ban_cnt;
		}

		fo << "Case #" << i + 1 << ": ";

		int x = res;
		double xx = x;
		if (fabs(xx - res) < 0.000001)
		{
			fo << fixed << setprecision(1) << res << endl;
		}
		else
		{
			fo.unsetf(ios_base::floatfield);
			fo << setprecision(6) << res << endl;
		}
	}

	fi.close();
	fo.close();

	return 0;
}
