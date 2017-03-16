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
LL ms,s,tot;
int K,L,S,f[1000];
char a[1000],b[1000],c[1000];
void dfs(int k)
{
	if(k>S)
	{
		tot++;
		LL tp=0;
		for(int i=1;i+L-1<=S;i++)
		{
			bool flag=1;
			for(int j=i;j<=i+L-1&&flag;j++)
				if(b[j]!=c[j-i+1])flag=0;
			if(flag)tp++;
		}
		s+=tp,ms=max(ms,tp);
	}else
	{
		for(int i=1;i<=K;i++)b[k]=a[i],dfs(k+1);
	}
}
int main()
{
	freopen("Bs.in","r",stdin);
	freopen("Bs.out","w",stdout);
	int T=get();
	for(int _=1;_<=T;_++)
	{
		cerr<<_<<endl;
		K=get(),L=get(),S=get();
		scanf("%s",a+1);
		scanf("%s",c+1);
		memset(f,0,sizeof(f));
		for(int i=1;i<=K;i++)f[a[i]]++;
		ms=s=tot=0;
		dfs(1);
		long double ss=s;
		printf("Case #%d: %.10lf\n",_,double(ms-(ss/tot)));
	}
	return 0;
}
