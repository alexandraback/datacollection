#include<bits/stdc++.h>
using namespace std;
const int maxD=1000+5;
const int INF=(1<<30);
int a[maxD];
int main()
{
	//freopen("inB.in","r",stdin);
	//freopen("outBsmall.out","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--)
	{
		int D,maxP=0,ans=INF;
		scanf("%d",&D);
		for(int i=0;i<D;i++) {scanf("%d",a+i);maxP=max(maxP,a[i]);}
		for(int nt=1;nt<=maxP;nt++)
		{
			int st=0;
			for(int i=0;i<D;i++)
				if(a[i]>nt) st+=a[i]/nt-1+(a[i]%nt==0?0:1);//(a[i]+(nt-1))/nt
			//printf("nt=%d st=%d\n",nt,st);
			ans=min(ans,st+nt);
		}
		printf("Case #%d: %d\n",++kase,ans);
	}
}
