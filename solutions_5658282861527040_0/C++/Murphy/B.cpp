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


int main(){
	int T;
	cin>>T;
	for (int cases = 0; cases < T; cases++) {
		int A, B, K;
		cin>>A>>B>>K;
		int res = 0;
		REP(i, A) REP(j, B)
			res += ((i & j) < K);
		printf("Case #%d: %d\n", cases + 1, res);
		
	}
	return 0;
}
