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

long long processCase(istream &in)
{
	long long r, t;
	in >> r >> t;
	long long i=0;
	while (2*r+1 <= t) {
		++i;
		t -= 2*r+1;
		r+=2;
	}
	return i;
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
