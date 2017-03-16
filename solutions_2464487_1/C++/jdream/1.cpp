#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
int T,TT;
LL rr,t,l,r,mid;
bool check(LL n){
	double rrr=rr;
	double nn=n;
	if(2*nn*rrr+2*nn*(nn-1)+nn-t>1e-4)return 0;
	//if(2*n*(n-1)+n<=t-2*n*rr)
		return 1;
	//return 0;
}
int main(){
	freopen("aa.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&TT);
	for(T=1;T<=TT;T++){
		scanf("%I64d%I64d",&rr,&t);
		l=1;r=t;
		//check(454748);
		//check(707106781);
		while(l<r){
			mid=(l+r)/2;
			if(check(mid))
				l=mid+1;
			else r=mid;
		}
		printf("Case #%d: %I64d\n",T,l-1);
	}
}