#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define MaxN 1000
using namespace std;
int T,n,now,cnt,f[MaxN][3];
struct Node{
	int a,b;
}g[MaxN];
bool cmp(Node a,Node b){
	return (a.b>b.b);
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d%d",&g[i].a,&g[i].b);
		sort(g+1,g+1+n,cmp);
		bool flag=true;
		now=cnt=0;
		memset(f,0,sizeof f);
		while (flag){
			flag=false;
			for (int i=1;i<=n;i++)
				if (!f[i][2] && now>=g[i].b){
					now+=2-f[i][1];
					f[i][2]=f[i][1]=1;
					flag=true;
					break;
				}
			if (flag){
				cnt++;
				continue;
			}
			for (int i=1;i<=n;i++)
				if(!f[i][1] && now>=g[i].a){
					now++;
					f[i][1]=1;
					flag=true;
					break;
				}
			if (flag){
				cnt++;
				continue;
			}
		}
		flag=true;
		for (int i=1;i<=n;i++)
			if (!f[i][2]) {
				flag=false;
				break;
			}
		printf("Case #%d: ",t);
		if (flag) printf("%d\n",cnt);
		else printf("Too Bad\n");
	}
}
