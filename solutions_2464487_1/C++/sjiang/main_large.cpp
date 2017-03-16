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
		bool trying = true;

		unsigned long long min_val, max_val;
		min_val = 0;
		max_val = 707106781;
		unsigned long long bbb = 707106780/2;
		unsigned long long paint = 2*bbb*bbb + bbb*(2*r-1);
		while(trying)
		{
			paint = 2*bbb*bbb + bbb*(2*r-1);
			cout << bbb << " " << min_val << " " << max_val << endl;

			if (paint > t)
			{
				max_val = bbb - 1;
				bbb = (min_val + max_val )/ 2;
			}
			else 
			{
				min_val = bbb + 1;
				bbb = (max_val+min_val) / 2;
			}
			if (min_val >= max_val - 2 )
			{
				break;
			}
		}

		cout << "HI" << endl;
		bbb = max_val + 1;
		while(trying)
		{
			paint = 2*bbb*bbb + bbb*(2*r-1);
			if ( paint > t)
			{
			}
			else 
			{
				break;
			}

			--bbb;
		}

		

		fout << "Case #" << aaa+1 << ": " << bbb << endl;
		//fout << fixed << setprecision(6) << "Case #" << aaa+1 << ": " << setprecision(6) << static_cast<double>( minKey )<< setprecision(6) <<  endl;

	}	

	fin.close(); fout.close();
	return 0;
}
