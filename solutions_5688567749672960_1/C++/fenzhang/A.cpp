#include<bits/stdc++.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define pritnf printf
#define N 100
using namespace std;
typedef long long int lnt;
typedef double dou;
int dis[N];
lnt dp[N];

lnt p10[100];

int c[100];
lnt rev(lnt w){
	lnt a=0;
	for(;w;w/=10)a=a*10+w%10;
	return a;
}
lnt rev2(lnt w,int l){
	lnt a=0;
	for(int i=0;i<l;i++,w/=10)a=a*10+w%10;
	return a;
}
int len(lnt w){
	int a=0;
	for(;w>=10;w/=10)a++;
	return a;
}
lnt sol(lnt n){
	if(n<=10)return n;
	int l=len(n);
	lnt ans=dp[l];
	lnt tn=n;
	for(int i=0;i<=l;i++){
		c[i]=n%10;
		n/=10;
	}
	lnt t1=0,t2=0,t3=0;
	for(int i=l/2+1;i<=l;i++){
		t1=t1*10+c[i];
		t3=t3+p10[i-(l/2+1)]*c[i];
	}
	for(int i=l/2;i>=0;i--){
		t2=t2*10+c[i];
	}
	if(t1==1){
		return ans+t2;
	}
	/////////////////
	if(t2>=1){
		return ans+t1+1+(t2-1);
	}
	t3--;
	t3=rev2(t3,(l+1)/2);
	return ans+t3+(t3!=1)+(p10[l/2+1]-1);
}
int qs,qe,q[N];
int main(){
	p10[0]=1;
	for(int i=1;i<20;i++)p10[i]=p10[i-1]*10;
	freopen("A-large.in","r",stdin);
	freopen("Al.txt","w",stdout);
	dis[1]=1;
	qs=qe=0;
	q[qe++]=1;
	for(;qs!=qe;){
		int w=q[qs++];
		//if(p10[len(w)]==w)printf("%d: %d %d\n",dis[w],w,dis[w]-dis[w/10]);
		int t=w+1;
		if(t<N&&dis[t]==0){
			dis[t]=dis[w]+1;
			q[qe++]=t;
		}
		t=rev(w);
		if(t<N&&dis[t]==0){
			dis[t]=dis[w]+1;
			q[qe++]=t;
		}
	}
	dp[0]=1;
	dp[1]=10;
	for(int i=2;i<15;i++){
		dp[i]=dp[i-1]+p10[(i+1)/2]+p10[(i+1)/2-(i%2)]-1;
		//printf("%I64d: %I64d\n",dp[i],p10[i]);
	}
	int t;RI(t);
	lnt n;
	for(int ti=1;ti<=t;ti++){
		//assert(dis[ti]==sol(ti));
		//if(dis[ti]!=sol(ti)){
		//	printf("Case #%d: %d\n",ti,dis[ti]);
		//	printf("Case #%d: %I64d\n",ti,sol(ti));
		//	break;
		//}
		RI64(n);
		//printf("Case #%d: %d\n",ti,dis[n]);
		printf("Case #%d: %I64d\n",ti,sol(n));
	}
	return 0;
}

