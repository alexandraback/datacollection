#include<bits/stdc++.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define pritnf printf
#define N 1000514
using namespace std;
typedef long long int lnt;
typedef double dou;
int n;
int dis[N];

int c[100];
int rev(int w){
	int a=0;
	for(;w;w/=10)a=a*10+w%10;
	return a;
}
int qs,qe,q[N];;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("As.txt","w",stdout);
	dis[1]=1;
	qs=qe=0;
	q[qe++]=1;
	for(;qs!=qe;){
		int w=q[qs++];
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
	int t;RI(t);
	for(int ti=1;ti<=t;ti++){
		RI(n);
		printf("Case #%d: %d\n",ti,dis[n]);
	}
	return 0;
}

