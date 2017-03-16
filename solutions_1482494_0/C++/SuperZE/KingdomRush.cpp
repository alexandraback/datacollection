// KingdomRush.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <queue>
#include <vector>

using namespace std;

struct level
{
	int s1;
	int s2;
	bool d1;
	bool d2;
};

/*struct comp
{
	bool operator()(level &l1, level &l2)
	{
		if (l1.s2 == l2.s2 && !l1.d1 && !l2.d1)
			return l1.s1 > l2.s1;
		else if (l1.d1 && !l2.d1)
			return false;
		else if (!l1.d1 && l2.d1)
			return true;
		return l1.s2 > l2.s2;
	}
};*/

bool next(vector<level> &l, int stars, level* &a)
{
	bool found = false;
	for (vector<level>::iterator i = l.begin(); i != l.end(); i++)
	{
		if (!(*i).d2 && (*i).s2 <= stars)
		{
			a = &(*i);
			return true;
		}
		else if (!(*i).d2 && !(*i).d1 && (*i).s1 <= stars)
		{
			if (!found)
			{
				a = &(*i);
				found = true;
			}
			else
			{
				if (a->s2 < (*i).s2)
					a = &(*i);
			}
		}
	}
	return found;
}

bool empty(vector<level> &l)
{
	for (vector<level>::iterator i = l.begin(); i != l.end(); i++)
		if (!(*i).d2)
			return false;
	return true;
}

int main(int argc, char* argv[])
{
	int t, n, stars;
	cin>>t;
	for (int i = 1; i <= t; i++)
	{
		//priority_queue<level, vector<level>, comp> l;
		vector<level> l;
		bool bad = false;
		int count = 0;
		cin>>n;
		stars = 0;
		for (int j = 0; j < n; j++)
		{
			level a;
			cin>>a.s1>>a.s2;
			a.d1 = a.d2 = false;
			l.push_back(a);
		}
		while (!empty(l) && !bad)
		{
			level *a = 0;
			if (next(l, stars, a))
			{
				if (stars >= a->s2)
				{
					stars += (a->d1 ? 1 : 2);
					a->d2 = true;
					count++;
				}
				else if (stars >= a->s1 && !a->d1)
				{
					stars += 1;
					a->d1 = true;
					count++;
				}
			}
			else
				bad = true;
		}
		if (bad)
			cout<<"Case #"<<i<<": Too Bad"<<endl;
		else
			cout<<"Case #"<<i<<": "<<count<<endl;
	}
	return 0;
}

