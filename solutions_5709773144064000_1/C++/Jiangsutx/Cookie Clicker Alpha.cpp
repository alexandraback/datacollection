#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("B-large-out.txt");		
	ifile.open("B-large.in");			
	//ifile.open("B-small.txt");	

	long T;
	double C = 0, F = 0, X = 0;
	
	ifile>>T;
	for (int iT=1; iT<=T;iT++)
	{
		ifile>>C>>F>>X;
		double time = 0.0, money = 0.0, rate = 2.0;;
		while (X > money)
		{
			if (X<=C)
			{
 				time += (X-money)/rate;
				money = X;
				break;
			}
			
			if (money<C)
			{
				time += (C-money)/rate;
				money = C;
			}
			else if (X-money>rate*C/F)
			{
				rate += F;
				money -= C;
			}
			else
			{
				time += (X-money)/rate;
				money = X;
			}
		}
		ofile.setf(ios::fixed); 
		ofile<<setprecision(7)<<"Case #"<<iT<<": "<<time<<endl;
	}
	ifile.close();
	ofile.close();
	system("pause");
}