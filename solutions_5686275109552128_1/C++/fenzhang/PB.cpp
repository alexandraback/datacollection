#include<bits/stdc++.h>
using namespace std;
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define pritnf printf
#define N 1514
using namespace std;
typedef long long int lnt;
typedef double dou;
int n;
int p[N];
int test(int b){
	int ans=0;
	for(int i=0;i<n;i++){
		if(p[i]>b){
			ans+=p[i]/b-(p[i]%b==0);
		}
	}
	return ans+b;
}

void sol(int uuu){
	RI(n);
	for(int i=0;i<n;i++){
		RI(p[i]);
	}
	///////
	sort(p,p+n);
	int ans=p[n-1];
	for(int i=1;i<=1000;i++){
		ans=min(ans,test(i));
	}
	printf("Case #%d: %d\n",uuu,ans);
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("Bout_l.txt","w",stdout);
	int t;RI(t);
	for(int i=1;i<=t;i++)sol(i);
	return 0;
}

