#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

int ans;

bool Found(long long p, long long q, int i){
	//cout << i << ": " << p << " " << q << endl;
	if(i>40) return false;
	if(p==0 || p==q){
		if(p==q) ans = min(i, ans);
		return true;
	}
	long long m = min(p, q-p);
	long long l = p - m;
	long long r = p + m;
	if(Found(l, q, i+1) && Found(r, q, i+1))
		return true;
	return false;
}

void Solve()
{
	ans = 41;
	int px, qx; scanf("%d/%d", &px, &qx);
	long long p=px, q=qx;
	if(Found(p, q, 0)) cout << ans;
	else cout << "impossible";
}

void Solve2()
{
	int px, qx; scanf("%d/%d", &px, &qx);
	long long p=px, q=qx;
	for(int i = 0; i <= 40; ++i){
		if(p==q){
			cout << i;
			return;
		}
		long long l = p;
		long long r = q-p;
		long long m = min(l, r);
		p += m;
		//p *= 2;
	}
	cout << "impossible";
}

int main()
{
	int T; cin >> T;
	FOR(t, T){
		cout << "Case #" << t+1 << ": "; Solve(); cout << endl;
	}
	return 0;
}
