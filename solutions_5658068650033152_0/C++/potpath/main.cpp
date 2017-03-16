#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
vector<int> perm;
int n,m,b[20][20];
bool v[20][20];
inline void bfs(int i,int j){
	int id=i*m+j;
	if (perm[id]) {
		return;
	}
	b[i][j]=1;
	if (i>0&&!v[i-1][j]&&!perm[id-m]) {
		v[i-1][j]=1;
		bfs(i-1, j);
	}
	if (j>0&&!v[i][j-1]&&!perm[id-1]) {
		v[i][j-1]=1;
		bfs(i, j-1);
	}
	if (i<n-1&&!v[i+1][j]&&!perm[id+m]) {
		v[i+1][j]=1;
		bfs(i+1, j);
	}
	if (j<m-1&&!v[i][j+1]&&!perm[id+1]) {
		v[i][j+1]=1;
		bfs(i, j+1);
	}
}
inline int cnt(){
	int ret=0;
	memset(b, 0, sizeof(b));
	memset(v, 0, sizeof(v));
	for (int i=0; i<n; ++i) {
		bfs(i,0);
		if (m>1) {
			bfs(i,m-1);
		}
	}
	for (int i=0; i<m; ++i) {
		bfs(0,i);
		if (n>1) {
			bfs(n-1,i);
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (!b[i][j]) {
				++ret;
			}
		}
	}
	return ret;
}
int main()
{
	int T,k;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		scanf("%d%d%d",&n,&m,&k);
		int ans=k,nm=n*m;
		switch (k) {
			case 1 ... 4:
				break;
			default:
//				int side=ceil(sqrt(k+4))-2;
				
//				if(side<=n&&side<=m)
//					ans=min(ans,side<<2);
//				else{
					for (int i=1; i<=nm; ++i) {
						perm=vector<int>(nm,0);
						for (int j=i; j>0; --j) {
							perm[nm-j]=1;
						}
						do{
							if (cnt()>=k) {
								ans=i;
								i=nm;
								break;
							}
						}while (next_permutation(perm.begin(), perm.end()));
					}
//				}
				break;
		}
		printf("Case #%d: %d\n",iT,ans);
	}
    return 0;
}