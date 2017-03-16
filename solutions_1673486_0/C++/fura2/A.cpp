#include<cstdio>
#include<algorithm>

using namespace std;

void solve(){
	int a,b; scanf("%d%d",&a,&b);
	double ans=b+2; // 直ちにリセットする戦略
	double p=1,p_tmp;
	for(int n=a;n>=0;n--){ // n 文字戻してから打ち直す戦略
		ans=min(ans,(b-a+1+2*n)*p+(2*b-a+2+2*n)*(1-p));
		if(n>0){
			scanf("%lf",&p_tmp);
			p*=p_tmp;
		}
	}
	printf("%.9f\n",ans);
}

int main(){
	int T; scanf("%d ",&T);
	for(int t=1;t<=T;t++) printf("Case #%d: ",t), solve();
	return 0;
}
