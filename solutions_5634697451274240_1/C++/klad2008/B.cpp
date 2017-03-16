#include <bits/stdc++.h>
using namespace std;
int T,N,ans,len;
char ss[110];
int s[110];
int work(int step,int head,int tail){
	if (step==0)return 0;
	if (tail==1)return work(step-1,head,tail^1);
	if (head==1)
		return work(step-1,0,0)+1;
		else return work(step-1,1,0)+1;
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		scanf("%s",ss);
		len=strlen(ss);
		N=0;s[++N]=(ss[0]=='+');
		for (int i=1;i<len;i++)
			if (ss[i]!=ss[i-1])s[++N]=(ss[i]=='+');
		ans=work(N,s[1],s[N]);
		printf("%d\n",ans);
	}
}