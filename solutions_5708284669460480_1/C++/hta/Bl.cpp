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
int K,L,S,f[10000],pp[10000];
char a[1000],c[1000];
int main()
{
	freopen("bl.in","r",stdin);
	freopen("Bl.out","w",stdout);
	int T=get();
	for(int _=1;_<=T;_++)
	{
		K=get(),L=get(),S=get();
		scanf("%s",a+1);
		scanf("%s",c+1);
		memset(f,0,sizeof(f));
		for(int i=1;i<=K;i++)f[a[i]]++;
		bool flag=1;
		long double p=1;
		for(int i=1;i<=L;i++)
		{
			p*=double(f[c[i]])/K;
			if(f[c[i]]==0)flag=0;
		}
		memset(pp,0,sizeof(pp));
		for(int i=2,j=0;i<=L;i++)
		{
			while(j&&c[i]!=c[j+1])j=pp[j];
			if(c[i]==c[j+1])++j;
			pp[i]=j;
		}
		long double ans=(S-pp[L])/(L-pp[L]);
		ans-=p*(S-L+1);
		if(!flag)ans=0;
		printf("Case #%d: %.10lf\n",_,double(ans));
	}
	return 0;
}
