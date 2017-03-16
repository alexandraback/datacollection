#include <cstdio>
#include <cstring>
#include <algorithm>
#define F first
#define S second
#define INF 999999999

using namespace std;

int casos,n,ans;
pair<int,int> vet[111];

bool solve(int mask,int mask2,int qtd,int star){
	if ( mask2 == ((1<<n)-1) ) ans=min(ans,qtd);
	else{
		bool ret=false;
		for ( int i = 0 ; i < n ; i++ ){
			if ( mask2&(1<<i) ) continue;
			if ( star >= vet[i].S ){
				if ( mask&(1<<i) ) ret|=solve(mask,(mask2|(1<<i)),qtd+1,star+1);
				else ret|=solve((mask|(1<<i)),(mask2|(1<<i)),qtd+1,star+2);
			}
		}
		if ( !ret ){
			for ( int i = 0 ; i < n ; i++ ){
				if ( mask&(1<<i) ) continue;
				if ( star >= vet[i].F ) ret|=solve((mask|(1<<i)),mask2,qtd+1,star+1);
			}
		}
		return ret;
	}
	return true;
}

int main(){
	scanf("%d",&casos);
	for( int cas = 1 ; cas <= casos ; cas++ ){
		scanf("%d",&n);
		for ( int i = 0 ; i < n ; i++ )scanf("%d%d",&vet[i].F,&vet[i].S);
		ans=INF;
		if ( solve(0,0,0,0) ) printf("Case #%d: %d\n",cas,ans);
		else printf("Case #%d: Too Bad\n",cas);
	}
	return 0;
}