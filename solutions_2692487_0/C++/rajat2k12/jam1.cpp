#include<vector>
#include<climits>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<iostream>
using namespace std;
#define getcx getchar_unlocked
inline void inp(int &n )//fast input function
{
        n=0;
        int ch=getcx();int sign=1;
        while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

        while(  ch >= '0' && ch <= '9' )
                {n = (n<<3)+(n<<1) + ch-'0' ; ch=getcx();}
		n=n*sign;
}
int main()
{
int t,a,n,c[1000006],i,j,q=0;
inp(t);
while(t--)
{
inp(a);
inp(n);
for(i=0;i<n;i++)
inp(c[i]);
sort(c,c+n);
int count=0,m=INT_MAX;
for(i=0;i<n;i++)
{
	if(c[i]>=a)
	{
		if(i==n-1)
		{count++;break;}
		if(2*a-1<=c[i])
		{
		int tmp=count+n-i;
		m=min(m,tmp);
		count++;
		a=2*a-1;
		if(count>m)
		break;
		i--;
		}
		else if(2*a-1>c[i])
		{
		count++;a=2*a-1+c[i];
		}
	}
	else
	{
	a+=c[i];
	}
}
q++;
printf("Case #%d: %d\n",q,min(m,count));
}
return(0);
}


