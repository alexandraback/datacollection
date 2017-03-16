#include<bits/stdc++.h>
#define ll long long
using namespace std;
int func(int r,int c,int w)
{
	if(w==c)
		return c;
	else
	{
		return (ceil((c*1.0)/w) -1 + w);
	}
}
int main()
{
	freopen("input.in","r",stdin);
freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	for(int cases=1;cases<=t;cases++)	
	{
		int res=0,n,r,c,w;
		scanf("%d %d %d",&r,&c,&w);
		res = func(r,c,w);
			printf("Case #%d: %d\n",cases,res);
 
	}
	return 0;
}

