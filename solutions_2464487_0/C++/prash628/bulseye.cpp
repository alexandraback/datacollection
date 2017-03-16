#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

int findres(int r,int t);
int findL(int r);

int main()
{
	int T;
	fin>>T;
	int i=0;
	int res;

	int r,t;

	while(i<T)
	{
		fin>>r;
		fin>>t;
		res=findres(r,t);

		i++;

		fout<<"Case #";
		fout<<i;
		fout<<": ";
		fout<<res;
		
		if(i!=T)
		{
			 fout<<"\n";
		}
	}
	return(0);
}


int findres(int r,int t)
{
	int fres=0;

	int radius=r;
	int chk=1;
	int neededL;
	
	while(chk)
	{
		neededL=findL(radius);
		if(neededL<=t){t=t-neededL;fres++;}
		else{chk=0;}
		radius=radius+2;
	}
	return(fres);
}


int findL(int r)
{
	int res;
	res=1+(2*(r));
	return(res);
}
