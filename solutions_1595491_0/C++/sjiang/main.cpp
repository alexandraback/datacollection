#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>


using namespace std;


int main(int argc, char * argv[])
{
	ifstream fin("B-small-attempt0.in"); 
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
		string str, sub;
		int N, S, p;
		getline(fin, str);
		istringstream iss(str);
		iss >> N;
		iss >> S;
		iss >> p;
		int max_greater(0);
		for (int bbb = 0; bbb< N ; bbb++)
		{
			int t;
			iss >> t;
			if((t >= 3*p - 2) && (t >= p))
			{
				max_greater++;
			}
			else if((t >= 3*p - 4) && (S) && (t>=p))
			{
				max_greater++; S--;
			}

		}	
		fout << "Case #" << aaa+1 << ": " << max_greater << endl;	
	}	

	fin.close(); fout.close();
	return 0;
}
