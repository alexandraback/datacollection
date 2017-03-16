#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

void main()
{
	ofstream out("C.out");
	ifstream in("C.in");
	int T,t;

	in>>T;
	for(t=1;t<=T;t++)
	{
		cout<<t<<endl;
		int A,B,order=1,i,j,k,tmp,r=0;
		in>>A>>B;
		for(tmp=A/10;tmp;tmp/=10,order*=10);
		for(i=A;i<B;i++)
		{
			int N=0,n,res[7];
			for(j=10,k=order;k>1;k/=10,j*=10)
			{
				tmp=(i%k)*j + i/k;
				if(tmp>i && tmp<=B)
				{
					for(n=0;n<N && res[n] != tmp;n++);
					if(n==N)
					{
						r++;
						res[N++]=tmp;
					}
				}
			}
		}

		out<<"Case #"<<t<<": "<<r<<endl;
	}

	in.close();
	out.close();
}

