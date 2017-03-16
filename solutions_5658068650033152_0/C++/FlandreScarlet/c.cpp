#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int n,m,p,ans;

void gao(int x,int y) {
	int i,now,t;
	now=2*(x+y);
	if (now>ans) return;
	t=x*y+now;
	ans=min(ans,now+max(0,p-t));
	if (t>=p) return;
	for (i=1;x+2*(i+1)<=n && y+2*(i+1)<=m;i++) {
		now=2*(x+y)+4*i;
		if (now>ans) return;
		t+=now;
		ans=min(ans,now+max(0,p-t));
		if (t>=p) return;
	}
}

int main() {
	int i,j,te,tt;
	scanf("%d",&tt);
	for (te=1;te<=tt;te++) {
		scanf("%d%d%d",&n,&m,&p);
		ans=p;
		for (i=1;i<=n-2;i++)
			for (j=1;j<=m-2;j++) gao(i,j);
		printf("Case #%d: %d\n",te,ans);
	} 
}
