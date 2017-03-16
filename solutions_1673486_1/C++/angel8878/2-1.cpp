#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
	ifstream file;
	file.open("A-large.in");
	ofstream output;
	output.open("result.out");
	output.setf(ios_base::fixed, ios_base::floatfield);
	output.precision(10);

	int caseNo;
	file >> caseNo;

	for(int t=1; t<= caseNo; t++)
	{
		int inputed, total;
		file >> inputed >> total;

		long double totalProb=1.0;
		long double result=999999.9;
		long double prob, cache;
		for(int n=0; n<inputed; n++)
		{
			file >> prob;
			totalProb*=prob;
			cache=totalProb*(long double)(inputed-(n+1)+total-(n+1)+1)+(1-totalProb)*(long double)(inputed-(n+1)+total-(n+1)+1+total+1);
			if(cache<result) result=cache;
		}
		if(result>total+2) result=total+2;

		output << "Case #" << t << ": ";
		output <<  result << endl;

	}
}