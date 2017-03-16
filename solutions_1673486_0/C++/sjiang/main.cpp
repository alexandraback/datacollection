#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char * argv[])
{
	ifstream fin("input.txt"); 
	if(!fin.good())
	{
		cout << "opps" << endl;
	}
	string stCaseNum;
	getline(fin, stCaseNum);
	
	const int nCaseCount = atoi(stCaseNum.c_str());

	ofstream fout("output.txt");
	for( int aaa = 0; aaa < nCaseCount ; aaa++)
	{
		string str; 
		getline(fin, str);
		int A, B;
		istringstream iss(str);
		iss >> A;
		iss >> B;
		getline(fin, str);
		istringstream iss2(str);
		vector<double> prob_right;
		for(int bbb = 0; bbb < A; bbb++)
		{
			double temp;
			iss2 >> temp;
			prob_right.push_back(temp);
		}
//	hit enter right away
		double minKey = B+2.0;

//	Delete bbb chars
		for( int bbb = 0; bbb < A; bbb++ )
		{
			double prob_succeed = 1;
//	Compute prob you were right
			for(int ccc = 0; ccc< A - bbb; ccc++)
			{
				prob_succeed*= prob_right[ccc];
			}
			double newkey = prob_succeed * (B - A + 2*bbb + 1) + (1-prob_succeed)*(B - A +2*bbb + 1 + B + 1);
			minKey = min(newkey, minKey);	
		}
		
		//fout << "Case #" << aaa+1 << ": " << static_cast<double>( minKey )<< setprecision(6) <<  endl;
		cout.precision(6);
		//cout << fixed << setprecision(6) << "Case #" << aaa+1 << ": " << setprecision(6) << static_cast<double>( minKey )<< setprecision(6) <<  endl;
		fout.precision(6);
		fout << fixed << setprecision(6) << "Case #" << aaa+1 << ": " << setprecision(6) << static_cast<double>( minKey )<< setprecision(6) <<  endl;
	}	

	fin.close(); fout.close();
	return 0;
}
