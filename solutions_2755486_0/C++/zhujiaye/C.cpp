#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn (105)
#define BASE (400)
using namespace std;

struct Tnode{
	int d,w,e,s;
}att[maxn];

int wall[1005],M,N,d,n,w,e,s,delta_d,delta_p,delta_s,cnt,test;

bool cmp(Tnode a,Tnode b){
	return a.d<b.d;
}
int main(){
	freopen("i.txt","r",stdin);
	
	cnt=1;
	for (scanf("%d",&test);test--;cnt++){
		scanf("%d",&N);
		printf("Case #%d: ",cnt);
		M=0;
		for (int i=0;i<N;i++){
			scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&delta_d,&delta_p,&delta_s);
			for (int j=0;j<n;j++){
				att[M].d=d;
				att[M].w=w;
				att[M].e=e;
				att[M].s=s;
				d+=delta_d;
				w+=delta_p;
				e+=delta_p;
				s+=delta_s;
				M++;
			}
		}
		sort(att,att+M,cmp);
		memset(wall,0,sizeof(wall));
		int res=0;
		for (int i=0,prei=-1;i<M;i++){
			bool ok=false;
			for (int j=att[i].w;j<att[i].e && !ok;j++)
				if (wall[j+BASE]<att[i].s) ok=true;
			if (ok)
				res++;
			if (i==M-1 || att[i].d!=att[i+1].d){
				for (int j=prei+1;j<=i;j++){
					for (int k=att[j].w;k<att[j].e;k++)
						if (wall[k+BASE]<att[j].s)
							wall[k+BASE]=att[j].s;
				}
				prei=i;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
