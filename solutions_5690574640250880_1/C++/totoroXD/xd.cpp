/*
 * totoroXD
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int INF = 1011110000, MOD=1000000000;
const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
const double EPS = 1e-6;

int n, m, k, kase=1, kk;
char mp[55][55];
bool input(){
	cin>>n>>m>>k;
	kk=k;
	return 1;
}
void solve(){
	memset(mp,0,sizeof(mp));
	for(int i=0; i<n; i++)
		fill(mp[i], mp[i]+m, '.');
	mp[n-1][m-1]='c';
	//printf("%d %d\n",n,m);
	if(k==n*m-1){
		k=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(!(i==n-1 && j==m-1)) mp[i][j]='*';
	}else if(n==1){
		if(k <= m-1){
			for(int i=0; i<k; i++) mp[0][i]='*';
			k=0;
		}
	}else if(m==1){
		if(k <= n-1){
			for(int i=0; i<k; i++) mp[i][0]='*';
			k=0;
		}
	}else if(n==2){
		if(k%2==0 && k<=n*m-4){
			for(int j=0; j<k/2; j++)
				mp[0][j] = mp[1][j] = '*';
			k=0;
		}
	}else if(m==2){
		if(k%2==0 & k<=n*m-4){
			for(int i=0; i<k/2; i++)
				mp[i][0] = mp[i][1] = '*';
			k=0;
		}
	}else{
		for(int i=0; i<n-3 && 0<k; i++){
			for(int j=0; j<m && 0<k; j++){
				if(mp[i][j]=='*')continue;
				if(m-2<=j){
					if(1<k){
						mp[i][j] = mp[i][j+1]='*';
						k-=2;
					}else{
						mp[i+1][0]='*';
						k--;
					}
				}else{
					mp[i][j]='*';
					k--;
				}
			}
		}
		//for(int i=0; i<n; i++)printf("%s\n",mp[i]);

		for(int j=0; j<m-3 && 0<k; j++){
			for(int i=n-3; i<n && 0<k; i++){
				if(mp[i][j]=='*')continue;
				if(n-2<=i){
					if(1<k){
						mp[i][j] = mp[i+1][j] = '*';
						k-=2;
					}else{
						mp[n-3][j+1]='*';
						k--;
					}
				}else{
					mp[i][j]='*';
					k--;
				}
			}
		}
		//for(int i=0; i<n; i++)printf("%s\n",mp[i]);

		if(k==1){
			mp[n-3][m-3]='*';
			k=0;
		}else if(k==3){
			mp[n-3][m-3]=mp[n-3][m-2]=mp[n-3][m-1]='*';
			k=0;
		}else if(k==5){
			mp[n-3][m-3]=mp[n-3][m-2]=mp[n-3][m-1]=mp[n-2][m-3]=mp[n-1][m-3]='*';
			k=0;
		}
	}
	printf("Case #%d:\n",kase++);
	if(0<k){
		//printf("%d %d %d ",n,m,kk);
		printf("Impossible\n");

	}else{
		for(int i=0; i<n; i++){
			printf("%s\n",mp[i]);
		}
	}
}
void pre(){
}
int main(){
	pre();
    int zz=1;
    cin>>zz;
    while(zz--){
    	input();
    	solve();
    }
    return 0;
}

/*

100
5 5 23
3 1 1
2 2 1
4 7 3
10 10 82
10 10 93
10 10 94
10 10 96
10 10 97
10 10 99
5 5 7
5 5 8
1 5 2
5 1 3
2 4 3
2 4 4
4 2 5
4 2 7

*/

