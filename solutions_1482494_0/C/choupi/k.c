#include <stdio.h>
#include <stdlib.h>

struct dataT {
	int s;
	int ss;
	int p;
};

int cmp1 (const void * a, const void * b)
{
	if(((struct dataT*)a)->s==((struct dataT*)b)->s)
		return ((struct dataT*)a)->ss - ((struct dataT*)b)->ss;
	return ( ((struct dataT*)a)->s - ((struct dataT*)b)->s );
}
int cmp (const void * a, const void * b)
{
	if(((struct dataT*)a)->s==((struct dataT*)b)->s)
		return ((struct dataT*)b)->ss - ((struct dataT*)a)->ss;
	return ( ((struct dataT*)a)->s - ((struct dataT*)b)->s );
}

int main()
{
	int t,T,N,i,tS,ai,bi,flag,k;
	struct dataT a[1001];
	struct dataT b[1001];
	int c[1001];
	scanf("%d", &T);
	for(t=0;t<T;t++) {
		scanf("%d",&N);
		for(i=0;i<N;i++) {
			scanf("%d %d", &(a[i].s), &(b[i].s));
			a[i].p=i; a[i].ss=b[i].s; b[i].p=i; b[i].ss=a[i].s;
			c[i]=0;
		}
		qsort(a,N,sizeof(struct dataT),cmp);
		qsort(b,N,sizeof(struct dataT),cmp);
		tS=0; ai=0; bi=0; flag=1; k=0;
		while(1) {
			if(bi==N) break;
			if(b[bi].s<=tS) { 
				if(c[b[bi].p]==1) tS+=1;
				else tS+=2;
				c[b[bi].p]=2;
				bi++; k++;
			} else if(ai<N && a[ai].s<=tS) {
				if(c[a[ai].p]<1) {
					tS+=1;
					c[a[ai].p]=1;
					k++;
				}
				ai++;
			} else { flag=0; break; }
		}
		if(flag==0) printf("Case #%d: Too Bad\n",t+1);
		else printf("Case #%d: %d\n", t+1,k);
	}
}





