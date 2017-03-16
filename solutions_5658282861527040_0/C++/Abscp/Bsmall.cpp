#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
void solve(int cas){
	printf("Case #%d: ",cas);
	int A,B,K;
	scanf("%d%d%d",&A,&B,&K);
	int ans=0;
	for(int i=0;i<A;++i)
		for(int j=0;j<B;++j)
			if((i&j)<K)
				++ans;
	printf("%d\n",ans);
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
	return 0;
}
