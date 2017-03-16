#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

void main()
{
	ofstream out("B.out");
	ifstream in("B.in");
	int T,t;

	in>>T;
	for(t=1;t<=T;t++)
	{
		int N,S,p,r=0,tmp;
		in>>N>>S>>p;
		p*=3;
		p-=2;
		while(N--)
		{
			in>>tmp;
			if(tmp >= p)
				r++;
			else if(S && tmp && tmp >= p-2)
			{
				r++;
				S--;
			}
		}

		out<<"Case #"<<t<<": "<<r<<endl;
	}

	in.close();
	out.close();
}

