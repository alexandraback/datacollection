#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define rep(i,n) fr(i,0,n)
#define N 1000

int col[N], lin[N], ma[N][N];
int n, m;

int main(){
	int t;
	scanf("%d", &t);
	rep(cas, t){
		scanf("%d%d", &n, &m);
		rep(i, n) lin[i] = -1;
		rep(j, m) col[j] = -1;
		
		rep(i, n) rep(j, m){
			int ele;
			scanf("%d", &ele);
			lin[i] = max(lin[i], ele);
			col[j] = max(col[j], ele);
			ma[i][j] = ele;
		}
		bool dm = false;
		rep(i, n) rep(j, m){
			if(ma[i][j] < col[j] && ma[i][j] < lin[i]){
				dm = true;
				goto sai;
			}
		}
		sai:
		printf("Case #%d: ", cas+1);
		if(dm) printf("NO\n");
		else printf("YES\n");
		
	}
}
