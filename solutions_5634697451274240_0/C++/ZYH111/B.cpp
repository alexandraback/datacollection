#include<cstdio>
#include<cstring>
char S[110];
int main()
{
	int i,L,T,_T,ans;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for (_T=1;_T<=T;_T++)
	{
		scanf("%s",S+1);
		L=strlen(S+1); ans=0;
		for (i=1;i<=L-1;i++)
			if (S[i]!=S[i+1]) ans++;
		if (S[L]=='-') ans++;
		printf("Case #%d: %d\n",_T,ans);
	}
	return 0;
}
