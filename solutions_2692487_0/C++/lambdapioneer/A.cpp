#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<PII> VPII;

typedef vector<double> VD;
typedef vector<string> VS;

typedef long long LL;

VI motes;

int A;
int N;

int dfs(int steps, int a, int i){
    //printf("dfs(%d, a=%d, %d)\n", steps, a, i);

    if(i > N){
    
        //printf("  finished\n");
        return steps;
        }
    
    int mote = motes[i];
    
    // simply absorb;
    int aa;
    if(mote < a){
        aa = a + mote;
        //printf("  absorb\n");
        return dfs(steps, aa, i + 1);
    }
    
    if (i == N-1){
        // removing or adding: doesn't care
        return steps + 1;
    }
    
    int s1 = 9999, s2 = 9999;    
    
    // should we add motes?
    int remM = N - i - 1;
    aa = a;
    for(int j=0; j < remM; j++){
        const int newMote = aa-1;
        aa += newMote;
        //printf("  aa=%d\n", aa);
        if(aa > mote){
            aa += mote;
            s1 = dfs(steps + j + 1, aa, i + 1);
            break;
        }
    }
    
    // should we just remove the rest?
    s2 = steps + (remM + 1);
    
    //printf("  s1=%d, s2=%d\n", s1, s2);
    // argh, it's 02:36am...
    return min(s1, s2);
}

int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
	    motes.clear();

		printf("Case #%d: ", caseNr);
		
        // READ	
		scanf("%d %d\n", &A, &N);
		
		for(int i=0; i<N; i++){
		    int x;
		    scanf("%d", &x);
		    motes.push_back(x);
		}
		
		// SOLVE
		
		sort(motes.begin(), motes.end());
		
		int steps = dfs(0, A, 0);
		
		printf("%d\n", steps);
		
		fflush(stdout);
	}
	
	return 0;
}
