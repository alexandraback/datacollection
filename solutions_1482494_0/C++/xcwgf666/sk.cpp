#include<stdio.h>
#include<algorithm>
using namespace std;
int tqn,tqi,n,i,j,was[1111],was2[1111],x[1111],y[1111],have,steps,fla,mi,mj;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=1;tqi<=tqn;tqi++){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d%d",&x[i],&y[i]);
			was[i]=0;
			was2[i]=0;
		}
		have=steps=0;
		for(i=1; ;i++){
			fla=0;
			for(j=1;j<=n;j++)if(was2[j]==0&&y[j]<=have){
				if(!was[j])have+=2;else have+=1;
				was[j]=was2[j]=1;
				++steps;fla=1;
				break;
			}
			if(!fla){
				mi=-1000000000;mj=0;
				for(j=1;j<=n;j++)if(was[j]==0&&x[j]<=have&&y[j]>mi){
					mi=y[j];mj=j;
				}
				if(mj){
					was[mj]=1;
					++have;++steps;fla=1;
				}
			}
			if(!fla)break;
		}
		fla=0;
		for(i=1;i<=n;i++)if(!was[i]||!was2[i])fla=1;
		if(fla)printf("Case #%d: Too Bad\n",tqi);else
		printf("Case #%d: %d\n",tqi,steps);
	}
	return 0;
}