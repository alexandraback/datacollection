#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
long long A, B, K;
long long da[65], db[65], dk[65];
long long dp[65][3][3][3];
int la, lb, lk;
bool checka(int idx, int n) {
	return idx < la && da[idx] > n;
}
bool checkb(int idx, int n) {
	return idx < lb && db[idx] > n;
}
bool checkk(int idx, int n) {
	return idx < lk && dk[idx] > n;
}
long long go(int idx, bool aok, bool bok, bool kok) {
	if(idx == -1) {
		return kok && aok && bok ? 1 : 0;
	}
	
	long long &ret = dp[idx][aok][bok][kok];
	if(ret != -1) return ret;
	ret = 0;
	//00
	int na = 0, nb = 0, nk = 0;
	ret = go(idx - 1, aok || checka(idx, na), bok || checkb(idx, nb), kok || checkk(idx, nk));
	//01
	na = 0, nb = 1, nk = 0;
	if(bok || (idx < lb && db[idx] == 1)) {
		ret += go(idx - 1, aok || checka(idx, na), bok || checkb(idx, nb), kok || checkk(idx, nk));
	}
	//10
	na = 1, nb = 0, nk = 0;
	if(aok || (idx < la && da[idx] == 1)) {
		ret += go(idx - 1, aok || checka(idx, na), bok || checkb(idx, nb), kok || checkk(idx, nk));
	}
	//11
	na = 1, nb = 1, nk = 1;
	bool cool = (aok || (idx < la && da[idx] == 1));
	cool &= (bok || (idx < lb && db[idx] == 1));
	cool &= (kok || (idx < lk && dk[idx] == 1));
	if(cool) {
		ret += go(idx - 1, aok || checka(idx, na), bok || checkb(idx, nb), kok || checkk(idx, nk));
	}
	return ret;
}
int main() {
	//freopen("b.in", "r", stdin); 
	freopen("B-small-attempt0.in", "r", stdin); freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-small-attempt1.in", "r", stdin); freopen("B-small-attempt1.out", "w", stdout);
	//freopen("B-small-attempt2.in", "r", stdin); freopen("B-small-attempt2.out", "w", stdout);
	//freopen("B-small-attempt3.in", "r", stdin); freopen("B-small-attempt3.out", "w", stdout);
	
	//freopen("B-large.in", "r", stdin); freopen("B-large.out", "w", stdout);
	
	int nT;
	cin>>nT;
	for (int t=1; t<=nT; t++) {
		memset(dp, -1, sizeof dp);
		cin>>A>>B>>K;
		la = lb = lk = -1;
		for(int i = 62; i >= 0; i--) {
			if (A & (1LL<<i)) {
				if (la == -1) la = i + 1;
				da[i] = 1;
			} else {
				da[i] = 0;
			} 
		}
		
		for(int i = 62; i >= 0; i--) {
			if (B & (1LL<<i)) {
				if (lb == -1) lb = i + 1;
				db[i] = 1;
			} else {
				db[i] = 0;
			} 
		}

		for(int i = 62; i >= 0; i--) {
			if (K & (1LL<<i)) {
				if (lk == -1) lk = i + 1;
				dk[i] = 1;
			} else {
				dk[i] = 0;
			} 
		}
		printf("Case #%d: ", t);
		cout<<go(62, false, false, false)<<endl;
	}
	return 0;
}
