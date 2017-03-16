//
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


double numcal(int A,int B,double* p )
{
	
	
	
	
	double num1=0.0,num2=0.0;
	double product=1.0;
	num1=1+B+1;
	double min=2*A+B-A+1;
	for (int n=0;n<A;n++)
	{
		product*=p[n];
		num2=2*(A-1-n)+B-A+1+(1-product)*(B+1);
		if(num2<min)
			min=num2;
	}

	

		
	 
	return (num1<min?num1:min);
}

int main()
{   
	
	
	ifstream fin("A-large.in");
	//ifstream fin("A-small-practice.in");
	//ifstream fin("B-large.in");
	int T;
	fin>>T;
	//cout<<T;
	ofstream fout("A-large.out");
	//ofstream fout("A-small-practice.out");
	//ofstream fout("B-large.out");	
	
	

	int A,B;
	

	cout <<setiosflags(ios::fixed);
cout <<setiosflags(ios::showpoint);
fout <<setiosflags(ios::fixed);
fout <<setiosflags(ios::showpoint);
	for (int n=1;!fin.eof();n++)
	{
		if (n%2==1)
		{fin>>A>>B;
		continue;}
		else
			{double* p=new double[A];
			for (int t1=0;t1<A;t1++)
		       fin>>p[t1];
			
			
		double num=numcal(A,B,p);
	    	
		fout<<"Case #"<<n/2<<": ";
		//cout<<setprecision (6)<<num<<endl;
		fout<<setprecision (6)<<num<<endl;
		delete []p;
		}
	}
	
	
	
	return 0;
}