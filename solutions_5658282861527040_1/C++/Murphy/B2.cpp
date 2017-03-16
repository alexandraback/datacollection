#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

map<pair<pii, int>, LL> m;

LL s(int A, int B, int K) {
	
	//cout<<A<<' '<<B<<' '<<K<<endl;
	if (K < 0) return 0;
	if (A == 0) return B + 1;
	if (B == 0) return A + 1;
	if (A == 1) return K == 0 ? B + B / 2 +2 : B * 2 + 2;
	if (B == 1) return K == 0 ? A + A / 2 + 2 : A * 2 + 2;
	pair<pii, int> p = make_pair(make_pair(A, B), K);
	if (m.find(p) != m.end()) return m[p];
	int k = K & 1;
	int al = A / 2, ar = A - 1 - al;
	int bl = B / 2, br = B - 1 - bl;
	LL res = 0;
	if (k == 1) {
		res += s(al, bl, K / 2);
		res += s(ar, bl, K / 2);
		res += s(al, br, K / 2);
		res += s(ar, br, K / 2);
	} else {
		res += s(al, bl, K / 2);
		res += s(ar, bl, K / 2);
		res += s(al, br, K / 2);
		res += s(ar, br, K / 2 - 1);
	}
	m[p] = res;
	//cout<<A<<' '<<B<<' '<<K<<' '<<res<<endl;
	return res;
}

int main(){
	int T;
	cin>>T;
	for (int cases = 0; cases < T; cases++) {
		int A, B, K;
		cin>>A>>B>>K; 
		A--; B--; 
		K--;
		LL res = s(A, B, K);
		printf("Case #%d: %lld\n", cases + 1, res);
		
	}
	return 0;
}
