#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

int cnt[2501];

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		memset(cnt,0,sizeof(cnt));
		int n; scanf("%d",&n);
		for(int i=1;i<=(2*n-1)*n;i++){
			int x; scanf("%d",&x);
			cnt[x]++;
		}
		printf("Case #%d:",Case);
		for(int i=1;i<=2500;i++) if(cnt[i]&1) printf(" %d",i);
		printf("\n");
	}
}
