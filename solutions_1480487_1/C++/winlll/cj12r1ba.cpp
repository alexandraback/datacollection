#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("a.in");
	fout.open("a.out");
	int tr,rnd;
	int n,m,i,j,sum;
	int c[5000];
	double a[5000],p[5000];
	bool b[5000];
	double t;
	fin>>tr;
	fout<<fixed<<setprecision(6);
	for (rnd=1;rnd<=tr;rnd++)
	{
		fin>>n;
		for (i=0;i<n;i++)
			fin>>c[i];
		sum=0;
		for (i=0;i<n;i++)
			sum=sum+c[i];
		for (i=0;i<n;i++)
			p[i]=double(c[i])/sum;
		m=n;
		t=double(2)/n;
		for (i=0;i<n;i++)
			b[i]=false;
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (p[j]>t && !b[j])
				{
					//fout<<i<<' '<<j<<' '<<t<<endl;
					b[j]=true;
					m--;
					t=t-(p[j]-t)/m;
				}
		for (i=0;i<n;i++)
			if (p[i]>t)
				a[i]=0.0;
			else
				a[i]=(t-p[i])*100.0;
		fout<<"Case #"<<rnd<<":";
		for (i=0;i<n;i++)
			fout<<' '<<a[i];
		fout<<endl;
	}
	fin.close();
	fout.close();
}