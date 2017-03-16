#include<cstdio>
#include<cstring>
using namespace std;
int a[20],b[20],q[20],ans[20];
int n,m,r,k,qn;
bool flag;

void work(int dep,int now) {
	int i;
	if (dep>n) {
		q[++qn]=now;
		return;
	}
	work(dep+1,now);
	work(dep+1,now*a[dep]);
}

bool gao() {
	qn=0;
	work(1,1);
	bool t1,t2;
	int i,j;
	t1=true;
	for (i=1;i<=k;i++) {
		t2=false;
		for (j=1;j<=qn;j++)
			if (b[i]==q[j]) t2=true;
		t1&=t2;
	}
	return t1;
}

void dfs(int dep) {
	int i;
	if (flag) return;
	if (dep>n) {
		if (gao()) {
			for (i=1;i<=n;i++) ans[i]=a[i];
			flag=true;
		}
		return;
	}
	for (i=2;i<=m;i++) {
		a[dep]=i;
		dfs(dep+1);
	}
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int r1,i,testcase;
	scanf("%d",&testcase);
	printf("Case #1:\n");
	scanf("%d%d%d%d",&r,&n,&m,&k);
	for (r1=1;r1<=r;r1++) {
		for (i=1;i<=k;i++) scanf("%d",b+i);
		flag=false;
		dfs(1);
		for (i=1;i<=n;i++) printf("%d",ans[i]);
		printf("\n");
	}
}
