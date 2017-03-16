#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_SIZE	1000010

fstream 	f, g;
long long 	longest[MAX_SIZE];
long long	cnt[MAX_SIZE];

bool isConsonant(char c)
{
	switch (c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		{
			return false;
		}

		default: return true;
	}

	return false;
}


long long solve(string s, long long n)
{
	long long 	res  = 0;
	long long 	last = -1;

	longest[s.size()] = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		longest[i] = (isConsonant(s[i])) ? (1 + longest[i+1]) : 0;
	}

	cnt[s.size()] = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		cnt[i] = (last != -1) ? cnt[last] : 0;

		if (longest[i] >= n)
		{
			if (last == -1)
			{
				cnt[i] = s.size() - 1 - (i + n - 1) + 1;
			}
			else
			{
				cnt[i] += last - i;
			}
		}

		if (longest[i] >= n) last = i;

		res += cnt[i];
	}

	return res;
}


int main()
{
	int			T;
	string 		s;
	long long 	n;

	f.open("in.txt",  ios :: in);
	g.open("out.txt", ios :: out);

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> s >> n;
		g << "Case #" << test << ": " << solve(s, n) << endl;
	}

	f.close();
	g.close();

	return 0;
}
