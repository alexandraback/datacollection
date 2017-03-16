/*
	Michał Gańczorz
	code jam 2015
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <queue>
#include <list>
#include <sstream>
 // #include <unistd.h>
// #include <unordered_map>

#define ll long long

using namespace std;


int pi(string x)
{
	int mx = 0;
	for(int i=1; i<x.length(); ++i)
	{
		bool ok = 1;
		for(int j=i; j<x.length(); ++j)
			if(x[j-i] != x[j])
			{
				ok = false;
				break;
			}

		if(ok)
			return x.length()-i;
	}

	return 0;
}


int ppbs[255];

void solve(int z)
{
	int res = 10;
	int k, l, s;
	
	string keys, word;
	
	cin>>k>>l>>s;
	cin>>keys>>word;

	int psl = pi(word);
	int mxocc = 0;
	if(word.length() <= s)
	{

		mxocc = 1;
		int okres = word.length() - psl;
		int cl = word.length();
		// cout<<psl<<"\n";
		while(cl + okres <= s)
		{
			cl += okres;
			mxocc++;
		}

		// if(psl != 0)
			// mxocc = ((s-word.length())/psl) + 1;
		// else
			// mxocc = s/word.length();
	}

	// return;

	for(int i=0; i<255; ++i)
		ppbs[i] = 0;

	for(int i=0; i<keys.length(); ++i)
		ppbs[keys[i]]++;


	bool caneven = 1;
	for(int i=0; i<word.length(); ++i)
		if(ppbs[word[i]] == 0)
			caneven = 0;

	if(caneven == 0)
	{
		cout<<"Case #"<<z<<": "<<"0.0"<<"\n";
		return;
	}

	long double ex = s-word.length()+1;
	long double kl = keys.length();
	// cout<<double(ex)<<"\n";
	for(int i=0; i<word.length(); ++i)
	{
		ex = ex*(ppbs[word[i]]/ kl );
		// if(ppbs[word[i]] == 0)
			// cout<<"czekolada"<<"\n";
	}
	double dd = mxocc-ex;
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(10);
	// cout<<mxocc<<"\n";
	cout<<"Case #"<<z<<": "<<dd<<"\n";
}

int main()
{
	// string str = "abab";
	// cout<<pi(str)<<"\n";

	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
		solve(i);
	
	return 0;
}