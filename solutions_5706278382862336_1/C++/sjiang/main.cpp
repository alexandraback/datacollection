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


unsigned long long int gcf ( unsigned long long a, unsigned long long b)
{
	while ( b != 0)
	{
		unsigned long long int temp  = a;
		a = b;
		b = temp % b;
	}
	return a;
}



int bits (unsigned long long int A)
{
	int ret_bits = 0;
	while( A != 0)
	{
		A = A >> 1;
		ret_bits++;
	}
	return ret_bits;
}

bool pow2(unsigned long long int A)
{
	if(A & (A-1))
	{
		return false;
	}
	else 
		return true;
}
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
	
	//	Number of test cases.
	const int T = atoi(str.c_str());

	//	Loop across each file.
	for( int aaa = 0; aaa < T ; aaa++)
	{
		getline(fin, str);
		istringstream iss(str);


		//	getline(fin, str);		iss.clear(); iss.str(str);
		//	 Data
		string str_in;
		unsigned long long int P, Q;
		iss >> str_in;
		stringstream test(str_in);
		string segment;
		vector<unsigned long long int> A;
		while(std::getline(test, segment, '/'))
		{
			istringstream iss2(segment);
			unsigned long long int temp;
			iss2 >> temp;
			A.push_back(temp);
		}
		P = A[0]; Q = A[1];
		unsigned long long int PQ = gcf(P,Q);
		//	Divide one into other:
		P = P / PQ;
		Q = Q / PQ;

		int Pbits = bits(P);
		int Qbits = bits(Q);

		//cout << Pbits << " " << Qbits << endl;

		if (pow2(Q))
		{
		int fin_ans(Qbits - Pbits);
		fout << "Case #" << aaa+1 << ": " << fin_ans << endl;
		}
		else
		{
		fout << "Case #" << aaa+1 << ": " << "impossible" << endl;
		}
		//fout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<double>(prob)<< setprecision(10) <<  endl;

	}	

	fin.close(); fout.close();
	return 0;
}
