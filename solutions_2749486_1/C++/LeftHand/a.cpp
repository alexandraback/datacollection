#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=1<<29;

int vis[10010];
int f[10010];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,x,y,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		int t=abs(x)+abs(y);
		int sum=0,n;
		for(int i=1;sum<t;i++){
			sum+=i;
			n=i;
			vis[i]=1;
		}
		sum-=t;
		if(sum%2){
			if(n%2){
				vis[n+1]=-1;
				vis[n+2]=1;
				sum--;
				n+=2;
			}
			else n++,sum+=n,vis[n]=1;
		}
		vis[sum/2]=-1;
		t=min(abs(x),abs(y));
		sum=0;
		memset(f,0,sizeof(f));
		for(int i=1;sum<t;i++){
			if(vis[i]!=1) continue;
			sum+=i;
			f[i]=1;
		}
		sum-=t;
		if(vis[sum]==-1) f[sum]=1;
		else f[sum]=0;
		printf("Case #%d: ",ri++);
		for(int i=1;i<=n;i++){
			//printf("%d ",vis[i]);
			if(f[i]){
				if(vis[i]*x>0){
					printf("E");
				}else
					printf("W");
			}else{
				if(vis[i]*y>0){
					printf("N");
				}else
					printf("S");
			}
		}
		puts("");

	}
}
