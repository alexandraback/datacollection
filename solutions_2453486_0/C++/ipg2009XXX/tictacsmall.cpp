/*-->>Light Cavalry<<--*/

//Imp header files
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cassert>
#include <climits>
#include <fstream>
using namespace std;

//defined I/O
#define si(n) scanf("%d",&n)
#define sli(n) scanf("%ld",&n)
#define slli(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define GetLine(n) getline(cin,n);
#define ss(n) scanf("%s",n)
#define pi(n) printf("%d",n)
#define pli(n) printf("%ld",n)
#define plli(n) printf("%lld",n)
#define pf(n) printf("%lf",n)
#define ps(n) printf("%s",n)
#define newLine printf("\n")
#define space printf(" ")
#define SWAP(a,b,t) t=a,a=b,b=t
#define Loop(i,a,n) for(__typeof(n) i(a); i<n; i++)
#define ULL unsigned long long int
#define LL long long int 

#define MOD 1000000007
//Imp functions
int gcd(int a, int b){if(b == 0)return a;else return gcd(b,a % b);}

#define get getchar_unlocked
inline int scan()
{
	int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}


char grid[4][4];
char visited[4][4];
int CheckRow(int row,int col,char c)
{
	int countC=0,countT=0;
	
	for(int i=0;i<4;i++)
	{
		if(grid[row][i]==c)
		countC++;
		
		if(grid[row][i]=='T')
		countT++;

		
	}
	//cout<<countC<<" "<<countT<<endl;
	if(countC+countT==4)
	return 1;
	else
	return 0;
	
return 0;
	
}

int CheckCol(int row,int col,char c)
{
	int countC=0,countT=0;
	
	for(int i=0;i<4;i++)
	{
		if(grid[i][col]==c)
		countC++;
		
		if(grid[i][col]=='T')
		countT++;

		
	}
	
	if(countC+countT==4)
	return 1;
	else
	return 0;
	
return 0;
	
}

int CheckDiagonal(int row,int col,char c)
{
	int countC=0,countT=0;
	if(row==col)
	{
		row=0;col=0;
		
		for(int i=0;i<4;i++)
		{
			if(grid[i][i]==c)
			countC++;
			
			if(grid[i][i]=='T')
			countT++;
		}
		
		if(countC+countT==4)
		return 1;
		else
		return 0;
		
		
	}
	else if(row+col==3)
	{
		row=0;col=3;
		
		for(int i=0;i<4;i++)
		{
			if(grid[i][col-i]==c)
			countC++;
			
			if(grid[i][col-i]=='T')
			countT++;
		}
		
		if(countC+countT==4)
		return 1;
		else
		return 0;
		
		
	}
	return 0;
}


int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.in","w",stdout);
	
	int t;
	t=scan();

	int p=0;
	while(t--)
	{
		++p;
		for(int i=0;i<4;i++)
		{
			scanf("%s",grid[i]);
		}
		
		int X=0,O=0;
		int dot=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
					if(grid[i][j]!='.' && grid[i][j]!='T')
					{
						if(grid[i][j]=='X')
						{
							if(!X)
							X=CheckRow(i,j,'X');
							
							if(!X)
							X=CheckCol(i,j,'X');
							
							if(!X)
								if((i+j==3)||(i==j))
								X=CheckDiagonal(i,j,'X');
						}
					
						if(grid[i][j]=='O')
						{
							if(!O)
							O=CheckRow(i,j,'O');
							
							if(!O)
							O=CheckCol(i,j,'O');
							
							if(!O)
								if((i+j==3)||(i==j))
								O=CheckDiagonal(i,j,'O');
						}
					}
					else if(grid[i][j]=='.')
					dot++;
				
			}
		}
		
		if(X && !O)
		{
			printf("Case #%d: X won\n",p);
		}
		else if(!X && O)
		{
			printf("Case #%d: O won\n",p);
		}
		else if(!X && !O && !dot)
		{
			printf("Case #%d: Draw\n",p);
		}
		else if( !X && !O)
		{
			printf("Case #%d: Game has not completed\n",p);
		}
		
		
		
		
	}
	
	
	
	return 0;
}



