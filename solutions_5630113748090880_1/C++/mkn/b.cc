#include <bits/stdc++.h>
/*
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
*/
using namespace std;

typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;

#define mp make_pair
#define pb push_back

#define fi first
#define se second

#define repp(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define rep(i,n) repp(i,0,(n)-1)

void main2(){
	int n; cin >> n;
	vector<int> a(3000, 0);
	rep(i, n * (2 * n - 1)){
		int b;
		scanf("%d", &b);
		a[b]++;
	}
	vint ans;
	rep(i, 2501){
		if(a[i] % 2) ans.pb(i);
	}
	rep(i, n - 1) cout << ans[i] << " ";
	cout << ans[n-1] << endl;
}

int main(){
	int casenum; cin >> casenum;
	rep(casenow, casenum){
		printf("Case #%d: ", casenow+1);
		main2();
	}
	return 0;
}

