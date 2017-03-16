#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef pair<int,int> P;
typedef long long ll;
#define mp make_pair
#define fi first
#define sc second

int main(){
	int t; scanf("%d",&t);
	for(int q=1;q<=t;q++){
		printf("Case #%d:",q);
		int k,c; ll s;
		scanf("%d%d%lld",&k,&c,&s);
		if(k == 1){
			puts(" 1");
		}
		else if(c == 1){
			if(s < k){
				puts(" IMPOSSIBLE");
			}
			else{
				for(int i=1;i<=k;i++){
					printf(" %d",i);
				}
				puts("");
			}
		}
		else{
			if(s < k-1){
				puts(" IMPOSSIBLE");
			}
			else{
				for(int i=2;i<=k;i++){
					printf(" %d",i);
				}
				puts("");
			}
		}
	}
}