#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>
using namespace std;

long long e1(long long r, long long t, long long rings) {
	long long t0 = 0;
	for (long long i=0; i<rings; ++i)
	{
		t0 += 2*r+1;
		r += 2;
	}
	return t0;
}

bool e2(long long r, long long t, long long rings) {
	if (t/rings < (2 * r - 1))
		return true;
	if (t/rings < 2 * rings)
		return true;
	return rings * (2 * r - 1 + 2*rings) > t;
}

long long processCase(istream &in)
{
	long long r, t;
	in >> r >> t;
	/*
	for (int i=0; i<1000; ++i)
	{
		if (e1(r, t, i) > t)
			return i-1;
	}
	*/
	long long fail = 1;
	fail <<= 31;
	long long succeed = 0;
	long long test;
	while (fail - succeed > 1)
		{
		test = (succeed + fail) / 2;
		if (e2(r, t, test))
			fail = test;
		else
			succeed = test;
		}
	return succeed;
}

void process(istream &in, ostream &out, bool trace=false)
{
	int cases;
	in >> cases;
	for (int i=1; i<=cases; ++i)
	{
		if (trace)
			cerr << "Case " << i << "/" << cases << endl;
		out << "Case #" << i << ": " << processCase(in) << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		process(cin, cout, true);
	}
	else if (argc == 2)
	{
		ifstream in(argv[1], ifstream::in);
		process(in, cout);
	}
	return 0;
}
