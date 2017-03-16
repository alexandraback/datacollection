#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#define SQ(a) ((a)*(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 2147483647;
const int mod = 1000000007;


int main(){
	int TT;
	scanf("%d",&TT);
	for(int T=1;T<=TT;T++){
		printf("Case #%d: ",T);
		int b;
		ll m,x=1;
		scanf("%d%lld",&b,&m);
		for(int i=2;i<b;i++)x*=2;
		if(m>x){
			printf("IMPOSSIBLE\n");
			continue;
		}
		int k=0;
		ll r=m;

		printf("POSSIBLE\n");
		m--;
		for(int i=0;i<b;i++){
			for(int j=0;j<b-1;j++){
				if(i<j)printf("1");
				else printf("0");
			}
			if(i==0)printf("1\n");
			else {
				if(m%2==1)printf("1\n");
				else printf("0\n");
				m/=2;
			}
		}
	}
}