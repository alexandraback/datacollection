#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int find(int r,int c,int w)
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
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		int result=0,N,r,c,w;
 
		scanf("%d %d %d",&r,&c,&w);
		result = find(r,c,w);
 
			printf("Case #%d: %d\n",++cas,result);
 
	}
	return 0;
}
