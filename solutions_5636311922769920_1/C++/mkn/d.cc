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

ll pow(ll base, ll kata){
	if (kata == 0) return 1;
	ll tmp = pow(base, kata/2);
	if (kata % 2) return tmp * tmp * base;
	else return tmp * tmp;
}

void main2(){
	int k, c, s;
	cin >> k >> c >> s;
	cerr << k << " " << c << " " << s << endl;
	if ( c * s < k ){
		cout << "IMPOSSIBLE" << endl;
		return;
	}else{
//		vll answer(s);
		int tmp = 0;
		rep(i, s){
			bool flag = false;
			ll ans = 0;
			rep(j, c){
				ans += tmp * pow(k, j);
	cerr << tmp << " * " << k << " ^ " << j << endl;
				if (++tmp == k){
					tmp = 0;
					flag = true;
				}
			}
			if(!flag){
				cout << ans + 1 << " ";
				cerr << endl;
			}else{
				cout << ans + 1 << endl;
				break;
			}
//			answer[i] = ans;
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

