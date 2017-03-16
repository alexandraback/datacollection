#include<cstdio>
#include<algorithm>

#define N 10000005
using namespace std;

int tcc,n,m,dg;
long long ans;
int table[N];
int main(){
	int i,j,k,l,t;
	freopen("input.txt", "r", stdin);
	FILE *out= fopen("output.txt", "w");
	scanf("%d",&tcc);
	for(int tc = 1;tc<=tcc;tc++){
		memset(table,0,sizeof(table));
		ans = 0;
		scanf("%d %d",&n,&m);
		for(dg = 1, t=10; m>=t;dg++, t*=10);
		t/=10;
		for(i = n;i<=m;i++){
			int cnt = 0;
			k = i;
			for(j = 0; j < dg;j++){
				l = k/t;
				k = l + (k-t*l)*10;
				if (k<n || k>m) continue;
				//printf("%d\n", k);
				if (table[k-n+1] == 0) {
					table[k-n+1] = i;
					cnt++;
				} else if (table[k-n+1] != i) {
					cnt = 0;
					break;
				}
			}
			ans += cnt*(cnt-1)/2;
		}
		if (tc%10 == 0)
			printf("tc: %d\n", tc);
		fprintf(out, "Case #%d: %lld\n", tc, ans);
	}
	return 0;
}