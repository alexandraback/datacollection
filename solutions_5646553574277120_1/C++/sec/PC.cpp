#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int C, D, V;
long long a[105];
int main(){
	int TN, i, ca=0;
	long long res, ans;
	scanf("%d", &TN);
	while(TN--){
		scanf("%d%d%d", &C, &D, &V);	
		for(i=0;i<D;i++){
			scanf("%lld", &a[i]);
		}
		sort(a, a+D);
		res=0;ans=0;
		if(a[0]!=1){
			ans++;
		}
		res=C;
		for(i=0;i<D && res<(long long)V;i++){
			if(a[i]==1)continue;
			if(a[i]<=res+1){
				res+=a[i]*C;
			}
			else{
				// printf("res %lld ans %lld a[%d]=%lld\n", res, ans, i, a[i]);
				res+=(res+1)*C;
				// res+=a[i]*C;
				i--;
				ans++;
			}
		}

		// printf("res %lld\n", res);
		while(res<(long long)V){
			res+=(res+1)*C;
			ans++;
		}
		// printf("res %lld\n", res);
		printf("Case #%d: %lld\n", ++ca, ans);
	}
	return 0;
}