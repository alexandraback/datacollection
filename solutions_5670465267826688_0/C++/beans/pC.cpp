#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL maxL=10000+5;
const LL MUL[8][8]={{0,1,2,3,4,5,6,7},{1,4,3,6,5,0,7,2},{2,7,4,1,6,3,0,5},{3,2,5,4,7,6,1,0},{4,5,6,7,0,1,2,3},{5,0,7,2,1,4,3,6},{6,3,0,5,2,7,4,1},{7,6,1,0,3,2,5,4}};
char s[maxL*4];
LL pre[maxL*4];
int main()
{
	//freopen("inCsmall.in","r",stdin);
	//freopen("outCsmall.out","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--)
	{
		int ipos=-1,kpos=-1;
		LL L,X;
		scanf("%I64d%I64d%s",&L,&X,s+1);
		pre[0]=0;
		for(int i=1;i<=L*min(4LL,X);i++)
		{
			if(s[(i-1)%L+1]=='i') pre[i]=MUL[pre[i-1]][1];
			else if(s[(i-1)%L+1]=='j') pre[i]=MUL[pre[i-1]][2];
			else pre[i]=MUL[pre[i-1]][3];
		}
		//for(int i=1;i<=L*min(4LL,X);i++) printf("pre[%d]=%d\n",i,pre[i]);
		int flag=0,all=0;
		for(int i=0;i<X%4LL;i++) all=MUL[all][pre[L]];
		//printf("all=%d\n",all);
		if(all==4)
		{
			for(int i=1;i<=L*min(4LL,X);i++) if(pre[i]==1) {ipos=i;break;}
			for(int i=1;i<=L*min(4LL,X);i++) if(pre[i]==3) {kpos=i;if(i+4*L<=L*X) {kpos=i+4*L;break;}}
			//printf("ipos=%d kpos=%d\n",ipos,kpos);
			if(ipos!=-1 && kpos!=-1 && ipos<kpos) flag=1;
		}
		printf("Case #%d: %s",++kase,flag?"YES\n":"NO\n");
	}
}
