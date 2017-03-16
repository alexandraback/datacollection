#include<bits/stdc++.h>

using namespace std;

int T;
char s[110];

int main()
{
	freopen("B.in","r",stdin);
	
	scanf("%d\n",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%s\n",s);
		printf("Case #%d: ", tt);
		int n=strlen(s);
		int i, ans=0;
		for(i=n-1;i>=0;i--) if (s[i]=='-') { ans++; break; }
		for(int j=i-1;j>=0;j--) if (s[j]!=s[j+1]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

