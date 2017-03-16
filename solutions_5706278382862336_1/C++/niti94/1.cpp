#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<sstream>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define PB push_back
#define MP make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define mod 1000000007
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define piw(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")
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
   // freopen("a.in","r",stdin);
//	freopen("bin.txt","w",stdout);
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
