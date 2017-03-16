#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=110000;
int A,B,tt,Run;
double a[maxn];

namespace Ninit{
	void init(){
		cin>>A>>B;
		for(int i=1;i<=A;++i)scanf("%lf",a+i);
	}
}


namespace Nsolve{
	long double ans;
	void case1(){
		long double F[2];
		F[0]=0,F[1]=1;
		for(int i=1;i<=A;++i)
			F[0]+=F[1]*(1-a[i]),F[1]*=a[i];
		ans=min(ans,F[0]*(B-A+2+B)+F[1]*(B-A+1));
	}
	void case2(){
		long double F[2];
		F[0]=0,F[1]=1;
		for(int i=1,x;i<A;++i){
			F[0]+=F[1]*(1-a[i]),F[1]*=a[i];
			x=A-i;
			ans=min(ans,F[0]*(x+x+B-A+2+B)+F[1]*(x+x+B-A+1));
			//cerr<<F[0]*(x+x+B-A+2+B)+F[1]*(x+x+B-A+1)<<endl;
		}
	}
	void case3(){
		ans=min(ans,(long double)B+2);
	}
	void solve(){
		ans=1e20;
		case1(),case2(),case3();
		printf("Case #%d: %.6lf\n",Run,(double)ans);
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
