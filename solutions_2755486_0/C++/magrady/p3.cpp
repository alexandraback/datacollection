#include<stdio.h>
#include<string.h>
#include<algorithm>
struct T {
	int m;
	long long d,dd,w,e,dwe,s,ds;
} t[1001];
struct ATT {
	long long d,w,e,s;
	bool operator<(ATT att) const {
		return d<att.d;
	}
} att[1000001];
int h[2000001];
int main(){
	int i,j,k;
	int T,TN,n;
	int st,ed,ok,su;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%I64d%d%I64d%I64d%I64d%I64d%I64d%I64d",
				&t[i].d,&t[i].m,&t[i].w,&t[i].e,&t[i].s,&t[i].dd,&t[i].dwe,&t[i].ds);
		}
		k=0;
		for(i=0;i<n;i++){
			for(j=0;j<t[i].m;j++){
				att[k++]=(ATT){t[i].d+t[i].dd*j,1000000+t[i].w+t[i].dwe*j,1000000+t[i].e+t[i].dwe*j,t[i].s+t[i].ds*j};
			}
		}
		std::sort(att,att+k);
		//for(i=0;i<k;i++){
			
		//}
		for(i=0;i<2000000;i++){
			h[i]=0;
		}
		su=0;
		for(st=0;st<k;st=ed){
			for(ed=st;ed<k&&att[ed].d==att[st].d;ed++);
			for(i=st;i<ed;i++){
				ok=0;
				for(j=att[i].w;j<att[i].e;j++){
					if(h[j]<att[i].s){
						ok=1;
					}
				}
				//printf("%I64d %I64d %I64d %I64d\n",att[i].d,att[i].w,att[i].e,att[i].s);
				if(ok)su++;//,puts("ok");
				
			}
			for(i=st;i<ed;i++){
				for(j=att[i].w;j<att[i].e;j++){
					if(h[j]<att[i].s){
						h[j]=att[i].s;
					}
				}
			}
			/*for(i=0;i<10;i++){
				printf("%d ",h[i]);
			}
			puts(";");*/
		}
		printf("Case #%d: %d\n",T,su);
	}
}
