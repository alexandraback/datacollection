#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

LL powTen[15];
set<LL> conj;
LL A, B;
int res;

void dfsPalindrome(int it1, int it2, int n, LL num = 0) {
	int ini = 0;
	if(it1 == 0) ini = 1;
	if(it1 < it2) {
		FOR(i, ini, 10) {
			LL inc = i*powTen[it1] + i*powTen[it2];
			num += inc;
			dfsPalindrome(it1+1, it2-1, n, num);
			num -= inc;
		}
	}
	else{
		if(it1 == it2) {
			FOR(i, ini, 10) {
				LL inc = i*powTen[it1];
				num += inc;
				conj.insert(num);
				num -= inc;
			}
		}
		else {
			conj.insert(num);
		}
	}
}

void generator() {
	powTen[0] = 1;
	FOR(i, 1, 15)
		powTen[i] = powTen[i-1]*10LL;
	FOR(i, 1, 15)
		dfsPalindrome(0, i-1, i);
}

void solve(int caso) {
	res = 0;
	cin >> A >> B;
	set<LL>::iterator it = lower_bound(ALL(conj), sqrt(A) );
	for(; it != conj.end() ;it++) {
		LL x = (*it);
		LL multi = x*x;
		if(multi > B) break;
		if(multi >= A) {
			if(conj.find(multi) != conj.end()){
				res++;
			}
		}
	}
	cout<<"Case #"<<caso<<": "<< res << endl;
}

int main(){
	generator();
	// freopen("a.in.txt", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("a.out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	F(i, T){ solve(i+1); }
}

