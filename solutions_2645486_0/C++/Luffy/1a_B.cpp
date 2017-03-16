#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int values[10000];

int runrun(int* values, int e, int r, int s, int n, int nowE) { // s~n
	int useEnergy;
	if (s == n) return values[s]*nowE;
	int maxE = 0;
	int getE;
	for (useEnergy = 0; useEnergy <= nowE; useEnergy++) {
		int nextE = nowE - useEnergy + r;
		if (nextE > e) nextE = e;
		getE = useEnergy*values[s] + runrun(values, e, r, s+1, n, nextE);
		if (getE > maxE) maxE = getE;
	}
	return maxE;
}

int main () {
	
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin >> T;
    int E, R, N;
    for (int t = 1; t <= T; t++) {
    	cin >> E >> R >> N;
    	if (R > E) R = E;
    	for (int i=0; i<N; i++) {
    		cin >> values[i];
    	}
    	int ans = runrun(values, E, R, 0, N-1, E);
    	printf("Case #%d: %d\n", t, ans);
    }
    
    return 0;
}
