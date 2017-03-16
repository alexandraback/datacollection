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

vector<int> RBFF[1024]; 
int BFF[1024];

int gao(int x, int forbidden = -1) {
	int r = 0;
	for (int n : RBFF[x]) {
		if (n != forbidden)
			r = max(r, 1 + gao(n));
	}
	return r;
}


int main(){
    int caseNumber;
    //scanf("%d", &caseNumber);
    cin>>caseNumber;
    REP(caseN, caseNumber) {
    	int N; cin>>N;
    	REP(i, N) {
    		RBFF[i].clear();
    	}
    	REP(i, N) {
    		int x; cin>>x; x--;
    		BFF[i] = x;
    		RBFF[x].pb(i);
    	}
    	int res = 0;
    	REP(i, N) {
    		//cycles
    		vector<bool> visited(N, false);
    		int t = i, c = 0;;
    		while (1) {
    			if (visited[t]) {
    				break;
    			}
    			visited[t] = 1;
    			c++;
    			t = BFF[t];
    		}
    		if (t == i) {
    			res = max(res, c);
    		}
    	}
    	//couples
    	int sm = 0;
    	REP(i, N) {
    		if (BFF[BFF[i]] == i && i < BFF[i]) {
    			//good cp

    			int left = gao(i, BFF[i]), right = gao(BFF[i], i);
    			sm += left + right + 2;
    		}
    	}
    	res = max(res, sm);
    	printf("Case #%d: %d\n", caseN + 1, res);
    }
    return 0;
}