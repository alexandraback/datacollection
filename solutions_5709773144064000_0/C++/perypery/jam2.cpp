#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
	//ifstream fin("in");
	//ofstream fout("out");
	istream &ist=cin;
	ostream &ost=cout;
	int T;
	double C,F,X;
	ist>>T;
	for(int i=1;i<=T;i++)
	{
		int n=0;
		ist>>C>>F>>X;
		double m=(X*F-C*F-2*C)/(C*F);
		if(m<=0)
			n=0;
		else
			n=ceil(m);
		//cout<<n<<endl;
		double sum=X/(2+n*F);
		for(int j=0;j<n;j++)
			sum+=C/(2+j*F);
		ost<<"Case #"<<i<<": ";
		ost.setf(ios::fixed);
		ost.precision(7);
		ost<<sum<<endl;
	}
	return 0;
}
/*
1
500.0 4.0 2000.0
*/