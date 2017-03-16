#include<stdio.h>
int tcn,tc;
int n,e,r;
int chk[10100];
int v[10100];
long long int ans;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,t,x;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%d%d",&e,&r,&n);
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d",&v[i]);
			chk[i]=0;
		}
		v[n]=-1;
		for(i=0;i<n;i++){
			t=n;
			for(j=0;j<n;j++){
				if(chk[j]==0&&v[j]>v[t])t=j;
			}
			if(t==n)break;
			chk[t]=1;
			for(j=t+1;j<n;j++){
				if(chk[j]==1)break;
			}
			x=e;
			if(j!=n&&e-((j-t)*r)>0)x-=e-((j-t)*r);
			for(j=t-1;j>=0;j--){
				if(chk[j]==1)break;
			}
			if(j!=-1&&e-((t-j)*r)>0)x-=e-((t-j)*r);
			if(x<0)x=0;
			ans+=(long long int)x*v[t];
		}
		printf("Case #%d: %lld\n",tc,ans);
	}
}