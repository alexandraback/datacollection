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
    	int N;
    	int best = 0;
    	cin>>N;
    	vector<int> V(N, 0);
    	REP(i, N) {
    		cin>>V[i];
    		best = max(best, V[i]);
    	}
    	for (int i = 1; i < best; i++) {
    		int r = i;
    		REP(j, N) {
    			int c = V[j];
    			int x = c / i;
    			if (i * x != c) {
    				x++;
    			}
    			// cout<<j<<' '<<x<<endl;
    			r += x - 1;
    		}
    		// cout<<i<<' '<<r<<endl;
    		best = min(best, r);
    	}
    	printf("Case #%d: %d\n", caseN + 1, best);
    }
    return 0;
}