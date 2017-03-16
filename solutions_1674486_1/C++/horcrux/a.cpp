//author : Parag Gupta
//accepted in : 
// contest :
/* algo: 
*/

#include<cstdio>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<list>
#include<stack>
#include<queue>


using namespace std;
#define ll long long int
inline ll power(int base,int n);

#define MX 1005
#define f(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define fe(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define fm(x,y,z) for((x)=(y) ; (x)>(z) ; (x)--)
#define FLUSH fflush(stdout)
#define copy(dest,src,size) memcpy(dest,src,size)
#define NL {printf("\n");}

int a[MX][MX];
int limits[MX];
int visit[MX];
bool ans = false;
int start;
void dfs(int v){
	visit[v] = start;
	for(int i=0;i<limits[v];i++){
		if( visit[a[v][i]] == start ){
			ans=true;
			return ;
		}
		else {
			dfs( a[v][i] );
		}
	}
}
int main(){
  int t,i,j,k,n,x,neigh;
  scanf("%d",&t);
  for(int r=1;r<=t;r++){
	ans = false;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		limits[i] = x;
		for(j=0;j<x;j++){
			scanf("%d",&neigh);
			a[i][j] = neigh;
		}
	}
	   memset( visit , 0 , sizeof(visit));
	for(i=1;i<=n;i++){
	   	start = i;
	   	dfs( i );
	}
	printf("Case #%d: ",r);
	if( ans ) printf("Yes\n");
	else printf("No\n");
	


  }


  return 0;
}
/* problem:
*/
inline ll power(int base,int n){
  ll ans=1;
  while(n){
    if(n&1==1) ans*=base;
    base*=base;
    n=(n>>1);
  }
  return ans;
}

