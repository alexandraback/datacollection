#include<iostream>
#include<fstream>
#include<math.h>
#include<string.h>
#include <sstream>
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

int primenum(int p,int num)
{
	int count = 0;
	while(num%p == 0)
	{
		num=num/p;
		count++;
	}
	return count;
}


void main()
{

	int T=0;
	int R = 0;
	int N= 0;
	int M=5;
	int K=7;
	ifstream in("C-small-2-attempt0.in");
	//ifstream in("A-small-attempt0.in");
	ofstream save("result4.txt");
	in >> T;
	in >> R;
	in >> N;
	in >> M;
	in >> K;
		save << "Case #1:"<<"\n";

	
	for(int p=0 ; p<R;p++)
	{
		int number = N;
		int prime[9];
		for(int i=0;i<9;i++)
		{
			prime[i] = 0;
		}

		int k[12];
		for(int i=0;i<12;i++)
		{
			in >> k[i];
			for(int j=2;j<9;j++)
			{
				if(j!=4 && j!=6 && j!=8)
				{
					if(prime[j]<primenum(j,k[i]))
					{
						prime[j] = primenum(j,k[i]);
					}
				}
			}
		}
		
		if(prime[3]>0)
		{
			number=number-prime[3];
		}

		if(prime[5]>0)
		{
			number=number-prime[5];
		}

		if(prime[7]>0)
		{
			number=number-prime[7];
		}

		if(number<prime[2])
		{
			int correct = prime[2]-number;
			int correct8 = correct/3;
			int correct4 = (correct-3*correct8)/2;
			
			prime[8] =correct8;
			if(correct4>0)
			{
			prime[4]=correct4;
			}
			prime[2] = prime[2]-prime[8]-prime[4];
			
			number = number - prime[2]-prime[8]-prime[4];
		}
		if(number<0)
		{
			prime[6] = -number;
			prime[2]+=number;
			prime[3]+=number;
		}
		if(number>0)
		{
			prime[2]+=number;
		}
		
		for(int i=2;i<9;i++)
		{
			for(int k=0;k<prime[i];k++)
			{
				save<<i;
			}
		}
		
		save<<"\n";
	}
	
	in.close();
	save.close();
}
