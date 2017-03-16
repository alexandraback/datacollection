#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

int T,N,S,P,v[110];

bool Isvalid(int a,int b,int c)
{
	if( abs(a-b)>2 || abs(a-c)>2 || abs(b-c)>2 ) return false;
	return true;
}

bool Issp(int a,int b,int c)
{
	if( abs(a-b)==2 || abs(a-c)==2 || abs(b-c)==2) return true;
	return false;
}

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d %d %d",&N,&S,&P);
		for(int j=1;j<=N;j++)
		{
			scanf("%d",&v[j]);
		}
		int va_sp2 = 0;
		int va_sp1 = 0;
		int va_sp0 = 0;
		int nva_sp = 0;

		for(int j=1;j<=N;j++)
		{
			bool f = false,f2=false,g=false,g2=false,g3=false;
			for(int m=0;m<=v[j];m++)
			{
				if(m>10) break;
				for(int x=0;v[j]-m-x>=0;x++)
				{
					if( x>10 || v[j]-m-x>10 ) continue;
					if(Isvalid(m,x,v[j]-x-m))
					{
						if( m>=P || x>=P || v[j]-x-m>=P)
						{
							f = true;
							if( Issp(m,x,v[j]-x-m))
							{
								g2 = true;
							}
							else
							{
								g3 = true;
							}
						}
						else
						{
							f2 = true;
							if( Issp(m,x,v[j]-x-m))
							{
								g = true;
							}
						}
					}

				}
			}
			
			if(f2&&!f)
			{
				nva_sp++;
			}
			if(f)
			{
				if(g2&g3) va_sp2++;
				else if(g2) va_sp1++;
				else va_sp0++;
			}

		}
		
		//printf("%d %d %d %d\n",nva_sp,va_sp2,va_sp1,va_sp0);
		int	ans = 0;
		if( va_sp1>=S)
		{
			ans += va_sp2+va_sp0+S;
		}
		else if(nva_sp+va_sp1+va_sp2>=S)
		{
			ans += va_sp2 + va_sp1 + va_sp0;;
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}