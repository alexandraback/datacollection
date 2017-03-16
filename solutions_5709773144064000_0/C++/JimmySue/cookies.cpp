#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream infile("B-small-attempt1.in");
	ofstream outfile("B1.OUT");
	int Case;
	infile >> Case;
	double c,f,x;
	double n;
	int maxn;
	double time;
	for (int i = 1; i < Case +1; i++)
	{
		time = 0.0;
		infile >> c >> f >> x;
		n = (double)(x*f - 2*c)/(c*f) -1.0;
		maxn = n +1;
		maxn = max(maxn,0);
		for(int j = 0; j < maxn; ++j)
		{
			time += (double)c/(2.0+ j * f);
		}
		time += (double)x/(2.0+maxn*f);
		outfile << "Case #" << i << ": " ;
		outfile.precision(7);
		outfile.setf(std::ios::fixed,std::ios::floatfield);
		outfile << time << '\n';
	}

}