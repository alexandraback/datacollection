#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{

ifstream fi;
ofstream fo;
fi.open("input.in");
fo.open("output.in");

int T;
fi >> T;
for (int i=1; i<=T; i++)
{
	double bigcount = 0;
	long double r, t;
	fi >> r >> t;
//solve the equaton:
// n = -(2r-1) + sqrt(4r2 - 4r + 1 +8t) / 4
	bigcount = -(2*r - 1);
	bigcount += sqrt(8*t + bigcount*bigcount);
	bigcount /= 4;	

long long int count = bigcount;
 if ((count*(2*r-3)+2*count*(count+1)) > t) count -= 1;
fo << "Case #" << i << ": " << count << endl;
}


fi.close();
fo.close();
}
