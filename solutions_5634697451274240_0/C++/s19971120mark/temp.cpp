#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int T,tt,i,L,ans;
char st[1005000];
int main(){
	freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);
	scanf("%d",&T);
	for (tt = 1;tt<=T;tt++)
	{
		memset(st,0,sizeof(st));
		scanf("%s",st);
		L = strlen(st);
		ans = 1;
		for (i = 1;i<L;i++)
		{
			if (st[i] != st[i-1]) ans++;
		}
		if (st[L-1] == '+') ans--;
		printf("Case #%d: %d\n",tt,ans);
	}
}
