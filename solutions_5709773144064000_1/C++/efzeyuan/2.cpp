#include<iostream>
#include<fstream> 
#include <iomanip>
using namespace std;

int main()
{
	ifstream f1;
	ofstream f2;
	f1.open("E:\\code jam\\q2\\B-large.in");
	f2.open("E:\\code jam\\q2\\1.out");
	int n;
	bool flag;
	f1>>n;
	double target,current,arrival,update,produce;
	double c,f,x;
	int i;
	for (i=1;i<=n;i++)
	{
		f1>>c>>f>>x;
		flag=true;
		current=0;
		produce=2;
		target=x/produce;
		while (flag)
		{
			arrival=current+c/produce;
			update=arrival+x/(produce+f);
			if (update<target)
			{
				target=update;
				current=arrival;
				produce=produce+f;
			}
			else flag=false;
		}
		f2<<setiosflags(ios::fixed);
		f2<<setprecision(7);
		f2<<"Case #"<<i<<": "<<target<<endl; 
		
	}
}
