#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

long long best_diff;
long long score_coders;
long long score_jammers;
string best_coders;
string best_jammers;

long long getNumber(const string& s)
{
	long long res = 0;
	for (unsigned i=0; i<s.size(); i++)
		res = 10 * res + (s[i] - '0');
	return res;
}

void doit(string coders, string jammers, unsigned pos, bool equal, bool minCoders)
{
	//cerr << "considering " << coders << " " << jammers << " " << pos << " " << equal << " " << minCoders << endl;
	if (pos == coders.size())
	{
		long long score1 = getNumber(coders);
		long long score2 = getNumber(jammers);
		long long diff = std::abs(score1 - score2);
		if (   best_diff == -1
		    || (diff < best_diff)
		    || (diff == best_diff && score1 < score_coders)
			|| (diff == best_diff && score1 == score_coders && score2 < score_jammers)
		   )
		{
			best_diff = diff;
			score_coders = score1;
			score_jammers = score2;
			best_coders = coders;
			best_jammers = jammers;
		}
		return;
	}
	if (!equal)
	{
		if (coders[pos] == '?')
			coders[pos] = (minCoders ? '0' : '9');
		if (jammers[pos] == '?')
			jammers[pos] = (minCoders ? '9' : '0');
		doit(coders, jammers, pos+1, equal, minCoders);
		return;
	}
	if (coders[pos] != '?' && jammers[pos] != '?')
	{
		doit(coders, jammers, pos+1, coders[pos]==jammers[pos], coders[pos]>jammers[pos]);
		return;
	}
	if (coders[pos] == '?' && jammers[pos] != '?')
	{
		coders[pos] = jammers[pos];
		doit(coders, jammers, pos+1, true, minCoders);
		if (jammers[pos] != '9')
		{
			coders[pos] = jammers[pos] + 1;
			doit(coders, jammers, pos+1, false, true);
		}
		if (jammers[pos] != '0')
		{
			coders[pos] = jammers[pos] - 1;
			doit(coders, jammers, pos+1, false, false);
		}
		return;
	}
	if (coders[pos] != '?' && jammers[pos] == '?')
	{
		jammers[pos] = coders[pos];
		doit(coders, jammers, pos+1, true, minCoders);
		if (coders[pos] != '9')
		{
			jammers[pos] = coders[pos] + 1;
			doit(coders, jammers, pos+1, false, false);
		}
		if (coders[pos] != '0')
		{
			jammers[pos] = coders[pos]-1;
			doit(coders, jammers, pos+1, false, true);
		}
	}
	if (coders[pos] == '?' && jammers[pos] == '?')
	{
		coders[pos] = jammers[pos] = '0';
		doit(coders, jammers, pos+1, true, minCoders);
		coders[pos] = '0';
		jammers[pos] = '1';
		doit(coders, jammers, pos+1, false, false);
		coders[pos] = '1';
		jammers[pos] = '0';
		doit(coders, jammers, pos+1, false, true);
		return;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		string coders, jammers;
		cin >> coders >> jammers;
		best_diff = -1;
		doit(coders, jammers, 0, true, true);
		cout << "Case #" << t << ": " << best_coders << " " << best_jammers << endl;
	}
    return 0;
}