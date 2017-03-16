#include <iostream>
#include <algorithm>
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
		getline(fin, str);
		istringstream iss(str);
		//	Input data
		int A, N;
		vector<int> mote_sizes;
		//	Load everything!!
		iss >> A >> N;

		getline(fin, str);		iss.clear(); iss.str(str);
		for (int bbb = 0 ; bbb < N; ++ bbb)
		{
			int temp_int;
			iss >> temp_int;
			mote_sizes.push_back(temp_int);
		}

		sort (mote_sizes.begin() , mote_sizes.end());

		//	Simulate
		int add_count =0;
		for(int bbb= 0 ; bbb < N ; ++ bbb)
		{
			int temp_add_count(0); int A1 = A;
			while ((A1 <= mote_sizes[bbb]) && (temp_add_count < N - bbb))
			{
				A1 += A1 - 1;
				temp_add_count++;
			}
			A1 += mote_sizes[bbb];
			if(temp_add_count < N - bbb)
			{
				add_count += temp_add_count;
				A = A1;
			}
			else
			{
				add_count += N - bbb;
				break;
			}
		}

		if(add_count > N)
		{
			add_count = N;
		}

		fout << "Case #" << aaa+1 << ": " << add_count << "\n";
		//fout << fixed << setprecision(6) << "Case #" << aaa+1 << ": " << setprecision(6) << static_cast<double>( minKey )<< setprecision(6) <<  endl;
	}	

	fin.close(); fout.close();
	return 0;
}
