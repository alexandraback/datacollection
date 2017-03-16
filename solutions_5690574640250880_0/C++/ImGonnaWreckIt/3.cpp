#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<math.h>
#include <iomanip>

using namespace std;

int main()
{
	int i,j,k;
	int T;
	int M,N,B;
	int min;
	int *row;
	int rem,quo;
	double temp;
	ifstream ip("C-small-attempt3.in");;
	ofstream op("output.txt");
	ip>>T;
	for(k=1;k<=T;k++)
	{
		op<<"Case #"<<k<<":\n";
		ip>>M>>N>>B;
		if(M==1)
		{
			for(i=0;i<B;i++)
				op<<"*";
			for(i=B;i<N-1;i++)
				op<<".";
			op<<"c\n";
			continue;
		}		

		if(N==1)
		{
			for(i=0;i<B;i++)
				op<<"*\n";
			for(i=B;i<M-1;i++)
				op<<".\n";
			op<<"c\n";
			continue;
		}
		if(B==M*N-1)
		{
			for(i=0;i<M;i++)
			{
				for(j=0;j<N;j++)
				{
					if(i==M-1 && j==N-1)
						op<<"c";
					else
						op<<"*";
				}
				op<<"\n";
			}
			continue;
		}
		i=M;
		row=new int[M];
		while(true)
		{
			if(i==2)
			{
				if(B%2!=0 || B/2==N-1)
				{
					i=-1;
					break;
				}
				else
				{
					row[M-2]=row[M-1]=B/2;
					break;
				}
			}
			else
			{
				if(B==0)
					rem=0;
				else
					rem=B%i;
				//cout<<i<<"\n";
				quo=B/i;
				
				if(k==112)
					cout<<B<<"\t"<<quo<<"\n";
				
				if(quo==0)
				{
					if(rem>=N)
					{
						row[M-i]=N;
						B=B-N; i--;
					}
					else if(rem==N-1)
					{
						if(N==2)
						{
							i=-1;
							break;
						}
						row[M-i]=N-2;
						B=1;
						i--;
					}
					else
					{
						row[M-i]=B;
						B=0; i--;
					}
					
				}

				else if(quo>N-2 || (quo==N-2 && rem!=0))
				{
					row[M-i]=N;
					B=B-N;
					i--;
				}
				
				else if(rem==0)
				{
					row[M-i]=quo;
					B=B-quo;
					i--;
				}
				else if((quo+1)*i-B==1)
				{
					row[M-i]=quo+2;
					if(row[M-i]==N-1)
						row[M-i]++;
					//cout<<(quo+1)*B<<"\t"<<row[M-i]<<"\n";
					B=B-row[M-i];
					i--;
				}
				else
				{
					row[M-i]=quo+1;
					B=B-quo-1;
					i--;
				}
			}
				
		}	
		if(i==-1)
		{
			op<<"Impossible\n";
			continue;
		}
		for(i=0;i<M-1;i++)
		{
			for(j=0;j<N;j++)
			{
				if(j>=row[i])
					op<<".";
				else
					op<<"*";
			}
			op<<"\n";
		}
		for(i=0;i<N-1;i++)
		{
			if(i<row[M-1])
				op<<"*";
			else
				op<<".";
		}
		op<<"c\n";
	}
	return 0;
}
