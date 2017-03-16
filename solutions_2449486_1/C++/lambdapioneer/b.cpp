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

int rowMax[200];
int colMax[200];
int lawn[200][200];
int R, C;

int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
		// go for it!	
		printf("Case #%d: ", caseNr);
		
		// READ
		scanf("%d %d\n", &R, &C);
		for(int i=0; i<R; i++){
		    for(int j=0; j<C; j++){
		        scanf("%d", &lawn[i][j]);	            
		    }	    
		}
		
		// CALC
		for(int r=0; r<R; r++){
		    rowMax[r] = 0;
		    for(int c=0; c<C; c++)
		        rowMax[r] = max(rowMax[r], lawn[r][c]);		  
	       
		}
	    for(int c=0; c<C; c++){
		    colMax[c] = 0;
    		for(int r=0; r<R; r++)
		        colMax[c] = max(colMax[c], lawn[r][c]);		  
		}
		
		// CHECK
		bool valid = true;
		for(int r=0; r<R; r++){
		    for(int c=0; c<C; c++){
		        if(min(colMax[c], rowMax[r]) != lawn[r][c]){
		            // no way we can cut yo lawn, bro!
		            valid = false;
		            break;
                }	            
		    }
	    }
	    
	    if (valid)
	        printf("YES\n");
        else
            printf("NO\n");
		
		
		fflush(stdout);
	}
	
	return 0;
}
