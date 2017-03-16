#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<sstream>
#define FOR(i,n) for(int i = 0 ; i < n ; i++)

using namespace std;

int a[15][15];


int main(){
	int t,n,m;
	scanf("%d",&t);
	bool valid =true;
	for(int cs = 1 ; cs<=t;cs++){
		scanf("%d%d",&n,&m);
		FOR(i,n)
			FOR(j,m)
				scanf("%d",&a[i][j]);
		valid = true;
		FOR(i,n){
			bool flag = true;
			FOR(j,m){
				if(a[i][j]==2) flag = false;
			}
			if(!flag){
				FOR(j,m)
					if(a[i][j]==1){
						FOR(k,n){
							//printf(" k : %d  j : %d %d \n",k,j,a[k][j]);
							if(a[k][j]==2){
								valid = false;
								goto failed;
							}
						}
					}
			}

		}

		failed:
			if(valid) printf("Case #%d: YES\n",cs);
			else printf("Case #%d: NO\n",cs);
	}
}

