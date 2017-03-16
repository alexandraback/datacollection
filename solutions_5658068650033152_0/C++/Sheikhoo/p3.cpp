#include<iostream>
#include<fstream>
#include<algorithm>
#include<stack>
#include<set>
#include<vector>
using namespace std;

#define uul unsigned long long
#define sul signed long long
#define For(i) for(int j=0; j<i; j++)
#define For2(st,n) for(int i=st; i<n; i++)
#define ch(t,s1,s2) (t<s1 || t>s2)
#define vit vector<uul>::iterator
#define vi vector<uul>
#define si set<uul>
#define sit set<uul>::iterator

int main()
{
	ifstream fin("p.in");
	ofstream fout("p.out");

	uul t;
	fin>>t;
	si a;

	For(t)
	{
		uul N,M,K;

		fin>>N;
		fin>>M;
		fin>>K;

		if( ch(N*M,1,20) || ch(K,1,N*M))
			return 1;

		uul l = N>=M?N:M;
		uul s = N<=M?N:M;
		uul count;
		
		if( N==1 || M==1)
		{
			count = 0;
		}
		else if(N==2 || M==2)
		{
			count = 0;
		}
		else if( K<=3 )
			count=0;
		else
		{
			int *pp = new int[s];
			int kkk = 0;
			int k=1;
			int mul=0;
			while(1)
			{
				mul=0;
				int counter = k;
				int j=2;
				while(K-counter > 2+k && j<l)
				{
					counter = counter+2+k;
					mul = mul+k;
					j++;
				}
				counter=counter+k;
				if(K-counter <= 4)
				{
					pp[kkk++] = mul;
				}
				k++;
				if(k>=s)
					break;
				
			}
			count = pp[0];
			for(int i=1; i<kkk; i++)
			{
				if(count<pp[i])
					count=pp[i];
			}
		}
		fout<<"Case #"<<j+1<<": "<<K-count<<endl;
	}
	return 0;
}