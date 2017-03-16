#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include <iomanip>

using namespace std;

int d(int,int);

void main()
{
//	ofstream out("A.out");
	FILE *out;
	out=fopen("A.out","w");
	ifstream in("A.in");
	int T,t;
	char line[32];

	in>>T;
	//in.getline(line,32);
	//sscanf(line,"%d",&T);

	for(t=1;t<=T;t++)
	{
		int A,B,a;
		double p,res,all;
		printf("%d\n",T);

		in>>A>>B;
		res=B+2;
		all=1;

		for(a=0;a<A;a++)
		{
			in>>p;
			all*=p;
			double tmp=(B-a+A-a-1)+(1-all)*(B+1);
			if(tmp<res)
				res=tmp;
		}

		fprintf(out,"Case #%d: %.6f\n",t,res);
//		out<<"Case #"<<t<<": "<<setprecision (6)<<res<<endl;
	}

	in.close();
	fclose(out);
}

int d(int a,int b)
{
	int c;
	do{
		if(a<b)
		{
			c=a;
			a=b;
			b=c;
		}
		if(!b)
			return a;
		a=a%b;
	}while(1);
}