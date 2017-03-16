#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#define INF 2147483647
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;


int T;
int main(){
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){
		ll k,c,s;
		scanf("%lld%lld%lld",&k,&c,&s);
		printf("Case #%d: ",TT);
		int x=k/c+(k%c?1:0);
		if(x>s){
			printf("IMPOSSIBLE\n");
			continue;
		}
		ll p=0;
		for(int i=0;i<x;i++){
			ll q=0;
			for(int j=0;j<c;j++){
				q=q*k+(p<k?p:0);
				p++;
			}
			printf("%lld ",q+1);
		}
		printf("\n");
	}
}