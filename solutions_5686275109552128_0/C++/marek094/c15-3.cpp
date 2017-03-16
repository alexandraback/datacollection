#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define ST first
#define ND second
#define MP(a,b) make_pair(a,b)
#define FOR(i,m,n) for(int i=int(m);i<int(n);++i)
#define REP(i,n) for(int i=0;i<int(n);++i)
#define DREP(i,n) for(int i=int(n)-1;i>=0;--i)

using namespace std;

int v[1111];
void test(int t) {
	int N; cin >> N;
	vector<long long> h(1111,0);
	int top = 0;
	REP (i, N) {
		cin >> v[i];
		h[ v[i] ]++;
		if (v[top]<v[i]) top = i;
	}
	long long min = v[top];
	long long val = 0;
	DREP (i, v[top]+1) {
		if (h[i]==0 || i<1) continue;	
		if (val + (long long)i < min) min = val + (long long)i;
		
		val += h[i];
		h[ i / 2 ] += h[i];
		h[ i / 2 + i % 2 ] += h[i];
	}
	cout << "Case #" << t+1 << ": " << min << endl;
}


int main() {
	int T; cin >> T;
	
	REP (i, T) 
		test(i);

	return 0;
}

















