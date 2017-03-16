#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int n;
LL m;
int ans[60][60];

int main(){
	int T;
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		cin >> n>> m;
		printf("Case #%d: ",ti);
		LL k=1LL<<n-2;
		memset(ans,0,sizeof(ans));
		if (k<m) puts("IMPOSSIBLE");
			else{
				puts("POSSIBLE");
				for (int i=1;i<n;i++){
					for (int j=i+1;j<n;j++)
						ans[i][j]=1;
				}
				int now=2;
				m--;
				ans[1][n]=1;
				while (m){
					if (m&1) ans[now][n]=1;
					m/=2;
					now++;
				}
				for (int i=1;i<=n;i++){
					for (int j=1;j<=n;j++) printf("%d",ans[i][j]);
					printf("\n");
				}

			}
	}
	return 0;
}