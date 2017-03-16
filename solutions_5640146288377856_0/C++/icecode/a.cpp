#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int ans,t,i,j,n,k,r,c,w;
	cin >> t;
	for(i=1;i<=t;i++)
	{
		cin >> r >> c >> w;
		ans = (c/w)*(r-1) + w + c/w - (c%w==0);
		printf("Case #%d: %d\n",i,ans);
	}
	printf("");
	return 0;
}
