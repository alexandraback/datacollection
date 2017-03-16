#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn (1005)
using namespace std;

struct Tnode{
	int x,y,z;
}a[maxn],b[maxn];

int test,n;
bool hash[maxn];

bool cmp(Tnode a,Tnode b){
	return a.x<b.x;
}
int main(){
	freopen("i.txt","r",stdin);
	int cnt=1;
	for (scanf("%d",&test);test--;cnt++){
		printf("Case #%d: ",cnt);
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].x=x;
			a[i].y=i;
			a[i].z=y;
			b[i].x=y;
			b[i].y=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		int tot=0,res=0;
		int i=1,j=1;
		memset(hash,0,sizeof(hash));
		for (;j<=n;){
			if (b[j].x<=tot){
				if (hash[b[j].y]) tot++;
					else tot+=2;
				hash[b[j].y]=true;
				j++;
				res++;
			}
			else{
				/*if (hash[a[i].y]){
					i++;
					continue;
				}
				if (a[i].x>tot) break;
				hash[a[i].y]=true;
				tot++;
				res++;
				i++;*/
				int opt=-1;
				for (i=1;i<=n;i++) if (!hash[a[i].y] && a[i].x<=tot){
					if (opt==-1 || a[opt].z<a[i].z) opt=i;
				}
				if (opt==-1) break;
				hash[a[opt].y]=true;
				tot++;
				res++;
			}
		}
		if (j>n) printf("%d\n",res);
			else puts("Too Bad");
	}
	return 0;
}
