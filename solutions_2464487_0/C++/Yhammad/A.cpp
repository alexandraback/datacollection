#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<string.h>
#include<utility>
#include<stdlib.h>
#include<cstdio>
using namespace std;
int main()
{
	ifstream in ("A-small-attempt0 (1).in");
	ofstream out ("output.txt");
	int  test, t, r;
	in >> test;
	for (int z = 1; z <= test; ++ z)
	{
		in >> r >> t;
		long double n = 0;
		n += (1 - 2*r);
		n += sqrt((2*r - 1) * (2*r - 1) + 8.0 * t);
		n /= 4.0;
		out << "Case #" << z << ": " << (long long)n << endl;
	}
	return 0;
}