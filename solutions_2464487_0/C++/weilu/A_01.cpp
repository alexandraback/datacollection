#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	ifstream in ("A-small-attempt2.in");
	ofstream out ("abcd.out" );

	int T;
	in >> T;
	int ii;
	for (int ii = 0; ii < T; ii++)
	{
		long long r;
		long long t;
		in >> r;
		in >> t;
		long long n = 1;
//		n = ( 1- 2*r + sqrt(long double( (2*r -1 )*(2*r- 1)+ 8*t ) ) )/4;
		while(1)
		{
			if (  (2*n - 1 + 2*r) > t/n ) 
				break;
			n++;
		}
		n--;
//		cout<< n <<endl;
		out<< "Case #"<<ii+1<<": "<<n<<endl;
	}
	return 0;
}