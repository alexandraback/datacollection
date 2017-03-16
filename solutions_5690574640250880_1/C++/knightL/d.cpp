#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

int res[51][51];

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		int r,c,M;
		scanf("%d%d%d",&r,&c,&M);
		printf("Case #%d:\n",test);
		int F=r*c-M;
		bool swaped=r>c;
		bool ok=true;
		if(swaped)
			swap(r,c);
		if(M==0)
		{
			memset(res,0,sizeof(res));
			res[0][0]=1;
		}
		else if(F==1)
		{
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					res[i][j]=2;
			res[0][0]=1;
		}
		else if(r==1)
		{
			for(int i=0;i<F;i++)
				res[0][i]=i==0?1:0;
			for(int i=F;i<c;i++)
				res[0][i]=2;
		}
		else if(r==2)
		{
			if(F%2!=0|| F<4)
				ok=false;
			else
			{
				for(int i=0;i<F/2;i++)
					res[0][i]=res[1][i]=0;
				for(int i=F/2;i<c;i++)
					res[0][i]=res[1][i]=2;
				res[0][0]=1;
			}
		}
		else
		{
			if(F==1)
			{
				for(int i=0;i<r;i++)
					for(int j=0;j<c;j++)
						res[i][j]=(i+j==0)?1:2;
			}
			else if(F==2||F==3||F==5||F==7)
				ok=false;
			else
			{
				for(int i=0;i<r;i++)
					for(int j=0;j<c;j++)
						res[i][j]=2;
				int Left=F;
				for(int i=0;i<2;i++)
					for(int j=0;j<2;j++)
					{
						res[i][j]=(i+j==0)?1:0;
						Left--;
					}
				assert(Left>=0);
				if(Left)
				{
					assert(Left>=2);
					res[2][0]=res[2][1]=0;
					Left-=2;
					if(Left)
					{
						assert(Left>=2);
						res[0][2]=res[1][2]=0;
						Left-=2;
						int next_r=3;
						int next_c=3;
						while(Left>=2 && next_r<r)
						{
							res[next_r][0]=0;
							res[next_r][1]=0;
							next_r++;
							Left-=2;
						}
						while(Left>=2 && next_c<c)
						{
							res[0][next_c]=0;
							res[1][next_c]=0;
							next_c++;
							Left-=2;
						}
						for(int i=2;i<r;i++)
							for(int j=2;j<c;j++)
								if(Left && res[i][j]==2)
								{
									res[i][j]=0;
									Left--;
								}
					}
				}
			}
		}
		if(!ok)
			puts("Impossible");
		else
		{
			if(!swaped)
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
					{
						assert(0<=res[i][j] && res[i][j]<=2);
						switch(res[i][j])
						{
						case 0:
							putchar('.');
							break;
						case 1:
							putchar('c');
							break;
						case 2:
							putchar('*');
							break;
						}
					}
					puts("");
				}
			else
			{
				for(int j=0;j<c;j++)
				{
					for(int i=0;i<r;i++)
					{
						assert(0<=res[i][j] && res[i][j]<=2);
						switch(res[i][j])
						{
						case 0:
							putchar('.');
							break;
						case 1:
							putchar('c');
							break;
						case 2:
							putchar('*');
							break;
						}
					}
					puts("");
				}
			}
		}
	}
	return 0;
}
