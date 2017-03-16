#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <numeric>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <thread>
#include <sstream>
#include <atomic>

using namespace std;


set<vector<long long> > S;


int main () {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		int N;
		map<int, int> M;
		scanf("%d", &N);
		for (int i=0; i<2*N-1; i++) {
			for (int j=0; j<N; j++) {
				int x;
				scanf("%d", &x);
				M[x]++;
			}
		}
		
		printf("Case #%d:", t);
		
		for (auto v : M) {
			if (v.second%2) printf(" %d", v.first);
		}
		printf("\n");
		
	}
	return 0;
}
