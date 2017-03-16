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
#define rrep(i,n) for((i)=(n);(i)>=0;(i)--)
#define Pii pair<int,int>
#define PB push_back
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int main()
{
	freopen("A-small-attempt2.in","r",stdin);
	freopen("sol.txt","w",stdout);
	int t,T,s[105],n,i,sm=0,j,smp;
	bool tmp[105];
	long double val;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    scanf("%d",&n);
	    sm=smp=0;
	    rep(i,n)
	    {
            scanf("%d",&s[i]);
            sm+=s[i];
            tmp[i]=false;
	    }
	    j=0;
	    for(i=0;i<n;i++)
	    {
	        if(2*sm>n*s[i])
                {
                    tmp[i]=true;
                    smp+=s[i];
                    j++;
                }
	    }
	    //cout<<(smp+sm)/(j*1.0)-s[0]<<endl;
	    printf("Case #%d: ",t);
	    for(i=0;i<n-1;i++)
	    {
	        if(tmp[i])
                {
                    val=(smp+sm)/(j*1.0);
                    printf("%llf ",((val-s[i])/(sm))*100.0);
                }
            else
                printf("0.00000 ");
	    }
	    if(tmp[n-1])
	    {
	        val=(smp+sm)/(j*1.0);
	        printf("%llf\n",((val-s[n-1])*100.0)/(sm));
	    }
	    else
            printf("0.00000\n");
	}
	return 0;
}

