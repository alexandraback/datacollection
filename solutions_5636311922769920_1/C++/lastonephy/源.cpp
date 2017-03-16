#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<queue>
#define eps 1e-8
#define MOD 1000000007
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1010
using namespace std;

LL pows[100];
vector<LL> ans;

void find(int s, int c)
{
	LL no = 1;
	for(int i = 1; i <= c; i ++)
	{
		no += pows[c - i] * (s - 1);
		s ++;
	}
	ans.push_back(no);
}

int main()
{
	//freopen("D-large.in","r",stdin);
	//freopen("D-large.out","w",stdout);
	int t;
	int k, c, s;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d: ",ii);
		pows[0] = 1;
		for(int i = 1; i <= c; i ++)
		{
			pows[i] = pows[i - 1] * k;
		}
		if(c * s < k)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		ans.clear();
		int x = 1;
		for(int i = 1; i <= s; i ++)
		{
			if(x > k)
			{
				break;
			}
			find(x,c);
			x += c;
		}
		int size = ans.size();
		for(int i = 0; i < size; i ++)
		{
			printf("%lld",ans[i]);
			if(i == size - 1)
			{
				printf("\n");
			}
			else
			{
				printf(" ");
			}
		}
	}
	return 0;
}