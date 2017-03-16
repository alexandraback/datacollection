#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void main()
{
double j[250];
double y[250];
double x=0,x2;
int tcase,l,k,N,n2;
char ch;
ifstream ifile("A-small-attempt3.in");
	ofstream ofile("output.txt");
	if (ifile.is_open())
	{
		ifile>>tcase;
		cout<<tcase<<endl;
		for(l=0;l<tcase;l++)
		{
			x=0;
			ifile>>N;
			cout<<N<<endl;
			for(k=0;k<N;k++)
			{
				ifile>>j[k];
				//cout<<j[k]<<"	";
			}
			//cout<<endl;
			for(int i=0;i<N;i++)
			{
				x=x+j[i];
				
			}
			x2=2*x;
			n2=N;
			for(int i=0;i<N;i++)
			{
				if(j[i]>2*x/N)
				{
					
					x2=x2-j[i];
					n2--;
					j[i]=-1;
				}

			}
			cout<<x<<endl;
			ofile.precision(8);
			ofile<<"Case #"<<l+1<<":";
			for(int k=0;k<N;k++)
			{
				ofile.precision(8);
				if(j[k]==-1)
					y[k]=0;
				else
				{
				y[k]=(((x2/n2)-j[k])/x)*100;
				}
				cout<<fixed<<y[k]<<endl;
				ofile<<fixed<<' '<<y[k];
			}
			ofile<<endl;

		}
	}
cin>>ch;
}