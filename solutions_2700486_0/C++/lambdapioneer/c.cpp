/*

Better solution: Create secure triangles. Those have the size 1,6,15,... and
the probability of their cells is always 1.0 .

If asked about any position on the side, we simply can determine how many of
the a=left and b=left possiblities would be satisfiy the criteria that that
cell is true.

This also works then for the large one :)

*/

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

int N;
int rx, ry;

bool diamond [2000][2000];
#define OFFSET 1000

int hits, totalCnt;


PII slideDown(int x, int y){
    while (y > 0){
        
    
        const bool blockedLeft = diamond[x-1][y-1];
        const bool blockedRight = diamond[x+1][y-1];
        if(blockedLeft && blockedRight){
            // we are stucked
            break;
        }
        else if(blockedLeft && !blockedRight){
            // slide right
            x++;
        }else if(!blockedLeft && blockedRight){
            // slide left
            x--;
        }else{
            // just drop
        }
        --y;
    }

    return PII(x, y);
}

void dfs(int n){
    // all diamonds placed?
    if(n==0){
        if(diamond[rx][ry]){
            ++hits;       
        }
        ++totalCnt;
        return;
    }
    
    // let fall
    const int x = OFFSET;
    int y = 40; // high enough for the small one
    
    bool split = false;
    
    // look if we hit a single top thing
    while (y > 1){        
        // check underneath
        const bool blockedUnder = diamond[x][y-2];    
        
        if(blockedUnder){    
            const bool blockedLeft = diamond[x-1][y-1];
            const bool blockedRight = diamond[x+1][y-1];
            if ((!blockedLeft) && (!blockedRight)){
               split = true;    // we will only split once
               break;        
            }else{
               split = false;   // there is only ONE way
               break;      
            }
        }
        // else keep on falling
        --y;
    }
    
    if(split){
        PII pos1 = slideDown(x+1, y+1);
        PII pos2 = slideDown(x-1, y+1);
        
        //printf("  split: %d,%d and %d,%d\n", pos1.first-1000, pos1.second, pos2.first-1000, pos2.second);
        
        // go for pos1
        diamond[pos1.first][pos1.second] = true;
        dfs(n-1);
        diamond[pos1.first][pos1.second] = false;
        
        // go for pos 2
        diamond[pos2.first][pos2.second] = true;
        dfs(n-1);
        diamond[pos2.first][pos2.second] = false;
    }else{
        PII pos1 = slideDown(x, y+1);
        
        //printf("  normal: %d,%d\n", pos1.first-1000, pos1.second);
        
        diamond[pos1.first][pos1.second] = true;
        dfs(n-1);
        diamond[pos1.first][pos1.second] = false;
    }
}

int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
	    // INIT
	    memset(diamond, false, sizeof(diamond));
		hits = 0;
		totalCnt = 0;
	
		// READ
		printf("Case #%d: ", caseNr);
		
		scanf("%d %d %d\n", &N, &rx, &ry);
		//printf("\n n=%d x,y=%d,%d\n", N, rx, ry);
		
		// special case: out of border
		if(rx > OFFSET-10 || rx < -OFFSET+10 || ry > OFFSET-10){		
		    printf("%.9lf\n", 0.0);
		    fflush(stdout);
		    continue;
		}
		    
		// fix offset...
		rx += OFFSET;
		
		// PLACE
		dfs(N);
		
		// OUTPUT
		double result = (double) hits / (double) totalCnt;
		printf("%.9lf\n", result);
		fflush(stdout);
	}
	
	return 0;
}
