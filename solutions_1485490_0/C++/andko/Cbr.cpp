#include<cstdio>
#include<cstdlib>
#include<iostream>
#define MAXN 104
using namespace std;
//unsigned long long min(unsigned long long a, unsigned  long long b){if(a<b)return a;return b;}
void solve(int num)
{
	int N,M;
	scanf("%d%d",&N,&M);
	int boxtype[MAXN], toytype[MAXN];
	long long boxQ[MAXN], toyQ[MAXN];
	for(int i=1;i<=N;i++)scanf("%lld%d",&boxQ[i],&boxtype[i]);
	for(int i=1;i<=M;i++)scanf("%lld%d",&toyQ[i],&toytype[i]);
	
	long long res = 0;
	for(int i=0;i<=M;i++)
	{
		for(int j=i;j<=M;j++)
		{
			long long tmpres = 0;
			long long licznik = boxQ[1];
			long long reszta = 0;
			bool czy1 = 0,czy2 = 0;
			for(int k=1;k<=i;k++)
				if(boxtype[1] == toytype[k])
				{
					long long roz = min(licznik,toyQ[k]);
					tmpres += roz;
					licznik -= roz;
					reszta = toyQ[k]-roz;
					if(k==i)czy1 = 1;
					if(licznik <= 0LL)
					{
						//if(k<i)czy1  = 0;
						break;
					}
					
				}
				if(i<2)goto dalej;
			licznik = boxQ[2];
			for(int k=i;k<=j;k++)
				if(boxtype[2] == toytype[k])
				{
					long long toyQt = toyQ[k];
					if(czy1 && k==i)toyQt = reszta;
					else if(k==i)toyQt = 0;
					long long roz = min(licznik,toyQt);
					tmpres += roz;
					licznik -= roz;
					reszta = toyQ[k]-roz;
					if(k==j)czy2 = 1;
					if(licznik <= 0LL)
					{
						//if(k<j)czy2  = 0;
						break;
					}
					
				}
				
				if(i<3)goto dalej;
			licznik = boxQ[3];
			for(int k=j;k<=M;k++)
				if(boxtype[3] == toytype[k])
				{
					long long toyQt = toyQ[k];
					if(czy2 && k==j)toyQt = reszta;
					else if(czy1 && k == i)toyQt = reszta;
					else if(k==j)toyQt = 0;
					long long roz = min(licznik,toyQt);
					tmpres += roz;
					licznik -= roz;
					if(licznik <=0)
						break;
				}
			//printf("%d %d %lld\n",i,j,tmpres);
			dalej:;
			if(res < tmpres)
			{
				
				res = tmpres;
			}
		}
	}
	printf("Case #%d: %llu\n",num,res);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)solve(i+1);
	return 0;
}