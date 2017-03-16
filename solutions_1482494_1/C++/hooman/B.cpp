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
	//in.getline(line,32);
	//sscanf(line,"%d",&T);

	for(t=1;t<=T;t++)
	{
		cout<<t<<endl;
		int N,n,a[1000],b[1000],play,S;
		int B[1000],i,j;

		//in.getline(line,32);
		//sscanf(line,"%d %d",&N,&M);
		in>>N;
		//cout<<N<<endl;
		for(n=0;n<N;n++)
		{
			in>>a[n]>>b[n];
			//cout<<a[n]<<' '<<b[n]<<endl;
			B[n]=n;
		}

		for(i=0;i<N;i++)
			for(j=i+1;j<N;j++)
			{
				int tmp;
				if(b[B[i]]>b[B[j]])
				{
					tmp=B[i];
					B[i]=B[j];
					B[j]=tmp;
				}
			}

		for(play=0,S=0,n=0,i=0;S<(2*N);)
		{
			for(;(n<N) && (b[B[n]]<=S);n++)
			{
				if(a[B[n]]==2002)
					S++;
				else
					S+=2;
			}
			for(i=N-1;i>=n && (a[B[i]]>S);i--);
			if(i>=n)
			{
				a[B[i]]=2002;
				S++;
				play++;
			}
			else
				break;
		}

		if(S==(2*N))
			out<<"Case #"<<t<<": "<<(N+play)<<endl;
		else
			out<<"Case #"<<t<<": "<<"Too Bad"<<endl;
	}
	in.close();
	out.close();
}
