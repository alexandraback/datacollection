#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<functional>
#include<bitset>
using namespace std;
const double eps=1e-9;
const double pi=acos(-1.0);
const int mod=1000000007;

int main()
{
	int i,ans,t,tt=0,n,r,c,w;
	freopen("A-large.in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&r,&c,&w);
		ans=c/w*r+w-1;
		if(c%w)
			ans++;
		printf("Case #%d: %d\n",++tt,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
99
1 4 2
1 7 7
2 5 1

Case #1: 3
Case #2: 7
Case #3: 10
*/

