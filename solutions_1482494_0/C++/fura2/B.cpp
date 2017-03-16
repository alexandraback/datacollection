#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n; scanf("%d",&n);
	int a[1000],b[1000];
	rep(i,n) scanf("%d%d",a+i,b+i);

	int star=0,pass[1000]={},ans=0;
	rep(_,2*n){
		bool ok=false;
		rep(i,n) if(pass[i]<2 && b[i]<=star) {
			star+=2-pass[i];
			pass[i]=2;
			ans++;
			ok=true;
		}
		if(ok) continue;

		int i_opt=-1;
		rep(i,n) if(pass[i]<1 && a[i]<=star) {
			if(i_opt==-1 || b[i_opt]<b[i]) i_opt=i;
		}
		if(i_opt!=-1){
			star++;
			pass[i_opt]=1;
			ans++;
		}
	}

	if(star<2*n) puts("Too Bad"); else printf("%d\n",ans);
}

int main(){
	int T; scanf("%d ",&T);
	for(int t=1;t<=T;t++) printf("Case #%d: ",t), solve();
	return 0;
}
