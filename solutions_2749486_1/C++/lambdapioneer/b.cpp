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

int X, Y, x, y;
char buf[5000000];

inline int abs(int x){
    return x >= 0 ? x : -x;
}

int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
		// go for it!	
		printf("Case #%d: ", caseNr);
		
		// INIT
		memset(buf, '\0', sizeof(buf));
		
		
		// READ
		scanf("%d %d\n", &X, &Y);
		
		// GO		
		int success = false;
		for(int steps = 1; steps < 500000; steps++){
		    x = X;
		    y = Y;
		    
		    //printf("steps=%d\n", steps);
		    
		    int bufpos = 0;
		    
		    bool fail = false;
		    
		    for(int step=steps; step>=1; step--){
		        //printf("  %d,%d\n", x, y);
		    
		        if(x == 0 && y == 0){
		            fail = true;
		            break;
	            }
		    
		        if(abs(x) > abs(y)){
		            // west <-> east
		            
		            if (x > 0){
		                // go west
		                buf[bufpos++] = 'E';
		                x -= step;
		            } else {
		                // go east
		                buf[bufpos++] = 'W';
		                x += step;
		            }
		        }else{
		            // north
		            // south
		            		            
		            if(y > 0){
		                // go south
		                buf[bufpos++] = 'N';
		                y -= step;
	                }else{
		                // go north
		                buf[bufpos++] = 'S';
		                y += step;
	                }
		        }
		    }
		    
		    if(fail || x != 0 || y != 0)
		        continue;
		        
	        // otherwise success
	        
	        // output backwards
	        for(int i=steps-1; i >= 0; i--){
	            printf("%c", buf[i]);
	        }
		    printf("\n");
		    
		    success = true;
	        break;
		    
		}
		
		// DEBUG
		if(!success){
		    fprintf(stderr, "FAILED: CASE %d\n", caseNr);
		}
		
		
		fflush(stdout);
	}
	
	return 0;
}
