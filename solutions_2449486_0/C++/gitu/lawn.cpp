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

/*-------begin of main---------*/
int main()
{
	int t;
	s(t);
	for(int G=0;G<t;G++)
	{
		int N,M;
		cin>>N>>M;
		int A[N][M];
		int max=0;
		For(i,0,N-1)
		{
			For(j,0,M-1)
			{
				cin>>A[i][j];	
			}	
		}
		int Row[N],Col[M];
		For(i,0,N-1)
		{
			Row[i]=0;
			For(j,0,M-1)
			{
				if(A[i][j]>Row[i])
				Row[i]=A[i][j];	
			}
		}
		For(j,0,M-1)
		{
			Col[j]=0;
			For(i,0,N-1)
			{
				if(A[i][j]>Col[j])
				Col[j]=A[i][j];	
			}
		}
		int answer=0;
		For(i,0,N-1)
		{
			For(j,0,M-1)
			{
				if(A[i][j]<Row[i] && A[i][j]<Col[j])
				{
					answer=1;
					break;	
				}	
			}	
		}
		if(answer==1)
		printf("Case #%d: NO\n",G+1);
		else
		printf("Case #%d: YES\n",G+1);
		
	}	
}
