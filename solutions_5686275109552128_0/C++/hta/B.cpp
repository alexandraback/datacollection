#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
#include <vector>
#include <ctime>
#include <set>
#include <bitset>
#include <deque>
#include <fstream>
#include <stack>
#include <map>
#include <utility>
#include <cassert>
#include <string>
#include <iterator>
#include <cctype>
using namespace std;
double getd()
{
    double d=0,d2=0,d3=1; char ch; bool flag=0;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')flag=true;else d=ch-48;
    while(isdigit(ch=getchar()))d=d*10+ch-48;
    if(ch=='.')
    {
        while(isdigit(ch=getchar()))d2=d2*10+ch-48,d3=d3*0.1;
        d+=d3*d2;
    }
    if(flag)return -d;else return d;
}
int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
int n,s,f[2000],a[2000];
int main()
{
	freopen("Bs.in","r",stdin);
	freopen("Bs.out","w",stdout);
	int T=get();
	for(int _=1;_<=T;_++)
	{
		n=get();s=0;
		memset(f,0,sizeof(f));
		for(int i=1,x;i<=n;i++)s=max(s,x=get()),f[x]++;
		int ans=s;
		for(int i=s;i;i--)
		{
			memcpy(a,f,sizeof(f));
			int cnt=0;
			for(int j=s;j>i;j--)
			{
				cnt+=a[j],a[j-i]+=a[j];
			}
			ans=min(ans,cnt+i);
		}
		printf("Case #%d: %d\n",_,ans);
	}
	return 0;
}
