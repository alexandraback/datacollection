#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

void solve(int tc){
	printf("Case #%d:\n", tc);
	int n, l; scanf("%d%d", &n, &l);
	for(int i=0;i<l;i++){
		char ch[35] = {};
		for(int j=0;j<n;j++)ch[j] = '0';
		ch[0] = '1';
		ch[n-1] = '1';
		ch[n/2] = ch[n/2-1] = '1';
		int x = i, w = n/2-2;
		while(x){
			ch[w] = ch[w+n/2] = x % 2 + '0';
			w--;
			x /= 2;
		}
		printf("%s ", ch);
		for(int j=2;j<=10;j++){
			ll x = pow(j, n/2) + 1e-9;
			printf("%lld ", x+1);
		}
		puts("");
	}
}

int main(){
	int Tc; scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve(tc);
	}
	return 0;
}