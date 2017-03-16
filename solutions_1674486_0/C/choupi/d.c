#include <stdio.h>

int M[1000][1000];
int v[1000];
int n;

int travel(int p)
{
	int i;
//printf("v[%d]=%d\n",p,v[p]);
	if(v[p]) return 1;
	v[p]=1;
	for(i=0;i<n;i++) {
//		printf("%d->%d (%d)\n", p,i,M[p][i]);
		if(M[p][i]>0 && travel(i)) return 1;
	}
	return 0;
}

int main()
{
	int t,T,i,j,m,x,y,fl;
	int P[1000];
	scanf("%d",&T);
	for(t=0;t<T;t++) {
		scanf("%d", &n);
		for(i=0;i<n;i++) for(j=0;j<n;j++) M[i][j]=0;
		fl=0;
		for(i=0;i<n;i++) {
			scanf("%d",&m); 
			if(m>1) fl=1;
			for(j=0;j<m;j++) {
				scanf("%d", &x);
				M[i][x-1]=1;
			}
		}
		if(fl==0) { printf("Case #%d: No\n", t+1); continue;}
		fl=0;
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) v[j]=0;
			if(travel(i)) { fl=1; break;}
		}
		if(fl==0) { printf("Case #%d: No\n", t+1); }
		else printf("Case #%d: Yes\n", t+1);
	}
}

