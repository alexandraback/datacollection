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
		char A[4][4];
		For(i,0,3)
		{
			For(j,0,3)
			{
				cin>>A[i][j];	
			}
		}
		char flag='D';
		For(i,0,3)
		{
			if( (A[i][0]=='X' || A[i][0]=='T') && (A[i][1]=='X' || A[i][1]=='T') && (A[i][2]=='X' || A[i][2]=='T') && (A[i][3]=='X' || A[i][3]=='T') )
			{
				flag='X';
				break;
			}
			else if((A[i][0]=='O' || A[i][0]=='T') && (A[i][1]=='O' || A[i][1]=='T') && (A[i][2]=='O' || A[i][2]=='T') && (A[i][3]=='O' || A[i][3]=='T'))
			{
				flag='O';
				break;
			}
			 
		}
		if(flag=='D')
		{
			For(j,0,3)
			{
				if( (A[0][j]=='X' || A[0][j]=='T') && (A[1][j]=='X' || A[1][j]=='T') && (A[2][j]=='X' || A[2][j]=='T') && (A[3][j]=='X' || A[3][j]=='T') )
				{
					flag='X';
					break;
				}
				else if( (A[0][j]=='O' || A[0][j]=='T') && (A[1][j]=='O' || A[1][j]=='T') && (A[2][j]=='O' || A[2][j]=='T') && (A[3][j]=='O' || A[3][j]=='T') )
				{
					flag='O';
					break;
				}
			}
		}
		if(flag=='D')
		{
			if( (A[0][0]=='X' || A[0][0]=='T') && (A[1][1]=='X' || A[1][1]=='T') && (A[2][2]=='X' || A[2][2]=='T') && (A[3][3]=='X' || A[3][3]=='T') )
			{
				flag='X';
			}
			else if( (A[0][0]=='O' || A[0][0]=='T') && (A[1][1]=='O' || A[1][1]=='T') && (A[2][2]=='O' || A[2][2]=='T') && (A[3][3]=='O' || A[3][3]=='T') )
			{
				flag='O';
			}
			else if( (A[0][3]=='X' || A[0][3]=='T') && (A[1][2]=='X' || A[1][2]=='T') && (A[2][1]=='X' || A[2][1]=='T') && (A[3][0]=='X' || A[3][0]=='T') )
			{
				flag='X';
			}
			else if( (A[0][3]=='O' || A[0][3]=='T') && (A[1][2]=='O' || A[1][2]=='T') && (A[2][1]=='O' || A[2][1]=='T') && (A[3][0]=='O' || A[3][0]=='T') )
			{
				flag='O';
			}
		}
		if(flag=='D')
		{
			For(i,0,3)
			{
				For(j,0,3)
				{
					if(A[i][j]=='.')
					{
						flag='S';
						break;	
					}	
				}
			}
		}
		if(flag=='X')
		printf("Case #%d: X won\n",G+1);
		else if(flag=='O')
		printf("Case #%d: O won\n",G+1);
		else if(flag=='D')
		printf("Case #%d: Draw\n",G+1);
		else if(flag=='S')
		printf("Case #%d: Game has not completed\n",G+1);
		
		NEWLINE;
	}	
}
