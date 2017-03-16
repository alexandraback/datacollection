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
	string inp; 
	cin >> inp;
	int l = inp.length();
	inp += '+';
//	char ch = inp[0];
	int ans = 0;
	rep(i, l){
		ans += (inp[i] != inp[i+1]);
	}
	cout << ans << endl;
}

int main(){
	int casenum; cin >> casenum;
	rep(casenow, casenum){
		printf("Case #%d: ", casenow+1);
		main2();
	}
	return 0;
}

