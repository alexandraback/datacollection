#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
int T,cas=0,a[102];
int A,N,ans,ans2;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&A,&N);
		ans=0;ans2=N;
		for(int i=1;i<=N;++i) scanf("%d",&a[i]);
		sort(a+1,a+1+N);
		for(int i=1;i<=N;++i){
			ans2=min(ans2,ans+N-i+1);
			int cnt=0;
			while(A<=a[i]){
				A+=A-1;cnt++;
				if(cnt>=N-i+1) break;
			}
			A+=a[i];
			if(cnt<N-i+1)ans+=cnt;
			else{
				ans+=N-i+1;
				break;
			}
		}	
		ans=min(ans,ans2);
		printf("Case #%d: ",++cas);
		printf("%d\n",ans);
	}
	return 0;
}
