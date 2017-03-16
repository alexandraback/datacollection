#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define MaxA 10
using namespace std;
int T,A,B,j;
double p[MaxA],ans[MaxA],num[MaxA],Ans;
void cmin(double &a,double b){
	if (a>b) a=b;
}
void dfs(int dep,double P,bool t){
	if (dep>1){
		if (t) ans[dep-1]+=(A+B-dep*2+3)*P;
		else ans[dep-1]+=(A+B-dep*2+3+B+1)*P;
		if (dep==A+1) return ;
	}
	dfs(dep+1,P*p[dep],t);
	dfs(dep+1,P*(1-p[dep]),false);
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (int i=1;i<=T;i++){
		scanf("%d%d",&A,&B);
		memset(ans,0,sizeof ans);
		memset(num,0,sizeof num);
		for (j=1;j<=A;j++)
			scanf("%lf",&p[j]);
		Ans=B+2;
		dfs(1,1,1);
		printf("Case #%d: ",i);
		for (int i=1;i<=A;i++)
			cmin(Ans,ans[i]);
		printf("%.6lf\n",Ans);
	}
	return 0;
}
