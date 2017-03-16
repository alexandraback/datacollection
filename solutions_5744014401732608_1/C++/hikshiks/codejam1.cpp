#include<bits/stdc++.h>

using namespace std;

#define pid pair<int, char>
#define mp make_pair
#define fi first
#define se second
#define ll long long

int main(){
	freopen("out.txt","w",stdout);
	int t;
	int tc = 0;
	scanf("%d",&t);
	ll n,m;
	
	ll ar[55];
	ar[0] = 1;
	ll tmp = 1;
	for(int i = 1; i < 50; i++){
		ar[i] = tmp;
		tmp*=2LL;
	}
	
	while(t--){
		scanf("%lld %lld",&n ,&m);
		printf("Case #%d: ",++tc);
		
		ll tmp = 1;
		for(int i = 0; i < n-2; i++){
			tmp*=2LL;
		}
		if(m>tmp){
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		
		int a[55][55];
		memset(a, 0, sizeof a);
		
		for(int i = 1; i < n; i++){
			for(int j = i+1; j < n; j++){
				a[i][j] = 1;
			}
		}
		
		for(int i = n-2; i>=0; i--){
		//	cout<<i<<' '<<ar[i]<<endl;
			if(m>=ar[i]){
				m-=ar[i];
				a[0][n-i-1] = 1;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				printf("%d",a[i][j]);
			}
			printf("\n");
		}
	}
	
}
