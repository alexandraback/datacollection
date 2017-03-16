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
typedef long long LL;
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
int n,a[100000],C,D,V;
bool f[10000],u[10000];
int main()
{
	freopen("Cs.in","r",stdin);
	freopen("Cs.out","w",stdout);
	int T=get();
	for(int _=1;_<=T;_++)
	{
		C=get(),D=get(),V=get();
		memset(u,0,sizeof(u));
		for(int i=1;i<=D;i++)a[i]=get();
		int ans=0;
		if(C==1)
		{
			memset(f,0,sizeof(f));
			f[0]=1;
			for(int i=1;i<=D;i++)
				for(int j=V;j>=a[i];j--)f[j]|=f[j-a[i]];
			while(1)
			{
				int p=0;
				for(;f[p]&&p<=V;p++);
				if(p>V)break;
				ans++;
				cerr<<p<<" ";
				for(int j=V;j>=p;j--)f[j]|=f[j-p];
			}
			cerr<<endl;
			//printf("Case #%d: %d\n",_,ans);
		}
		printf("Case #%d: %d\n",_,ans);
	}
	return 0;
}
