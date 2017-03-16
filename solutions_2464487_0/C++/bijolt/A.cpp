#include <iostream>
#include <fstream>
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
	int count = 0;
	double r, t;
	fi >> r >> t;
	while( t>0)
	{
		t -= (r+1)*(r+1) - r*r;
		if( t >= 0) count++;
		r = r+2;
	}
fo << "Case #" << i << ": " << count << endl;
}


fi.close();
fo.close();
}
