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
	printf("Case #%d: ", tc);
	int n;
	scanf("%d", &n);
	if(n == 0){
		printf("INSOMNIA\n");
		return;
	}
	int chk[10] = {};
	for(int i=1;;i++){
		int x = n * i;
		while(x)chk[x%10] = 1, x /= 10;
		int ok = 1;
		for(int j=0;j<10;j++)if(chk[j] == 0)ok = 0;
		if(ok == 1){
			printf("%d\n", n*i);
			break;
		}
	}
}

int main(){
	int Tc; scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve(tc);
	}
	return 0;
}