#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;



void main()
{

	int T=0;
	//ifstream in("test1.txt");
	ifstream in("A-small-attempt0.in");
	ofstream save("result1.txt");
	in >> T;

	for(int p=0 ; p<T;p++)
	{
		long long r = 0;
		long long t = 0;
		in >> r;
		in >> t;
		int i = 0;
		int count = 0;
		while(t>=0)
		{
			t = t-2*r-1-4*i;
			i++;
			count++;
		}
	
		save << "Case #"<<p+1<<": "<<count-1 << "\n";

	}
	in.close();
	save.close();
}
