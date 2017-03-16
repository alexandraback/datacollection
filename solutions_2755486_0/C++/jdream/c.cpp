#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct rec{int d,w,e,s;}a[1101];
bool cmp(rec x,rec y){
	return x.d<y.d;
}
int T,TT,m,n,minw,d,num,w,e,s,delta_d,delta_p,delta_s,st;
int i,j,k,ans,B[10000];
int main(){
	freopen("cc.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&TT);
	for(T=1;T<=TT;T++){
		scanf("%d",&n);
		m=0;
		minw=10000;
		for(i=1;i<=n;i++){
			scanf("%d",&d);
			scanf("%d",&num);
			scanf("%d%d",&w,&e);
			scanf("%d",&s);
			scanf("%d",&delta_d);
			scanf("%d",&delta_p);
			scanf("%d",&delta_s);
			for(j=1;j<=num;j++){
				++m;
				a[m].d=d;a[m].w=w;a[m].e=e;
				a[m].s=s;
				minw=min(minw,w);
				w+=delta_p;e+=delta_p;
				d+=delta_d;
				s+=delta_s;
			}
		}
		sort(a+1,a+m+1,cmp);
		minw--;
		for(i=1;i<=m;i++)a[i].w-=minw,a[i].e-=minw;
		memset(B,0,sizeof(B));
		ans=0;a[m+1].d=-1;st=1;
		for(i=1;i<=m;i++){
			for(j=a[i].w+1;j<=a[i].e;j++)
				if(B[j]<a[i].s){
					ans++;break;
				}
			if(a[i+1].d!=a[i].d){
				for(k=st;k<=i;k++)
					for(j=a[k].w+1;j<=a[k].e;j++)
						B[j]=max(B[j],a[k].s);
				st=i+1;
			}
		}
		printf("Case #%d: %d\n",T,ans);
	}
	
}