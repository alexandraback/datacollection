#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<sstream>
#define FOR(i,n) for(int i = 0 ; i < n ; i++)

using namespace std;

int a[105][105];


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
			FOR(j,m){
				// check entire row and entire col or this element
				bool row= true, col = true;
				FOR(k,n){
					if(a[k][j] > a[i][j])
						row = false;
				}
				FOR(k,m){
					if(a[i][k] > a[i][j])
						col = false;
				}
				if(!row and !col){
					valid = false;
					goto failed;
				}
			}
		}

		failed:
			if(valid) printf("Case #%d: YES\n",cs);
			else printf("Case #%d: NO\n",cs);
	}
}

