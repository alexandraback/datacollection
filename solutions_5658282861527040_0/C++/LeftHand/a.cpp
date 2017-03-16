#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
using namespace std;

#define N  64
#define ALL(x)     x.begin(),x.end()
#define CLR(x,a)   memset(x,a,sizeof(x))
typedef pair<int,int> PI;
typedef long long 	  ll;
const int INF    = 0x3fffffff;
const int MOD    = 1000000007;
/*-----------code----------------*/

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int re,Case=1;
	scanf("%d",&re);
	while(re--){
		int A,B,K;
		scanf("%d%d%d",&A,&B,&K);
		int ans=0;
		for(int i=0;i<A;i++){
			for(int j=0;j<B;j++){
				if( (i&j)<K ) ans++;
			}
		}
		printf("Case #%d: %d\n",Case++,ans);
	}
	return 0;
}
