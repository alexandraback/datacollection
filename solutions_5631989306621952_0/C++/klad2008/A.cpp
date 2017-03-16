#include <bits/stdc++.h>
using namespace std;
int T,len;
char s[1010],ans[1010],t1[1010],t2[1010];
bool bigger(char t1[],char t2[],int len){
	for (int i=0;i<=len;i++){
		if (t1[i]>t2[i])return 1;
		if (t1[i]<t2[i])return 0;
	}
	return 0;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		scanf("%s",s);
		len=strlen(s);
		memset(ans,0,sizeof(ans));
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		ans[0]=s[0];
		for (int i=1;i<len;i++){
			for (int j=0;j<i;j++)
				t1[j]=ans[j],t2[j+1]=ans[j];
			t1[i]=s[i];t2[0]=s[i];
			if (bigger(t1,t2,i))
				for (int j=0;j<=i;j++)ans[j]=t1[j];
				else	for (int j=0;j<=i;j++)ans[j]=t2[j];
		}
		printf("Case #%d: %s\n",tt,ans);
	}
}