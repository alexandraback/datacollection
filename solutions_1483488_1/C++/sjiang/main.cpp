#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> convert2digits(const int input)
{
	vector<int> retVec;
	int divisor = 1;
	while(divisor <= input)
	{
		//cout << ((input/divisor) % 10)<< endl;
		retVec.push_back((input / divisor) % 10);
		divisor *= 10;
	}
	return retVec;


}
int main(int argc, char * argv[])
{
	//ifstream fin("input.txt"); 
	//ifstream fin("C-small-attempt0.in"); 
	ifstream fin("C-large.in"); 
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
		vector<int> temp = convert2digits(A);
		int nNumDigits = temp.size();
		int RP(0); 
		for( int bbb = A; bbb <= B; bbb++ )
		{
			vector<int> digits = convert2digits(bbb);
			vector<int> shift_values;
			for(int ccc = 1; ccc < nNumDigits; ccc++)
			{
				int temp = 0; int nMultiply = 1;
				for(int ddd=0; ddd< nNumDigits; ddd++)
				{
					temp = temp + digits.at((ddd + ccc)%nNumDigits) * nMultiply;
					nMultiply *= 10;
				}
				if((temp >= A) && (temp <= B) && (temp != bbb))
				{
					if(find(shift_values.begin(), shift_values.end(), temp) == shift_values.end())
					{
						shift_values.push_back(temp);
						RP++; //cout << bbb<< "\t" << temp<< endl;;
					}
				}
			}
		}
		
		fout << "Case #" << aaa+1 << ": " << RP/2 << endl;	
	}	

	fin.close(); fout.close();
	return 0;
}
