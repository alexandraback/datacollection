#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=110000;
int n,tt,Run;
struct Tcxx{
	int a,b,u;
}A[maxn];

namespace Ninit{
	inline bool cmp(const Tcxx &a,const Tcxx &b){
		return a.b>b.b;
	}
	void init(){
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%d%d",&A[i].a,&A[i].b),A[i].u=0;
		}
		sort(A+1,A+n+1,cmp);
	}
}


namespace Nsolve{
	int ans,val;
	void solve(){
		int i;
		for(ans=val=0;;){
			for(i=1;i<=n;++i)if(A[i].u!=2 && A[i].b<=val){
				A[i].u?val+=1:val+=2;A[i].u=2;
				++ans;goto Lab1;
			}
			for(i=1;i<=n;++i)if(A[i].u==0 && A[i].a<=val){
				val+=1;A[i].u=1;
				++ans;goto Lab1;
			}
			break;Lab1:;
		}
		printf("Case #%d: ",Run);
		if(val!=2*n)printf("Too Bad\n");else printf("%d\n",ans);
	}
}

int main(){
	freopen("love.in","r",stdin);freopen("love.out","w",stdout);
	for(cin>>tt,Run=1;tt;++Run,--tt){
		Ninit::init();
		Nsolve::solve();
	}
	fclose(stdout);
	return 0;
}
