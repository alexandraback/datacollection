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
#define MAX (int)10e6
#define eps 1e-7
#define pi 3.14159
#define unsigned long long ull

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;


int n,x,y,m;
vi v;
ll solve(int curr, ll steps, ll sum, int k){
	
	// printf("pos do vet : %d, passos : %lld, tam atual :%lld, tam do vet : %d\n",curr, steps, sum, v.size() - k);
	if(curr >= v.size() - k){
		// printf("retornei %lld steps\n\n",steps);
		return steps;
	}
	
	//if(v[curr] >= sum) return INF;
	
	ll menor = INF;
	 // vai pra prox bola, absorvendo essa primeira, sem adicioanr nem remover
	if(v[curr] < sum)
		menor = min(menor, solve(curr + 1, steps, sum + v[curr], k) );

	if(v[curr] >= sum && (sum-1 > 0)){
		//adicionando uma
		 // printf("adding\n");
			menor = min(menor, solve(curr, steps + 1, sum + (sum-1), k) );
			
		}
		//removendo uma
		if(k + 1 <= v.size()){
			 // printf("desadding\n");
			menor = min(menor, solve(curr, steps + 1, sum, k + 1) );

		}
	return menor;
}
int main(void){
	scanf("%d",&n);
	for(int cases = 1; cases <=n ; ++cases){
		scanf("%d%d",&x,&y);
		v.clear();
		for(int i=0; i<y; ++i){
			scanf("%d",&m);
			v.pb(m);
		}
		sort(v.begin(), v.end());
		printf("Case #%d: %d\n",cases, solve(0, 0, x, 0) );
	}
	return 0;
}