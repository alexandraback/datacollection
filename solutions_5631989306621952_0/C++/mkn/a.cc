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

bool chk(string mae, string ato){
	rep(i, mae.length()){
		if(mae[i] != ato[i]) return (mae[i] > ato[i]);
	}
	return false;
}

void main2(){
	string S;
	cin >> S;
	int len = S.length();
	string now= "";
	now += S[0];
	repp(i, 1, len-1){
		string mae = S[i] + now;
		string ato = now + S[i];
		if ( chk(mae, ato) ){
			now = mae;
		}else{
			now = ato;
		}
	}
	cout << now << endl;
}

int main(){
	int casenum; cin >> casenum;
	rep(casenow, casenum){
		printf("Case #%d: ", casenow+1);
		main2();
	}
	return 0;
}

