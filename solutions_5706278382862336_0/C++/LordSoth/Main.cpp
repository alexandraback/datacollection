#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct numo
{
	double value;
	bool naomi;
};

/*vector<char> getType(string s)
{
	vector<char> result;
	int count;
	result.push_back(s[0]);
	for(int i = 1; i < s.length; i++)
	{
		if(s[i] != result.back)
		{
			result.push_back(s[i]);
		}
		else
	}
	return result;
}*/


int main()
{
	string line, a, b;
	ifstream myfile ("test.txt");
	ofstream ofile;
	int numOfTestCases = 0;
	int n;
	int result = 0;
	double p, q;
	vector<vector<char>> table;
	ofile.open("result.txt");
	ofile.precision(7);
	ofile.setf( std::ios::fixed, std:: ios::floatfield );
	if (myfile.is_open())
	{
		getline(myfile, line);
		numOfTestCases = atoi(line.c_str());
		for(int i = 0; i < numOfTestCases; i++)
		{	
			getline(myfile, line);
			string tmp = line;
			n = line.find("/");
			p = atof(line.substr(0,n).c_str());
			q = atof(line.c_str() + n + 1);

			while(p < q)
			{
				p = p*2;
				result++;
			}
			int count = 0;
			while(count < 40 && p != q)
			{
				if( p > q )
				{
					p -= q;
				}
				else
				{
					p *= 2;
				}
				count++;
			}
			if(p != q)
				result = -1;
			/*if(p != q)
			{
				bool doNotCalc = false;
				double num = (q / (p - q));
				if( floor(num) != num )
				{
					result = -1;
					doNotCalc = true;
				}
				int numa = (int) num;
				bool powerOfTwo = !(numa == 0) && !(numa & (numa - 1));
				if( !doNotCalc && p != q && !powerOfTwo)
				{
					result = -1;
				}
			}*/
			
			if(result == -1)
			{
				ofile << "Case #" << i + 1 << ": impossible" << endl;
			}
			else
			{
				ofile << "Case #" << i + 1 << ": " << result << endl;
			}
			result = 0;
		}
		myfile.close();
	}

	else cout << "Unable to open file"; 
	ofile.close();
	return 0;
}


