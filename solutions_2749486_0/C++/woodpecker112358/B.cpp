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
using namespace std;
typedef long long mint;
typedef unsigned long long umint;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("Bout.txt","w",stdout);
	int t,T,x,y;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	    scanf("%d%d",&x,&y);
	    printf("Case #%d: ",t);
	    Rep(i,Abs(x))
	    {
	        if(x>0)
                printf("WE");
            else
                printf("EW");
	    }
	    Rep(i,Abs(y))
	    {
	        if(y>0)
                printf("SN");
            else
                printf("NS");
	    }
	    printf("\n");
	}
	return 0;
}

