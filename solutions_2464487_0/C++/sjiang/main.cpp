#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
using namespace std;

int main(int argc, char * argv[])
{
	ifstream fin("input.txt"); 
	ofstream fout("output.txt");
	
	if(!fin.good())
	{
		cout << "opps" << endl;
	}
	string str;
	getline(fin, str);
	
	const int T = atoi(str.c_str());

	for( int aaa = 0; aaa < T ; aaa++)
	{
		//	Load everything!!
		istringstream iss(str);
		getline(fin, str);		iss.clear(); iss.str(str);
		
		unsigned long long t, r, a;
		iss >> r >> t;
		int bbb = 0;
		for (bbb = 0; bbb < 707106780; ++bbb)
		{
			unsigned long long paint = 2*bbb*bbb + bbb*(2*r-1);
			if (paint > t)
			{
				break;
			}

		}

		fout << "Case #" << aaa+1 << ": " << bbb-1 << endl;
		//fout << fixed << setprecision(6) << "Case #" << aaa+1 << ": " << setprecision(6) << static_cast<double>( minKey )<< setprecision(6) <<  endl;

	}	

	fin.close(); fout.close();
	return 0;
}
