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

#define MAX_P 10000000

void prime_generate(vint &p){
//	int count = 0;
	vector<bool> table(MAX_P + 1,1);
	repp(i, 2, MAX_P){
		if (table[i]){
			p.push_back(i);
			for(int j = i + i; j <= MAX_P; j += i){
				table[j] = 0;
			}
		}
	}
}

int n;

ll pow(ll m, int i){
	if(i == 0) return 1LL;
	ll tmp = pow(m, i/2);
	if(i % 2) return tmp * tmp * m;
	else return tmp* tmp;
}

bool chk(unsigned int m, vint& primes){
	int ans[11]={};
cerr << "m: " << m << endl;
	repp(base, 2, 10){
cerr << "base: " << base << endl;
		ll mb = 0;
		rep(i, 32){
			if( (1 << i) & m ){
				mb += pow((ll)base, i);
			}
		}
		bool flag = false;
		rep(i, primes.size()){
			if (mb % primes[i] == 0 && mb != primes[i]){
				ans[base] = primes[i];
				flag = true;
				break;
			}
		}
		if ( !flag ) return 0;
	}
	if (n == 32)
		cout << static_cast<bitset<32> >(m) << " ";
	else
		cout << static_cast<bitset<16> >(m) << " ";
	repp(i, 2, 9) cout << ans[i] << " "; cout << ans[10] << endl;
	return 1;
}

void main2(){
	cout << endl;
	int j; cin >> n >> j;
	vint primes;
	prime_generate(primes);

	rep(i,10) cerr << primes[i] << " "; cerr << endl;

//	ll i = (1LL << (n-1)) + 1;
	int hoge = min (20, n-2);
	vector<unsigned int> cand(1 << hoge);
	for(unsigned int i=0; i < (1 << hoge); ++i) cand[i] = ((unsigned int)1<<(n-1)) + i + i + 1;
	random_shuffle(cand.begin(), cand.end());

	int count = 0;
//	vector<unsigned int> answers;
	rep(i, cand.size()){
		if (chk(cand[i], primes)){
			if(++count == j){
				return;
			}
/*			answers.push_back(cand[i]);
			if( answers.size() == j ){
				rep(k, j){
					c
				}
			}*/
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

