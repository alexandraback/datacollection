#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;
 
#define sd(a) scanf("%d",&a)
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,r,c,w,i,ans;
	sd(t);
	for(i=1;i<=t;++i)
	{
		sd(r);
		sd(c);
		sd(w);
		ans=(r-1)*(c/w);
		if(c%2==0&&w>=c/2||c%2==1&&w>c/2)
		{
			if(w==c)
				ans=ans+w;
			else
				ans=ans+w+1;
		}
		else
		{
			if(c%w==0)
				ans=ans+w+c/w-1;
			else
				ans=ans+w+c/w;
		}
		printf("Case #%d: %d\n",i,ans);
	}
}