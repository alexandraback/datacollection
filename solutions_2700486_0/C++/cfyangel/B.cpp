#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int x,y,n;
int t,id;
int i,j,k;
double ans,a,b;

int main()
{
	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&t);
    for (id=1;id<=t;id++)
    {
        scanf("%d%d%d",&n,&x,&y);
		printf("Case #%d: ",id);
		if (abs(x)+abs(y)==0)
		{
		    ans=1;
		}
		else if (abs(x)+abs(y)==2)
		{
		    if (n==1)ans=0;
		    else if (n==2)
		    {
		        if (y==0)ans=0.5;
		        else ans=0;
		    }
		    else if (n==3)
		    {
		        if (y==0)ans=0.75;
		        else if (y==1)ans=0.25;
		        else ans=0;
		    }
		    else if (n==4)
		    {
		        if (y==0)ans=1;
		        else if (y==1)ans=0.5;
		        else ans=0;
		    }
		    else if (n==5)
		    {
		        if (y<=1)ans=1;
		        else ans=0;
		    }
		    else ans=1;
		}
		else if (abs(x)+abs(y)==4)
		{
		    if (n<=6)ans=0;
		    else if (n==7)
		    {
		        if (y==0)ans=0.5;
		        else ans=0;
		    }
		    else if (n==8)
		    {
		        if (y==0)ans=0.75;
		        else if (y==1)ans=0.25;
		        else ans=0;
		    }
		    else if (n==9)
		    {
		        if (y==0)ans=1-1.0/8;
		        else if (y==1)ans=0.5;
		        else if (y==2)ans=1.0/8;
		        else ans=0;
		    }
		    else if (n==10)
		    {
		        if (y==0)ans=1-1.0/16;
		        else if (y==1)ans=11/16.0;
		        else if (y==2)ans=5.0/16;
		        else if (y==3)ans=1.0/16;
		        else ans=0;
		    }
		    else if (n==11)
		    {
		        if (y==0)ans=1;
		        else if (y==1)ans=26/32.0;
		        else if (y==2)ans=16.0/32;
		        else if (y==3)ans=6.0/32;
		        else ans=0;
		    }
		    else if (n==12)
		    {
		        if (y==0)ans=1;
		        else if (y==1)ans=1;
		        else if (y==2)ans=42.0/64;
		        else if (y==3)ans=22.0/64;
		        else ans=0;
		    }
		    else if (n==13)
		    {
		        if (y==0)ans=1;
		        else if (y==1)ans=1;
		        else if (y==2)ans=1;
		        else if (y==3)ans=64.0/128;
		        else ans=0;
		    }
		    else if (n==14)
		    {
		        if (y<5)ans=1;
		        else ans=0;
		    }
		    else if (n==15)
		    {
		        if (y<6)ans=1;
		        else ans=0;
		    }
		    else ans=1;

		}
		else if (abs(x)+abs(y)==6)
		{
		    if (n<=15)ans=0;
		    else if (n==16)
		    {
		        if (y==0)ans=0.5;
		        else ans=0;
		    }
		    else if (n==17)
		    {
		        if (y==0)ans=0.75;
		        else if (y==1)ans=0.25;
		        else ans=0;
		    }
		    else if (n==18)
		    {
		        if (y==0)ans=1-1.0/8;
		        else if (y==1)ans=0.5;
		        else if (y==2)ans=1.0/8;
		        else ans=0;
		    }
		    else if (n==19)
		    {
		        if (y==0)ans=1-1.0/16;
		        else if (y==1)ans=11/16.0;
		        else if (y==2)ans=5.0/16;
		        else if (y==3)ans=1.0/16;
		        else ans=0;
		    }
		    else if (n==20)
		    {
		        if (y==0)ans=31/32;
		        else if (y==1)ans=26/32.0;
		        else if (y==2)ans=16.0/32;
		        else if (y==3)ans=6.0/32;
		        else if (y==4)ans=1.0/32;
		        else ans=0;
		    }
		    else ans=1;
		}
		else ans=0;

		printf("%lf\n",ans);
    }
	return 0;
}
/*
1
1+5=6
1+5+9=15
C4,2+C4,3+C4,4
6+4+1
*/
