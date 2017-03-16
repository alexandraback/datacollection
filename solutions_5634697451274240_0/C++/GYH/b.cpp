#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
char s[maxn];

int main()
{
	//freopen("test.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("ansB.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int z=1;z<=T;++z)
	{
		scanf("%s",s);
		int len = strlen(s);
		int ans = 0;
		for(int i=len-1;i>=0;--i)
		{
			if(s[i] == '-' && (i == len - 1 || s[i+1] != '-')) ++ans;
			if(ans && s[i] == '+' && s[i+1] != '+') ++ans;
		}
		printf("Case #%d: %d\n",z,ans);
	}
	return 0;
}
