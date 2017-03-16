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
const int a[5][5]=
{
{0,0,0,0,0},
{0,1,2,3,4},
{0,2,1,4,3},
{0,3,4,1,2},
{0,4,3,2,1}
};
const bool b[5][5]=
{
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,1,0,1},
{0,0,1,1,0},
{0,0,0,1,1}
};
char s[20000];
int main()
{
	freopen("Cs.in","r",stdin);
	freopen("Cs.out","w",stdout);
	int T=get();
	for(int _=1;_<=T;_++)
	{
		int n=get(),x=get(),L=n;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='1')s[i]=1;
			else if(s[i]=='i')s[i]=2;
			else if(s[i]=='j')s[i]=3;
			else s[i]=4;
		for(int i=1;i<x;i++)
			for(int j=1;j<=n;j++)s[++L]=s[j];
		int u=s[1],v=0,p,q;
		for(p=1;p<L&&!(u==2&&!v);p++)v^=b[u][s[p+1]],u=a[u][s[p+1]];
		u=s[L],v=0;
		for(q=L;q>1&&!(u==4&&!v);q--)v^=b[s[q-1]][u],u=a[s[q-1]][u];
		u=s[1],v=0;
		for(int i=1;i<L;i++)v^=b[u][s[i+1]],u=a[u][s[i+1]];
		printf("Case #%d: ",_);
		if(q-p-1>0&&u==1&&v)puts("YES");else puts("NO");
	}
	return 0;
}
