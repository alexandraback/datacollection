#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	int n,s[200],t;
	infile>>n;
	for (int i=0;i<n;i++)
	{
		int sum=0;
		infile>>t;
		for (int j=0;j<t;j++)
		{
			infile>>s[j];
			sum+=s[j];
		}
		int tt=t, ss=sum;
		for (int j=0;j<t;j++)
		{
			if (s[j]>=sum*2/t) 
			{
				tt--;
				ss=ss-s[j];
			}
		}
		outfile<<"Case #"<<i+1<<": ";
		for (int j=0;j<t; j++)
			if (s[j]<sum*2/t)
		{
			double ans=(sum+ss)/((double)tt*sum);
			if (ss!=0)  ans=ans-(double)s[j]/(double)sum;
			ans=ans*100;
			if (ans<0) ans=0;
			outfile.setf(ios::showpoint);
			outfile.precision(6);
			outfile<<ans<<' ';
		}
			else outfile<<"0.000000 ";
		outfile<<endl;
	}


	infile.close();
	outfile.close();
	return 0;
}