#include <bits/stdc++.h>
using namespace std;

int N;
char S[1005];

int calc()
{
	scanf("%d%s",&N,S);
	int ans=0;
	for (int i=0,x=0; i<=N; i++)
	{
		if (S[i]>'0'&&x<i) ans+=i-x,x=i;
		x+=S[i]-48;
	}
	return ans;
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++) printf("Case #%d: %d\n",i,calc());
	return 0;
}

