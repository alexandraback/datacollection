#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int N = 100005;
int dp[N],ok[N];
void add(int i,int a,int b){
	dp[i]=a;ok[i]=b;
}
void ouput(int n,int s1,int s2){
	for(int i=1;i<=n;i++){
		if(dp[i]==0){
			if(s1^ok[i]) putchar('E');
			else putchar('W');
		}
		else{
			if(s2^ok[i]) putchar('N');
			else putchar('S');
		}
	}
	puts("");
}
void gao(int n,int x,int y){
	memset(dp,-1,sizeof(dp));
	int tot=abs(x)+abs(y);
	int t=n*(n+1)/2;
	int temp=(t-tot)/2;
	int s1=x<0?1:0,s2=y<0?1:0;
	x=abs(x);y=abs(y);
	add(temp,0,0);
	x+=temp;
	for(int i=n;i;i--){
		if(dp[i]==-1){
			if(x>y){
				if(i<=x)
					dp[i]=0,ok[i]=1,x-=i;
				else 
					dp[i]=ok[i]=1;
			}else{
				if(i<=y)
					dp[i]=ok[i]=1,y-=i;
				else
					dp[i]=0,ok[i]=1;
			}
		}
	}
	ouput(n,s1,s2);
}
int main(){
	//freopen("B-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		int tot=abs(x)+abs(y),n=0;
		printf("Case #%d: ",++cas);
		while(true){
			n++;
			int t=n*(n+1)/2;
			if(t<tot) continue;
			if((t-tot)&1) continue;
			gao(n,x,y);
			break;
		}
	}
	return 0;
}