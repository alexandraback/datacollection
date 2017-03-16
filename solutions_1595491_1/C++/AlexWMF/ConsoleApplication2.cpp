// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int S;
static int p;


bool hasSurpising() 
{
	return S > 0;
}

bool vv( int param1, int total ) 
{
	double d = double(param1) / 3;
	if (d >= total)
		return true;
	else if (d == 0)
		return false;
	else
	{
		d = total - d;
		if (d < 1.0)
			return true;
		else if (hasSurpising() && d < 1.5)
		{
			--S;
			return true;
		}
	}
	return false;
}

void process(int num, const vector<int>& v)
{
	cout << "Case #" << num + 1 << ": ";
	int cnt(0);
	int val;

	for (unsigned i = 0; i < v.size(); ++i)
	{
		val = v[i];

		if (vv(val, p))
			++cnt;
	}
	cout << cnt;

	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int count(0);
	cin >> count;
	int N;

	vector<int> v;
	int tmp;

	for (int i = 0; i < count; ++i)
	{
		cin >> N >> S >> p;
		v.clear();
		for (int e = 0; e < N; ++e)
		{
			cin >> tmp;			
			v.push_back(tmp);
		}
		process(i, v);
	}

	return 0;
}

