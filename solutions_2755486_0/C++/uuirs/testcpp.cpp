#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define debug(x) cout<<#x<<'='<<x<<endl;
struct node{
	int d,n,w,e,s,del_d,del_p,del_s;
}no[20];
int a[200][4],an;
int wa[10000];
int cmp(const void*x,const void*y){
	return ((int*)x)[3]>((int*)y)[3]?1:-1;
}
int check(int x){
	for(int i=a[x][0]*2+1000;i<=a[x][1]*2+1000;i++){
		if(wa[i]<a[x][2])return 1;
	}
	return 0;
}
void solve(int x){
	for(int i=a[x][0]*2+1000;i<=a[x][1]*2+1000;i++){
		if(wa[i]<a[x][2])wa[i]=a[x][2];
	}
}
void gao(int x){
	int w,e,s,d;
	for(int i=0;i<no[x].n;i++){
		w=no[x].w+i*no[x].del_p;
		e=no[x].e+i*no[x].del_p;
		s=no[x].s+i*no[x].del_s;
		d=no[x].d+i*no[x].del_d;
		a[an][0]=w;
		a[an][1]=e;
		a[an][2]=s;
		a[an][3]=d;
		an++;
	}
}
int main(){
	int T,x,y;
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	// EWSN
	scanf("%d",&T);
	int cas=1,n;
	while(T--){
		scanf("%d",&n);
		int ans=0;
		printf("Case #%d: ",cas++);
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d%d",&no[i].d,&no[i].n,&no[i].w,&no[i].e,&no[i].s);
			scanf("%d%d%d",&no[i].del_d,&no[i].del_p,&no[i].del_s);
		}
		an=0;
		for(int i=0;i<n;i++){
			gao(i);
		}
		qsort(a,an,sizeof a[0],cmp);
		for(int i=0;i<10000;i++)wa[i]=0;
		int td;
		for(int i=0;i<an;){
			td=i;
			while(td<an&&a[td][3]==a[i][3]){
				ans+=check(td);
				td++;
			}
			for(;i<td;i++){
				solve(i);
			}
		}
		printf("%d\n",ans);
	}
}
