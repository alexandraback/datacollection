#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[105];
int task,n,ans;
int main() {
	//freopen("B-large.in","r",stdin);
	//freopen("B-large.out","w",stdout);
	scanf("%d",&task);
	for (int id=1;id<=task;id++) {
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		while (n&&(s[n]=='+')) n--;
		if (n==0) {
			printf("Case #%d: 0\n",id); continue;
		}
		ans=1;
		for (int i=2;i<=n;i++) if (s[i]!=s[i-1]) ans++;
		printf("Case #%d: %d\n",id,ans);
	}
	return 0;
}
