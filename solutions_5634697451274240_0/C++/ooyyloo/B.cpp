#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
typedef long long LL;

char s[200];
char ss[200];
int main() {
	int T; scanf("%d",&T);
	for (int tt=1;tt<=T;tt++) {
		scanf("%s",s);
		int len=strlen(s);
		printf("Case #%d: ",tt);

		int po=0;
		for (int i=0;i<len;i++) {
			ss[po++]=s[i];
			while (i+1<len&&s[i+1]==s[i]) i++;
		}
		int ans=0;
		for (int i=0;i<po;i++) {
			if (ss[i]=='+') continue;
			if (i==0) ans+=1;
			else ans+=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
	未证明
*/
