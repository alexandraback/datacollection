#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cctype>
#include <cstring>
#include <string>
#include <numeric>
#include <functional>
#include <iomanip>
#include <ctime>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;

bool vis[2000005];
int digit;
LL exd[8];
int count_dig(int x)
{
    int d=0;
    while(x>0)
    {
        d++;
        x/=10;
    }
    return d;
}
int circle(int x,int k)
{
    LL nexd=exd[digit-k];
    LL head=x/nexd;
    LL nx=x;
    nx*=exd[k];
    nx=nx%exd[digit];
    nx+=head;
    if(count_dig((int)nx)==digit)return (int)nx;
    return -1;
}
int main()
{
	int T,A,B;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for(int _t=1;_t<=T;_t++)
	{
	    scanf("%d %d",&A,&B);
	    digit=count_dig(A);
	    exd[0]=1;
	    for(int i=1;i<=digit;i++)exd[i]=exd[i-1]*10;
	    memset(vis,false,sizeof(vis));
	    int res=0;
	    vector<int> V;
	    int tem,last;
	    for(int i=A;i<B;i++)
	    {
	        V.clear();
	        for(int j=1;j<digit;j++)
	        {
	            tem=circle(i,j);
                if(tem!=-1)V.push_back(tem);
	        }
	        sort(V.begin(),V.end());
	        last=-1;
	        for(int j=0;j<V.size();j++)
	        {
	            if(V[j]==last)continue;
	            tem=V[j];
	            //printf("%d->%d\n",i,tem);
	            if(tem>i&&tem<=B)res++;
	            last=tem;
	        }
	        V.clear();
	        //puts("");
	    }
	    printf("Case #%d: %d\n",_t,res);
	}
	return 0;
}
