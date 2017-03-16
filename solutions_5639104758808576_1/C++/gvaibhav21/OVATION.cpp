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
	freopen("out.txt","w",stdout);
	freopen("in.txt","r",stdin);
	int t,s,i,j,cursum;
	char a[10000];
	int ans;
	sd(t);
	for(j=1;j<=t;++j)
	{
		ans=0;
		sd(s);
		scanf("%s",&a);
		cursum=0;
		for(i=0;i<=s;++i)
		{
			if(cursum<i)
			{
				ans=ans+i-cursum;
				cursum=i;
			}
			cursum=cursum+a[i]-'0';
		}
		printf("Case #%d: %d\n",j,ans);
	}
	fclose(stdin);
	fclose(stdout);
}