#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define mod 10
#define B 33
#define MAX (int)10e2 + 10
#define eps 1e-7
#define pi 3.14159
#define unsigned long long ull

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;


int n,x,y,m;
vi v;
ll dp[MAX][1010];

ll solve(int curr, ll steps, ll sum, int k, int adding, int desading){
	
	// printf(" %d, %lld,  %d\n",curr,steps,idid);
	// printf("estado:(%d,%d) steps %lld, meu tam : %lld, tam total : %d\n",curr,adding*200 + desading,steps,sum, v.size() - k);
	if(curr >= v.size() - k){
		// printf("retornei %lld steps\n\n",steps);
		return steps;
	}
	ll & ret = dp[curr][ adding*200 + desading ];
	if(ret != -1){
		
	// printf("retornando\n");
		return ret;
	}
	ret = INF;
	 // vai pra prox bola, absorvendo essa primeira, sem adicioanr nem remover
	if(v[curr] < sum)
		ret = min(ret, solve(curr + 1, steps, sum + v[curr], k, adding, desading) );

	if(v[curr] >= sum && (sum-1 > 0)){
		// adicionando uma
		 // printf("adding\n");
			ret = min(ret, solve(curr, steps + 1, sum + (sum-1), k, adding + 1, desading) );
			
	}
	//removendo uma
	if(k + 1 <= v.size()){
		 // printf("desadding\n");
		ret = min(ret, solve(curr, steps + 1, sum, k + 1, adding, desading + 1) );

	}
	return  ret;
}
int main(void){
	scanf("%d",&n);
	for(int cases = 1; cases <=n ; ++cases){
		memset(dp,-1, sizeof dp);
		scanf("%d%d",&x,&y);
		v.clear();
		for(int i=0; i<y; ++i){
			scanf("%d",&m);
			v.pb(m);
		}
		sort(v.begin(), v.end());
		printf("Case #%d: %d\n",cases, solve(0, 0, x, 0, 0,0) );
	}
	return 0;
}