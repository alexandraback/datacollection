#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <string>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FN "gcj1c_b"

int main()
{
	
	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;
	for(int i = 0; i < t; i++)
	{
		out << "Case #" << (i+1) << ": ";
		 int x, y;
		 in >> x >> y;
		 if(x < 0)
		 {
			 for(int i = 0; i < -x; i++)
			 {
				 out << "EW";
			 }
		 } else {
			 for(int i = 0; i < x; i++)
			 {
				 out << "WE";
			 }
		 }

		 if(y < 0)
		 {
			 for(int i = 0; i < -y; i++)
			 {
				 out << "NS";
			 }
		 } else {
			 for(int i = 0; i < y; i++)
			 {
				 out << "SN";
			 }
		 }
		 out << "\n";
	}

	out.close();
	return 0;
}