/* Nakshatra Maheshwari...!!!
  IIIT Allahabad....!! */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#define ll long long
#define mx7 10000007
#define mx6 1000006

//...........................................//
//input
#define si(t) scanf("%d",&t)
#define sl(t) scanf("%lld",&t)
#define sf(t) scanf("%f",&t)
#define sdb(t) scanf("%lf",&t)
#define schar(c) scanf("%c",&c)
#define sstr(s) scanf("%s",s)
#define ssi(a,b) scanf("%d%d",&a,&b)
#define ssl(a,b) scanf("%lld%lld",&a,&b)
//...........................................//
//Output
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define pf(a) printf("%f\n",a)
#define pdb(a) printf("%lf\n",a)
//...........................................//
using namespace std;
long long int B[50];

long long int gcd(long long int a,long long int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

void gen()
{
	long  long int i = 1,j;
	B[0] = i; 
	for(j=1;j<=44;j++)
	{
		i *= 2;
		B[j] = i;
	}
	
}


int main()
{
	//	freopen("ss.in","r",stdin);
//	freopen("out1.txt","w",stdout);
	int T,i,j,k;
	long long int P,Q,W;
	scanf("%d",&T);
	gen();
	char c;
	for(k=1;k<=T;k++)
	{
		scanf("%lld %c %lld",&P,&c,&Q);
		W = gcd(Q,P);
		P /= W;
		Q /= W;
		
		if(binary_search(B,B+41,Q))
		{
			j = 1;
			bool o = true;
			if(P>Q)
			{
				printf("Case #%d: impossible\n",k);
				o = false;
			}
			while(j<=40 && o)
			{
				if(P>=Q/2)
				{
					printf("Case #%d: %d\n",k,j);
					o = false;
				}
				Q /= 2;
				j++;
			}
			if(o==true)
			printf("Case #%d : impossible\n",k);
		}
		else
		{
			printf("Case #%d: impossible\n",k);
		}
		
	}
}
