#include "iohelper.h"
#include <set>
#include <sstream>
using namespace std;

vector<double> result0;

void readFunc0(ifstream& in)
{
	double C,F,X;
	in>>C>>F>>X;
	double s = 2;
	double time = 0;
	while(true)
	{
		double t1 = X/s;
		double t2 = C/s + X/(F+s);
		if(t1 < t2)
		{
			result0.push_back(time+t1);
			break;
		}else{
			time += C/s;
			s += F;
		}
	}
}

int main()
{
	IOHelper io;
	io.readFile("B-small-attempt0.in",readFunc0);
	io.writeFile("B-small-attempt0.out",result0);
	return 0;
}