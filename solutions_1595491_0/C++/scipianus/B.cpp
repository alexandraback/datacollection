#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,nrs,P,v[110];

inline int Rezolvare()
{
	int i,A,B,C,nruz=0,maxim,minim,rez=0;
	bool pos1,pos2;
	sort(v+1,v+n+1);
	for(i=1;i<=n;i++)
	{
		pos1=pos2=false;
		for(A=0;A<=10;A++)
		{
			for(B=0;B<=10;B++)
			{
				if(A+B<=v[i])
				{
					C=v[i]-A-B;
					maxim=max(max(A,B),C);
					minim=min(min(A,B),C);
					if(maxim>=P)
					{
						if(maxim-minim==2)
							pos2=true;
						if(maxim-minim<2)
							pos1=true;
					}
				}
			}
		}
		if(pos1==true)
			rez++;
		else
		{
			if(pos2==true && nruz<nrs)
			{
				rez++;
				nruz++;
			}
		}
	}
	return rez;
}

int main()
{
	int i,t;
	ifstream fin("B.in");
	ofstream fout("B.out");
	fin>>T;
	for(t=1;t<=T;t++)
	{
		fin>>n>>nrs>>P;
		for(i=1;i<=n;i++)
			fin>>v[i];
		fout<<"Case #"<<t<<": "<<Rezolvare()<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
