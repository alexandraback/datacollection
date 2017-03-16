#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
#include<cstring>
#include<limits.h>
#define gc getchar()
#define pc putchar
#define mod 1000000007
using namespace std;
typedef long long ll;

//Fast read
inline void read(ll& n)
{
	n = 0;
	char ch = gc; int sign = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') sign = -1; ch = gc; }
	while(ch >= '0' && ch<= '9')
	{
		n = n*10 + ch - '0';
		ch = gc;
	}
	n *= sign;
}

//Fast print
inline void print(ll n)
{
	char ch[15];
	int ind=0;
	if(n<0)
    {
        pc('-');
        n *= -1;
    }
	if(n == 0)
	{
		pc('0');
	}
	while(n > 0)
	{
		ch[ind] = n%10 + '0';
		n /= 10;
		ind++;
	}
	while(ind--) pc(ch[ind]);
	pc('\n');
}

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
	freopen("A-small-attempt2.in", "r", stdin);
    freopen("outsmall2.txt", "w", stdout);
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
