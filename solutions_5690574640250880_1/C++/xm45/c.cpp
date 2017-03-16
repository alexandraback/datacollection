#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<deque>
#include<functional>
#include<iterator>
#include<vector>
#include<list>
#include<map>
#include<memory>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#define abs(a) ((a>0)?(a):-(a))
#define sgm(a) (a==0?(0):((a>0)?(1):(-1)))
#define sqr(a) ((a)*(a))
#define swap(a,b,lx) {lx t;t=a;a=b;b=t;}
#define oo 0xfffffff
using namespace std;
int N,M,K,T;
int R,C;
inline int rd(int a)
{
		long long b=((long long)rand()+1)*((long long)rand()+1)*((long long)rand()+1)%100000007*(rand()+1)%a+1; 
		return(b);
}
bool ans=0;
bool h[51][51];
void clear()
{
	ans=0;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			h[i][j]=0;
}
void make1()
{
	if(N==R*C)
		return;
	ans=1;
	if(R==1)
		for(int i=C-N+1;i<=C;i++)
			h[R][i]=1;
	else
		for(int i=R-N+1;i<=R;i++)
			h[i][C]=1;
}
void make()
{
	if(N%2==1 && (R<3 || C<3))
		return;
	int r=R-2,c=C-2;
	if(r*c>=N)
	{
		for(int i=R;i>2;i--)
			for(int j=C;j>2;j--)
			{
				if(!N)
				{
					ans=1;
					return;
				}
				h[i][j]=1;
				N--;
			}
	}
	else
	{
		for(int i=R;i>2;i--)
			for(int j=C;j>2;j--)
				h[i][j]=1;
		N-=r*c;
		int limit=2;
		if(N%2)
		{
			N++;
			h[3][3]=0;
			limit=3;	
		}
		for(int i=R;i>limit;i--)
		{
			if(!N)
			{
				ans=1;
				return;
			}
			h[i][1]=h[i][2]=1;
			N-=2;
		}
		for(int i=C;i>limit;i--)
		{
			if(!N)
			{
				ans=1;
				return;	
			}
			h[1][i]=h[2][i]=1;	
			N-=2;
		}
	}
	if(N==0)
		ans=1;
}
void pr()
{
	printf("\n");
	if(ans==0)
		printf("Impossible\n");
	else
		for(int i=1;i<=R;i++)
		{
			for(int j=1;j<=C;j++)
				if(i==1 && j==1)
					printf("c");
				else
					printf("%c",h[i][j]?'*':'.');
			printf("\n");
		}
	
}
void work()
{
	scanf("%d%d%d",&R,&C,&N);
	//printf("%d %d %d",R,C,N);
	clear();
	if(R*C-N==1)
	{
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
				h[i][j]=1;
		h[1][1]=0;
		ans=1;
	}
	else
		if(R==1||C==1)
			make1();
		else
			make();
	pr();
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,l;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		if(i==9)
			j=1;
		printf("Case #%d: ",i);
		work();
		//printf("\n");
	}
    return(0);
}
