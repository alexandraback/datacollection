#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#include<time.h>
#define ll __int64
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int i;
int tcase=0;
int n,r,c,w;
int ans;
int t;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);freopen("A-output.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&r,&c,&w);
		ans= c/w * r+ w-1;
		if( c%w )	ans++;
		printf("Case #%d: %d\n",++tcase,ans);
	}
}
