/* HellGeek */
/* Shiva Bhalla */
/* iit2012077 */


#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

#define LL long long
#define FIT(i,t) for(i=0;i<t;i++)
#define FIN(i,n) for(i=0;i<n;i++)
#define FJT(j,t) for(j=0;j<t;j++)
#define FJN(j,n) for(j=0;j<n;j++)
#define MAX2(a,b) a>b?a:b
#define MIN2(a,b) a>b?b:a
#define REP(i,a,b) for(i=a;i<=b;i++)

using namespace std;
 
LL Blast[50];
 LL laudesejaona[100005];
LL gcd(LL a,LL b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
 
void gen()
{
	LL int i = 1,j;
	Blast[0] = i; 
	for(j=1;j<=44;j++)
	{
		i *= 2;
		Blast[j] = i;
	}
 
}
 
 
int main()
{
 
	int T,i,j,k;
	LL int Po,Qo,Wo;
	
	freopen("alpha1.txt", "w", stdout);
	
    scanf("%d",&T);
	gen();
	char c;
	for(k=1;k<=T;k++)
	{
		scanf("%lld %c %lld",&Po,&c,&Qo);
		Wo = gcd(Qo,Po);
		Po /= Wo;
		Qo /= Wo;
 
		if(binary_search(Blast,Blast+41,Qo))
		{
			j = 1;
			bool o = true;
			if(Po>Qo)
			{
				printf("Case #%d: impossible\n",k);
				o = false;
			}
			while(j<=40 && o)
			{
				if(Po>=Qo/2)
				{
					printf("Case #%d: %d\n",k,j);
					o = false;
				}
				Qo /= 2;
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
	
	return 0;
}
