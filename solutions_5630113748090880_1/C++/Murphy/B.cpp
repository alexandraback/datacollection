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
    int caseNumber;
    //scanf("%d", &caseNumber);
    cin>>caseNumber;
    REP(caseN, caseNumber) {
    	map<int, int> M;
    	int N; cin>>N;
    	REP(i, 2 * N - 1) REP(j, N) {
    		int x; cin>>x;
    		M[x]++;
    	}
    	vector<int> V;
    	for (auto it : M) {
    		if (it.second & 1) {
    			V.pb(it.first);
    		}
    	}
    	assert(V.size() == N);
    	sort(V.begin(), V.end());
    	printf("Case #%d:", caseN + 1);
    	for (auto it : V) {
    		printf(" %d", it);
    	}
    	puts("");
    }
    return 0;
}