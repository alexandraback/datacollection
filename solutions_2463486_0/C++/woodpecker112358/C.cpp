#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cctype>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<map>
#include<set>
#define pi (acos(-1.0))
#define Abs(a) (((a)<0) ? (-(a)) :(a) )
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define Rep(i,n) for(int i=0;i<(n);i++)
#define Rrep(i,n) for(int i=n-1;i>=0;i--)
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
#define Size(x) ((int)(x.size()))
#define SZ 10000001
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int cnt[SZ];
bool ispalin(mint val)
{
    int a[17],cnt=0,i,j;
    while(val)
    {
        a[cnt++]=val%10;
        val/=10;
    }
    for(i=0,j=cnt-1;i<j;i++,j--)
        if(a[i]!=a[j])
            return false;
    return true;
}
int msqrt(mint val)
{
    mint lo=0,hi=100000000,mid;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        if(mid*mid==val)
            return mid;
        if(mid*mid<val)
            lo=mid+1;
        else
            hi=mid;
    }
    if((lo*lo)!=val)
        lo--;
    return lo;
}
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("Cout.txt","w",stdout);
	int t,T,i;
	mint a,b;
	scanf("%d",&T);
	for(i=1;i<SZ;i++)
	{
	    if(ispalin(i)&&ispalin((i*1LL)*i))
	    {
	        //cout<<i<<endl;
            cnt[i]=cnt[i-1]+1;
	    }
        else
            cnt[i]=cnt[i-1];
	}
	for(t=1;t<=T;t++)
	{
	    scanf("%lld%lld",&a,&b);
	    a=msqrt(a-1);
	    b=msqrt(b);
	    //cout<<a<<" "<<b<<endl;
		printf("Case #%d: %d\n",t,cnt[b]-cnt[a]);
	}
	return 0;
}

