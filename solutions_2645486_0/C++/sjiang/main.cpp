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
		int E, R, N;
		vector<int> v;
		//	Load everything!!
		getline(fin, str);
		istringstream iss(str);
		iss >> E >> R >> N;
		if (R > E)
		{ R = E;}
		getline(fin, str);		iss.clear(); iss.str(str);

		for (int bbb = 0 ; bbb < N; ++bbb)
		{
			int temp;
			iss >> temp;
			v.push_back(temp);
		}

		int dp_table[12][11];
		for(int bb1 = 0; bb1 < E+1; ++bb1) 
		{
			int energy_before = max(bb1 - R,0);
			dp_table[0][bb1] = v[0] * (E - energy_before);

		}
		for(int aa1 = 1; aa1 < N; ++aa1) 
		{
			for(int bb1 = 0; bb1 < E+1; ++bb1) 
			{
				int energy_before = max(bb1 - R,0);
				dp_table[aa1][bb1] = dp_table[aa1-1][energy_before] ;
				for(int cc1 = energy_before ; cc1 < E+1 ; ++cc1)
				{

					dp_table[aa1][bb1] = max (dp_table[aa1-1][cc1] + v[aa1]* (cc1 - energy_before ),
						dp_table[aa1][bb1]) ;
				}
				
			}
		}

		for(int aoeu1 = 0; aoeu1 < N; ++aoeu1) 
		{
			for(int aoeu2 = 0; aoeu2 < E+1; aoeu2++) 
			{
				cout << dp_table[aoeu1][aoeu2] << " ";
			}
			cout << endl;
		}
		
			cout << endl;
			cout << endl;
			cout << endl;
			
		

int ans = -1;
		for(int bbb = 0 ; bbb < E+1; ++bbb)
		{
			ans = max(ans, dp_table[N-1][bbb]);
		}
		
		fout << "Case #" << aaa+1 << ": " << ans <<  endl;
		//fout << fixed << setprecision(6) << "Case #" << aaa+1 << ": " << setprecision(6) << static_cast<double>( minKey )<< setprecision(6) <<  endl;

	}	

	fin.close(); fout.close();
	return 0;
}
