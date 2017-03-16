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

char field[4][4];

int check(char p){
    // ROWS
    for(int i=0; i<4; i++){
        bool valid = true;
        for(int j=0; j<4; j++){
            if(field[i][j] == p || field[i][j] == 'T'){
                continue;
            }else{
                valid = false;
                break;
            }
        }
        if (valid) return 1;
    }
    // COLS
    for(int i=0; i<4; i++){
        bool valid = true;
        for(int j=0; j<4; j++){
            if(field[j][i] == p || field[j][i] == 'T'){
                continue;
            }else{
                valid = false;
                break;
            }
        }
        if (valid) return 1;
    }
    // DIAG
    {
        bool valid = true;
        for(int i=0; i<4; i++){
            if(field[i][i] == p || field[i][i] == 'T'){
                continue;
            }else{
                valid = false;
                break;
            }
        }
        if (valid) return 1;
    }
    {
        bool valid = true;
        for(int i=0; i<4; i++){
            if(field[i][3-i] == p || field[i][3-i] == 'T'){
                continue;
            }else{
                valid = false;
                break;
            }
        }
        if (valid) return 1;
    }
    
    return 0;
}

int ne; // not empty


int main(){ 	
	int cases;
	scanf("%d\n", &cases);
	
	for(int caseNr = 1; caseNr <= cases; caseNr++){
		// go for it!	
	    ne = 0;
		
		// READ
		for(int i=0; i<4; i++){
		    for(int j=0; j<4; j++){
		        char c = '\n';
		        while (c == '\n')
		            scanf("%c", &c);
                field[i][j] = c;
                if(c == 'O' || c == 'X' || c == 'T')
                    ++ne;
		    }
		    scanf("\n");
		}
		
		// TRY
		int x = 0, o = 0;
		x = check('X');
		o = check('O');
		
		printf("Case #%d: ", caseNr);
		
		if(x == 1 && o == 0){
		    printf("X won\n");
		}else if(x == 0 && o == 1){
		    printf("O won\n");
		}else if (x==1 && o == 1){
		    printf("Draw\n");
		}else{
		    if(ne == 16)
    		    printf("Draw\n");
		    else
	    	    printf("Game has not completed\n");
		}
		
		fflush(stdout);
	}
	
	return 0;
}
