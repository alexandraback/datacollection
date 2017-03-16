#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;
long long t,x,y,n;
long long gcd(long long x, long long y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
bool correct(long long y)
{
    while(y>1)
    {
        if(y%2!=0) return false;
        y/=2;
    }
    return true;
}
int solve(long long x, long long y)
{
    int br=0;
    while(y>x)
    {
        y/=2;
        br++;
    }
    return br;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&t);
	for(int o=1; o<=t; o++)
	{
		printf("Case #%d: ",o);
		char c;
        scanf("%lld",&x);
        scanf("%c",&c);
        scanf("%lld",&y);
        long long g=gcd(x,y);
        x/=g;
        y/=g;
        if(correct(y)==true)
            printf("%d\n",solve(x,y));
        else
            printf("impossible\n");
    }
	return 0;
}
