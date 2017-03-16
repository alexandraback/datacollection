#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int x,y,z,tx,ty,ia,i,j,t,tc,k;
	char a[2000];
	ifstream ifile("D:/in4.in");
	ofstream ofile("D:/out.txt");
	ifile>>tc;
	for(t=0;t<tc;++t)
	{
		ifile>>x>>y;
		i=j=0;
		k=1;
		ia=0;
		tx=ty=1;
		if(x<0) {tx=-1; x=x*tx;}
		if(y<0) {ty=-1; y=y*ty;}
		while(1)
		{
			if(i+k<=x) {a[ia++]=(tx==-1)?'W':'E'; i+=k; ++k;}
			if(j+k<=y) {a[ia++]=(ty==-1)?'S':'N'; j+=k; ++k;}
			if(i+k>x&&j+k>y) break;
		}
		while(i!=x)
		{
			a[ia++]=(tx==-1)?'E':'W';
			a[ia++]=(tx==-1)?'W':'E';
			i=i+1;
			k+=2;
		}
		while(j!=y)
		{
			a[ia++]=(ty==-1)?'N':'S';
			a[ia++]=(ty==-1)?'S':'N';
			j=j+1;
			k+=2;
		}
		ofile<<"Case #"<<t+1<<": ";
		for(z=0;z<ia;++z)
		{
			ofile<<a[z];
		}
		ofile<<endl;
	}
	return 0;
}
