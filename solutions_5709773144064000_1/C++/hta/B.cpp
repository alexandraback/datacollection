#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
inline int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T=get();
	for(int t=1;t<=T;t++)
	{
		double c,f,x,r=2.0,ans=0;
		scanf("%lf%lf%lf",&c,&f,&x);
		while(x/r>c/r+x/(r+f))ans+=c/r,r+=f;
		ans+=x/r;
		printf("Case #%d: %.9lf\n",t,ans);
	}
	return 0;
}
