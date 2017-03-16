#include<fstream>
using namespace std;

bool c[1000001];

int main()
{
	ifstream fin;
	fin.open("c.in");
	ofstream fout;
	fout.open("c.out");
	int tr,rnd,i,j,tot;
	long long n,v;
	for (i=2;i<1000001;i++)
		c[i]=true;
	for (i=2;i<1001;i++)
		if (c[i])
			for (j=i;j<1000001 / i;j++)
				c[i*j]=false;
	fin>>tr;
	for (rnd=1;rnd<=tr;rnd++)
	{
		fin>>n;
		if (n>1)
			tot=1;
		else
			tot=0;
		for (i=2;i<1000001;i++)
			if (c[i])
			{
				v=i;j=0;
				while (v<=n)
				{
					v=v*i;j++;
				}
				if (j>1)
					tot=tot+j-1;
			}
		fout<<"Case #"<<rnd<<": "<<tot<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}