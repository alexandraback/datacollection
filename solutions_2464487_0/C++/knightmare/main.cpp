#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define LL long long

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.txt","w",stdout);
	int n,m;
	int i,j,k;
	int cas=0,T;
	cin>>T;
	while(T--)
	{
		int ans=0;
		cas++;
		int r,t;
		scanf("%d%d",&r,&t);
		int tmp=(r+1)*(r+1)-r*r;
		k=3;
		while(t>=tmp)
		{
			t-=tmp;
			ans++;
			tmp=(r+k)*(r+k)-(r+k-1)*(r+k-1);
			k+=2;
		}

		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;	
}
