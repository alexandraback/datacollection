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

// how can a treasure be opened
int t2k[50];

// which keys are in a chest
VI tContains[50];
int keyCnt[500];

// set of all visited combinations
// idea: it does not matter on which path we ended up here
// when we are at the same state we also have the same key
// configuration available.
bool visited[2*4194304]; // =2*(2^22)

int K, N;

int trace[50];

// @param open: binary set for checking on the current state of opened treasures
bool backtrack(int depth, int open){

    if(visited[open])
        return false;        
    visited[open] = true;
    
    const int cntOpen = depth;
    if(cntOpen == N)
        return true;
    
    // try to open treasures for opening
    for(int t=1; t<=N; t++){    
        const int treasureBit = 0x01 << t;   
        
        // Thank you, "g++ -Wall"
        //       v-- I will always put paranthesises around bitwise &
        if((open & treasureBit) != 0x00)
            continue; // no need to reopen
                    
        const int keyNeeded = t2k[t];
        if (keyCnt[keyNeeded] <= 0)
            continue; // no key available
        
        // lets open
        --keyCnt[keyNeeded];
        
        // get AAALLL the keys
        const int s = tContains[t].size();
        for(int i=0; i<s; i++)
            ++keyCnt[tContains[t][i]];
        
        // backtrack
        trace[depth] = t;
        const bool success = backtrack(depth + 1, open | treasureBit);
        if(success)
            return success | true;
            
        // give back all the keys :(
        for(int i=0; i<s; i++)
            --keyCnt[tContains[t][i]];
        
        // and close
        ++keyCnt[keyNeeded];
    }
    
    return false;
}

int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
	    // INIT	    

        for(int i=0; i<2*4194304;i++)
            visited[i] = false;
	    for(int i=0; i<50; i++){
	        t2k[i] = -1;
	        tContains[i].clear();	        
	        trace[i] = -1;
	    }
	    for(int i=0; i<500; i++){
	        keyCnt[i] = 0;
        }	
		
		// READ
		scanf("%d %d\n", &K, &N);		
		
		// READ initial keys
		for(int x=0; x<K; x++){
		    int k;
		    scanf("%d", &k);		    
		    keyCnt[k]++;
		}
		
		// READ about treasures
		for(int t=1; t<=N; t++){
		    int key, cnt;
		    scanf("%d %d", &key, &cnt);
		    		    
		    t2k[t] = key;
		    
		    for(int x=0; x<cnt; x++){
		        int k;
		        scanf("%d", &k);
		        tContains[t].push_back(k);
		    }
		}
		
		// START BACKTRACK	    
	    bool success = backtrack(0, 0);	
	    
	    // PRINT output	
		printf("Case #%d: ", caseNr);
	    if(success){
	        // print trace
	        for(int i=0; i<N; i++){
	            if(i>0)
	                printf(" ");
                printf("%d", trace[i]);
	        }
	        printf("\n");
	    }else{
	        printf("IMPOSSIBLE\n");
	    }
		
		fflush(stdout);
	}
	
	return 0;
}
