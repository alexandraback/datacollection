#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
using namespace std;

int main(int argc, char * argv[])
{
	ifstream fin("input.txt"); 
	if(!fin.good())
	{
		cout << "opps" << endl;
	}
	string str;
	getline(fin, str);
	
	const int N = atoi(str.c_str());

	ofstream fout("output.txt");
	for( int aaa = 0; aaa < N ; aaa++)
	{
		getline(fin, str);
		istringstream iss(str);
		int T;
		iss >> T;
		cout << "A: " << T << endl << endl;
		vector<int> scores;
		for(int bbb = 0; bbb < T; bbb++)	
		{
			int B;
			iss >> B;
			scores.push_back(B);
			cout << B << endl;
		}

		int X = accumulate(scores.begin(), scores.end(), 0);
		cout << X;
		int always_total = X;
		vector<double> percent(T,-1);
		bool flag = true;
		int curr_total = X;
		int Tnew = T;
		while(flag)
		{
		cout << " HI\n";
			bool flag_update = false; int new_curr;
			for(int bbb = 0; bbb < T; bbb++)
			{
				if(percent[bbb]!=0){
					double Y = 100*((always_total + static_cast<double>(curr_total))/Tnew - scores[bbb])/always_total;
					cout << curr_total << endl;
					cout << Tnew << endl;
					cout << scores[bbb] << endl;
					cout << Y << endl << endl;
					if(Y < 0)
					{
						percent[bbb] = 0;
						flag_update = true;

						new_curr = curr_total - scores[bbb];
						Tnew--;
						break;
					}
				else
					percent[bbb] = Y;
				}
			}
			if(flag_update)
				curr_total = new_curr;
			else
				flag = false;
		}
		fout.precision(5);
		fout << "Case #" << aaa+1 << ": " ;
		for(int bbb = 0; bbb < T; bbb++)
		{

			fout << fixed << setprecision(6) << percent[bbb] << setprecision(6) << " ";
			//fout << max(static_cast<double>( Y ),0.0) << " ";
		}
		fout << endl;
		//fout << fixed << setprecision(6) << "Case #" << aaa+1 << ": " << setprecision(6) << static_cast<double>( minKey )<< setprecision(6) <<  endl;

	}	

	fin.close(); fout.close();
	return 0;
}
