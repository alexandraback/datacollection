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

inline bool isV(char c){
    switch(c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

char buf[2000000];
int n;
int L;

int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
		// go for it!	
		printf("Case #%d: ", caseNr);
		
		// INIT
		memset(buf, '\0', sizeof(buf));
		
		// READ
		char c;
		for(int i=0; true; i++){
		    scanf("%c", &c);
		    if(c == ' '){
		        L = i;
		        break;
	        }
		    buf[i] = c;
		}
		
		scanf("%d\n", &n);
		
		long long cnt = 0;
		
		// ADVANCED O(N)
		
		bool active = false;
		LL last = 0;
		int cons = 0;
		for(int i=0; i<L; i++){
		
		    //printf("i=%d cnt=%d\n", i, cnt);
		    const bool con = !isV(buf[i]);
		    		    
		    if(con){
		        ++cons;
		        if(cons >= n){
		            // forms end of a consecutive segments
		            last = i-(n-1)+1;
		            cnt += last;
		            active = true;
		        }else{		            
		            if(!active)
		                continue;
	                cnt += last;
		        }
		    }else{
		        // VOWEL
		        cons = 0;
		        if(!active)
		            continue;
	            cnt += last;
		    }
		}
		
		
		printf("%lld\n", cnt);
		
		
		fflush(stdout);
	}
	
	return 0;
}
