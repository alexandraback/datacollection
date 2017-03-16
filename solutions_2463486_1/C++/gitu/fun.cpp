/*------Coded by Gitanshu Behal------*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<cctype>
#include<ciso646>
#include<stdbool.h>
#include<cstddef>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<complex>
#include<functional>
#include<numeric>
#include<limits>
#include<stdexcept>
#include<string>
#include<utility>
#include<fstream>


		/*--------scan/print--------*/
# define s(n) scanf("%d",&n)
# define p(n) printf("%d",n)
# define pln(n) printf("%d\n",n)
# define sln(n) scanf("%d\n",&n)
# define plld(x) printf("%lld\n",x)

		/*--------FOR LOOPS--------*/
# define For(I,l,m) for(int I=l;I<=m;I++)
# define ForInt(I,l,m) for(I=l;I<=m;I++)
# define NFor(I,l,m) for(int I=l;I>=m;I--)
# define NForInt(I,l,m) for(I=l;I>=m;I--)

		/*--------others--------*/
# define TEST int t; scanf("%d",&t); while(t--)
# define ZERO(x) memset(x,0,sizeof(x))
# define SET(x,y) memset(x,y,sizeof(x))
# define NEWLINE printf("\n")

/*--------2 option--------*/
# define YES printf("YES\n")
# define NO printf("NO\n")

/*------DIRECTELY USABLE----> sort(array,array+size),swap(a,b),------*/


using namespace std;

bool isPalin(long long int n)
{
	long long int b=0,c=n;
	while(c!=0)
	{
		b=b*10+(c%10);
		c=c/10;
	}
	return b==n; 
}


/*-------begin of main---------*/
int main()
{
	int t;
	s(t);
	long long int A[2000],I=0;
	for(long long int i=1;i<=10000000;i++)
	{
		if(isPalin(i))
		{
			if(isPalin(i*i))
			A[I++]=i*i;
		}
	}
/*	For(i,0,I-1)
	{
		cout<<A[i]<<" "	;
	}*/
	for(int G=0;G<t;G++)
	{
		long long int N,M;
		cin>>N>>M;
		int answer=0;
		For(i,0,I-1)
		{
			if(A[i]>=N && A[i]<=M)
			answer++;	
		}
		printf("Case #%d: %d\n",G+1,answer);
		
	}	
}
