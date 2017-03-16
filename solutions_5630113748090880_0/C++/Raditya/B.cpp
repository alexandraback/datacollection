#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N = 2501;
bool ar[N];
int main(){
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; ++tc){
		int n;
		scanf("%d", &n);
		memset(ar,0,sizeof ar);
		for(int i=1;i<(n<<1);++i){
			for(int j=0;j<n;j++){
				int s;
				scanf("%d", &s);
				ar[s] ^=1;
			}
		}
		printf("Case #%d:", tc);
		for(int i=1;i<N;++i){
			if(ar[i]) printf(" %d", i);
		}
		puts("");
	}
	return 0;
}