#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
int t,r,c,w;
int main()
{
	in >> t;
	for (int i=1;i<=t;i++) {
		in >> r >> c >> w;
		int g = c/w*r;
		g += w-1;
		if (c%w != 0) g++;
		out << "Case #" << i << ": " << g << "\n";
	}
	return 0;
}
