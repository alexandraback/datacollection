#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,d,v,a[110],ans,m;
bool visit[110],ok;

 bool judge()
 {
 	int i,j,dp[110]={0};
 	bool f=1;
	dp[0]=1;
	for(i=1;i<=m+d;i++){
		for(j=v;j>=a[i];j--){
			dp[j]|=dp[j-a[i]];
		}
	}
	for(i=1;i<=v;i++) 
		if(dp[i]==0){
			f=0;
			break;
		}
	if(f) return 1;
	return 0;
 }
 
 void DFS(int x)
 {
 	int i;
 	if(ok) return;
 	if(x-d>=m){
	 	if(judge()){
	 		ans=m;ok=1;
	 	}
	 	return;
 	}
 	for(i=1;i<=30;i++){
 		if(visit[i]) continue;
 		visit[i]=1;a[x+1]=i;
 		DFS(x+1);
 		visit[i]=0;
 	}
 }

 void run()
 {
 	int i;
 	ok=0;
 	memset(visit,0,sizeof(visit));
 	scanf("%d%d%d",&n,&d,&v);
 	for(i=1;i<=d;i++){
 		scanf("%d",&a[i]);
 		visit[a[i]]=1;
 	}
 	for(m=0;m<=30;m++)
 		if(!ok) DFS(d);
 	printf("%d\n",ans);
 }

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		run();
	}
 return 0;
}

