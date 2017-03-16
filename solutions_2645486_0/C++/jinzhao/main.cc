#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct TreeNode {
	int l,r,ls,rs,v;
};

int e,r,n,p;
int a[10010];
int b[10010];
TreeNode c[300000];

void maketree(int l,int r) {
	int h=p;
	c[p].l=l;
	c[p].r=r;
	p++;
	if (l!=r) {
		int t=(l+r)/2;
		c[h].ls=p;
		maketree(l,t);
		c[h].rs=p;
		maketree(t+1,r);
		c[h].v=max(c[c[h].ls].v,c[c[h].rs].v);
	} else {
		c[h].ls=0;
		c[h].rs=0;
		c[h].v=a[l];
	}
	return;
}

int maxv(int i,int l,int r) {
	//printf("%d %d %d\n",l,r,i);
	//getchar();
	if (l>r) return -1;
	if ((c[i].l==l)&&(c[i].r==r)) return c[i].v;
	int t=(c[i].l+c[i].r)/2;
	if (t>=r) return maxv(c[i].ls,l,r);
	if (t<l) return maxv(c[i].rs,l,r);
	return max(maxv(c[i].ls,l,t),maxv(c[i].rs,t+1,r));
}

int find(int l,int r,int k) {
	if (l==r) return l;
	int t=(l+r)/2;
	if (maxv(1,l,t)>k) return find(l,t,k);
	else return find(t+1,r,k);
}

int main() {
	int t,tt,i,j,now,k;
	long long ans;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d%d%d",&e,&r,&n);
		for (i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		memset(c,0,sizeof(c));
		now=e;
		ans=0;
		p=1;
		maketree(0,n-1);
		//for (i=1;i<p;i++) {
			//printf("%d %d %d %d %d\n",c[i].l,c[i].r,c[i].ls,c[i].rs,c[i].v);
		//}
		//printf("%d\n",maxv(1,1,2));
		for (i=n-1;i>=0;i--) {
			///*
			if (maxv(1,i+1,n-1)>a[i])
				b[i]=find(i+1,n-1,a[i]);
			else
				b[i]=e+n;
			//printf("%d %d\n",i,b[i]);
			//*/
			/*
			b[i]=e+n;
			j=i+1;
			while (j<n) {
				if (a[j]>a[i]) {
					b[i]=j;
					j=n;
				}
				j++;
			}
			*/
		}
		for (i=0;i<n;i++) {
			//printf("%d ",b[i]);
			k=max(0ll,e-(long long)(b[i]-i)*r);
			if (now>k) {
				ans+=(long long)(now-k)*a[i];
				now=k+r;
			} else now+=r;
		}
		printf("Case #%d: %lld\n",tt,ans);
	}
	return 0;
}
