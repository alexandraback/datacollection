#include<bits/stdc++.h>
using namespace std;
struct node{
	int next,to;
}edge[2010];
int n,a[1010],b[1010],head[1010],cnt;

void addedge(int x,int y)
{
	++cnt;
	edge[cnt].next=head[x];
	edge[cnt].to=y;
	head[x]=cnt;
}

int DFS(int x,int y)
{
	int i,mx=0;
	for(i=head[x];~i;i=edge[i].next){
		if(edge[i].to==y) continue;
		mx=max(mx,DFS(edge[i].to,y));
	}
	return mx+1;
}

void fuck()
{
	int i,j,t,loop=0,lin=0;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	cnt=-1;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		addedge(a[i],i);
	}
	for(i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		t=0;j=i;
		while(b[j]==0){
			b[j]=++t;
			j=a[j];
		}
		loop=max(loop,t-b[j]+1);
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++){
			if(a[i]!=j||a[j]!=i) continue;
			lin+=DFS(i,j)+DFS(j,i);
			//printf("%d %d %d %d\n",i,j,DFS(i,j),DFS(j,i));
		}
	printf("%d\n",max(loop,lin));
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
   int i,t;
   scanf("%d",&t);
   for(i=1;i<=t;i++){
	   printf("Case #%d: ",i);
	   fuck();
   }
 return 0;
}
