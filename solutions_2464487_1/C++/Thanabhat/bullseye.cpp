/*
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

long long cal(long long r,long long n)
{
    long long a1=r+r+1;
    long long an=a1+(n-1)*4;
    long long res=(a1+an)/2;
    res*=n;
    //printf("cal %lld %lld = %lld\n",r,n,res);
    return res;
}

int solve(int cc)
{
    long long r,t;
    scanf("%lld %lld",&r,&t);
    long long l=1,m,h=min(2000000000000000000LL/r,(long long)sqrt(t/2));
    while(l<=h)
    {
        m=(l+h)/2;
        long long c=cal(r,m);
        if(c<=t)
        {
            l=m+1;
        }else if(c>t)
        {
            h=m-1;
        }
        //printf("%lld %lld\n",l,h);
    }
    printf("Case #%d: %lld\n",cc,h);

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        solve(i+1);

	return 0;
}
