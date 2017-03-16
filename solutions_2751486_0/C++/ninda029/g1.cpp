#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define sd(i) scanf("%d",&i)
#define sll(i) scanf("%lld",&i)
#define sull(i) scanf("%llu",&i)
#define sc(i) scanf("%c",&ch)
#define sstr(i) scanf("%s",i)
#define pd(i) printf("%d",i)
#define pll(i) printf("%lld",i)
#define pull(i) printf("%llu",i)
#define pc(i) printf("%c",i)
#define pstr(i) printf("%s",i)
#define newline printf("\n")
#define itoa(i,j) sprintf(i,"%d",j)
#define rep(i,j,n) for(i=j;i<n;i++)
#define ull unsigned long long
#define ll long long


void readline(char *str)
{
	char ch;
	sc(ch);
	int i=0;
	while(ch != '\n') {str[i++]=ch;sc(ch);}
	str[i]='\0';
}

char str[1000020];
int n;

long long solve()
{
	long long ans = 0;
	int i;
	int len = strlen(str);
	int curr=0;
	int valid = false;
	int last;
	rep(i,0,len)
	{
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='u' || str[i]=='o') 
		{
			curr=0;
			if(valid)
			{
				ans+=last+1;
			}
		}
		else
		{
			curr++;
			if(curr>=n) { valid = true;last=i-n+1;ans +=  i-n+2;}
			else if(valid)
			{
				ans+=last+1;
			}
		}
	}
	return ans;
}

int main()
{
	int t;
	sd(t);
	int in;
	rep(in,1,t+1)
	{
		char ch;
		sc(ch);
		scanf("%s",str);
		sd(n);
		printf("Case #%d: %lld\n",in,solve());
	}
	return 0;
}