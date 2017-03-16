#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>

using namespace std;

#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

int tabla[100][100];

int main() {
	int n, N, M;

	cin>>n;
	for (int caso = 1; caso <= n; caso++) {
		cin>>N>>M;
		
		vector<int> maxF(N, 0), maxS(M, 0);
		for (int i=0; i<N; i++) for (int j=0;j<M;j++) {
			cin>>tabla[i][j];
			maxF[i] = max(maxF[i], tabla[i][j]);
			maxS[j] = max(maxS[j], tabla[i][j]);
		}
		
		bool ok = true;
		for (int i=0;i<N;i++) for (int j=0;j<M;j++) if (tabla[i][j]<min(maxF[i], maxS[j])) ok=false;
		
		cout << "Case #" << caso << ": " << (ok ? "YES" : "NO" )<< endl; 
	}
	return 0;
}
