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

void digits(ll now, bool *dig, int *num){
	do{
		int a = now % 10;
		if (!dig[a]){
			dig[a] = true;
			(*num)++;
		}
		now /= 10;
	}while(now);
}

void main2(){
	int n; cin >> n;
	if ( n == 0 ){
		cout << "INSOMNIA" << endl;
		return;
	}
	bool dig[10] = {};
	int dignum = 0;
	ll now = 0;
	while(1){
		now += n;
		cerr << "now: " <<  now << endl;
		digits(now, dig, &dignum);
		rep(i,10) cerr << dig[i] << " "; 
		cerr << "dignum: " << dignum << endl;
		if (dignum == 10){
			cout << now << endl;
			break;
		}
	}
}

int main(){
	int casenum; cin >> casenum;
	rep(casenow, casenum){
		printf("Case #%d: ", casenow+1);
		main2();
	}
	return 0;
}

