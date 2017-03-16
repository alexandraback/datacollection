// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

bool isVowel(char c)
{
	return 'a' == c || 'e' == c || 'i' == c || '0' == c || 'o' == c || 'u' == c;
}

bool isConsonants(char c)
{
	return !isVowel(c);
}

typedef std::pair<int, int> Interval;

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream in("A.in");

	int T;
	in >> T;

	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		std::string s; int n;
		in >> s >> n;


		std::vector<Interval> q;

		int v = 0, c = 0;
		for (int i = 0; i < n; ++i)
		{
			if (isVowel(s[i])) ++v;
			else ++c;
		}

		if (0 == v && n == c) q.push_back(Interval(0, n - 1));

		for (int i = n; i < s.size(); ++i)
		{
			if (isVowel(s[i]) != isVowel(s[i - n]))
			{
				if (isVowel(s[i])) { ++v; --c; }
				else { --v; ++c; }
			}

			if (0 == v && n == c) q.push_back(Interval(i - n + 1, i));
		}

		unsigned long long r = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			int l = 0, u = q.size() - 1;

			while (u > l + 1)
			{
				int m = (u + l)/2;
				if (q[m].first > i) u = m;
				else l = m;
			}

			int first = -1;
			if (!q.empty())
				if (q[l].first >= i) first = l;
				else if (q[u].first >= i) first = u;

			if (-1 != first)
				r += s.size() - q[first].second;
		}

		std::cout << "Case #" << testNumber << ": " << r << "\n";

	}

	return 0;
}

