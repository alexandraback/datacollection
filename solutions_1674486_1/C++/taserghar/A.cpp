/*
Author		:taser ghar
Algorithm	:	
Complexity	:	
Problem		:
Comments	:balir badh amar venge gele hai , taser ghar jeno hoibe shohai
LightOJ		:)
*/
#pragma warning (disable : 4786)
#pragma comment(linker, "/STACK:16777216")

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>

#define inf 987654321
#define pi (2*acos(0.0))
#define eps 1e-7
using namespace std;
#define siz 1100

vector<int>adj[siz];
int N;
int memo[siz][siz];
int memono[siz][siz];
int cnt;
int f( int u, int k ){
		if( u == k ) 
			return 1;
	if( adj[u].size() == 0 ) return 0;
	int &res = memo[u][k];
	int &resno = memono[u][k];
	if( resno == cnt ) return res;
	resno = cnt;
	int i, v;
	 res = 0;
	for( i =0 ; i < adj[u].size(); i++){
		v = adj[u][i];
		res = res + f( v, k );
		if( res >=2 ) return res;
	}
	return res;
}
int call(){
	int i, j;
	for( i =0 ; i < N; i++){
		for( j =0 ; j < N; j++){
			if( i==j ) continue;
			cnt++;
			int res = f(i, j);
			if( res >=2 ) return res;
		}
	}
	return 0;
}
void init(){
	int i, j;
	for( i =0 ; i <N + 5; i++){
		adj[i].clear();
	}
}
int main()
{
	freopen("A-large.in","r",stdin);
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int kase, ct = 1, k;
	int i, j, u, v;
	scanf("%d", &kase);
	while(kase--){
		scanf("%d", &N);
		init();
		for( i= 0 ; i < N; i++){
			scanf("%d", &k);
			for( j = 0; j < k; j++){
				scanf("%d", &u); u--;
				adj[u].push_back(i);
			}
		}
	int res = call();	
	if( res ){
		printf("Case #%d: Yes\n", ct++);
	}
	else
		printf("Case #%d: No\n", ct++);
	}
	return 0;


}