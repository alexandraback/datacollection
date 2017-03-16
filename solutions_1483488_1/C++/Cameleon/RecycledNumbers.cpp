#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int degree(int);
void setC();
int C[7];
int main()
{
	ofstream ofvar;
	ofvar.open("output.out");
	setC();
	bool valid;
	int T, A, B, n, m, deg, out,temp1,temp2;
	string str1;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>A>>B;
		deg=degree(A);
		out=0;
		for(int j=A;j<B;j++)
		{
			setC();
			for(int k=1;k<=deg;k++)
			{
				n=j;
				temp1=pow(10,k);
				temp2=n%temp1;
				//if(temp1==0)
				//	continue;
				m=n/pow(10,k)+temp2*pow(10,deg-k);
				valid=true;
				if(m>n&&m<=B)
				{
					for(int l=0;l<7;l++)
					{
						if(C[l]==0)
						{
							C[l]=m;
							break;
						}
						if(C[l]==m)
						{
							valid=false;
						//	cout<<"FOUND";
							break;
						}
					}
					if(valid)	
						out++;
				//	cout<<n<<"   "<<m<<endl;
				}
			}
		}
		ofvar<<"Case #"<<i+1<<": "<<out<<endl;
	}
	return 0;
}
int degree(int A)
{
	int out=0;
	for(int i=0;i<7;i++)
	{
		if(A/static_cast<int>(pow(10,i))!=0)
		{
			out++;
	//		cout<<A/pow(10,i)<<endl;
		}
	}
	//cout<<"Degree of "<<A<<" is "<<out<<endl;
	return out;
}
void setC()
{
	for(int qwer=0;qwer<7;qwer++)
		C[qwer]=0;
}
