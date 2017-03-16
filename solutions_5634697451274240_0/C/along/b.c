#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<pair<string,int>, int> best;

int calc(string s, int target)
{
	int i,j,k;
	if (best.find(make_pair(s, target)) != best.end())
		return best[make_pair(s, target)];
	best[make_pair(s, target)] = 1000000;
	int r=1000000;
	for(i=s.size()-1; i>=0; i--)
		if (s[i] != s[s.size()-1])
			break;
	if (i < 0)
	{
		if (s[s.size()-1] == '0' + target)
			r = 0;
		else
			r = 1;
	}
	else
	{
		if (s[s.size()-1] == '0' + target)
		{
			string s1 = s.substr(0, i+1);
			r = min(r, calc(s1, target));
		}
		else
		{
			string s1 = s.substr(0, i+1);
			r = min(r, calc(s1, !target)+1);
		}
	}
	string s1 = s;
	reverse(s1.begin(), s1.end());
	r = min(r, calc(s1, !target)+1);

//	printf("%s %d: %d\n", s.c_str(), target, r);
	best[make_pair(s, target)] = r;
	return r;
}

int main()
{
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		string S;
		cin >> S;
		for(int i=0; i<S.size(); i++)
		{
			if (S[i] == '+') S[i] = '1';
			else S[i] = '0';
		}
		best.clear();
		printf("Case #%d: %d\n", cc, calc(S, 1));
	}
}
