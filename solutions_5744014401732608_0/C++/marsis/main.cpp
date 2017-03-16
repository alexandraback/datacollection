#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
ll m;
ll A[100];
int adj[100][100];

int main()
{
    int T,z(1);
    freopen("/home/mars/Documents/in.in","r",stdin);
    freopen("/home/mars/Documents/B.out","w",stdout);
    cin >> T;
    while(T--){
		cin >> n >> m;
		memset(adj,0,sizeof adj);
		A[n-1] = 1;
		for(int i=n-2;i>=0;i--){
			A[i] = 0;
			for(int j=i+1;j<n;j++){
				if(m>=A[i] + A[j]){
					A[i] += A[j];
					adj[i][j] = 1;
				}
			}
		}
		printf("Case #%d: ",z++);
		if(A[0] == m){
			printf("POSSIBLE\n");
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					printf("%d",adj[i][j]);
				}
				printf("\n");
			}
		}else printf("IMPOSSIBLE\n");
    }
    return 0;
}
