#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("c.in");
	ofstream fout;
	fout.open("c.out");
	int tc,round,a,b,i,m,v,j,k,tot,t;
	bool flag;
	int x[12];

	fin>>tc;
	for (round=0;round<tc;round++)
	{
		fin>>a>>b;
		if (a<12)
			a=12;
		tot=0;
		for (i=a;i<b;i++)
		{
			v=i;
			m=1;
			//flag=true;
			while (v/m>0)
			{
				//if (v/m%10==0)
				//	flag=false;
				m=m*10;
			}
			//if (!flag)
			//	continue;
			j=0;t=10;
			while (t<m)
			{
				x[j]=v/t+v%t*(m/t);
				if (x[j]>i && x[j]<=b)
				{
					k=0;
					while (x[k]!=x[j] && k<=j)
						k++;
					if (k==j)
						tot++;
				}
				j++;t=t*10;
			}
		}
		fout<<"Case #"<<round+1<<": "<<tot<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}