#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdlib>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#define MAX 100005
#define all(x) x.begin(),x.end()


typedef long long Int;
using namespace std;
//vector<int> g[MAX];
//int usd[MAX];

void solve(){
	int A, B, res = 0,K;

	scanf("%d %d%d",&A,&B,&K);
	for( int i = 0; i < A; i++){
		for( int j = 0; j < B ;j++){
			if ( (i&j) < K ){
				res++;
			}
		}
	}
	printf("%d\n",res);
}

int main(){

	int runs;
	scanf("%d",&runs);
	for( int r = 1; r <= runs; r++){
		printf("Case #%d: ",r);
		solve();
	}

	return 0;
}
