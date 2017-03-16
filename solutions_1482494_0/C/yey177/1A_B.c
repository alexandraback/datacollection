#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pair_t{
	int a,b,c,d;
}PAIR;
PAIR p[2008];
int a[1008],b[1008],f[1008],q[2008],qn;

int pcomp(PAIR *g,PAIR *h){
	if(g->a!=h->a)return g->a-h->a;
	else return g->c-h->c;
}
void push(int x){
	int i=qn++,pr;
	while(i>0){
		pr=(i-1)/2;
		if(pcomp(&p[q[pr]],&p[x])>=0)break;
		q[i]=q[pr];
		i=pr;
	}
	q[i]=x;
}
int pop(){
	int r=q[0],x=q[--qn],i=0,pc;
	while(i*2+1<qn){
		pc=i*2+1;
		if(pc+1<qn&&pcomp(&p[q[pc]],&p[q[pc+1]])<0)pc++;
		if(pcomp(&p[q[pc]],&p[x])<=0)break;
		q[i]=q[pc];
		i=pc;
	}
	q[i]=x;
	return r;
}
int comp(const void *_g,const void *_h){
	PAIR *g=(PAIR *)_g,*h=(PAIR *)_h;
	return g->b-h->b;
}

int main(){
	int t,i,k,n,tmp,po,lv,cnt;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		for(i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			p[i*2].a=0;p[i*2].b=a[i];p[i*2].c=b[i];p[i*2].d=i;
			p[i*2+1].a=1;p[i*2+1].b=b[i];p[i*2+1].d=i;	
		}
		p[n*2].a=2;p[n*2].b=2012;p[n*2].d=n;
		qsort(p,n*2+1,sizeof(PAIR),comp);
		po=lv=qn=cnt=0;
		while(po<n*2){
			while(p[po].b<=lv){
				if(p[po].a==1&&(!f[p[po].d])){
					f[p[po].d]=2;
					lv+=2;
					cnt++;
				}else{
					push(po);
				}
				po++;
			}
			if(qn){
				tmp=pop();
				f[p[tmp].d]++;
				lv++;
			}else{
				break;
			}
		}
		if(lv>=n*2)printf("Case #%d: %d\n",k,n*2-cnt);
		else printf("Case #%d: Too Bad\n",k);
	}
	return 0;
}
