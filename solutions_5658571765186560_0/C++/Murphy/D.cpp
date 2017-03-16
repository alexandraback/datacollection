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
    	int X, R, C; cin>>X>>R>>C;
    	if (R > C) swap(R, C); //R <= C
    	int r = 0;
    	if (X == 1) r = 1;
    	else if (X == 2) r = (R == 2 || C == 2 || R == 4 || C == 4);
    	else if (X == 3) {
    		if (R == 1) r = false;
    		if (R == 2) r = C == 3; //2.2x 2.3t 2.4x
    		if (R == 3) r = true; //3.3t 3.4t
    		if (R == 4) r = false; //4.4x
    	} else {
    		if (R == 1) r = false;
    		if (R == 2) r = false; //2.2x 2.3x 2.4f-z
    		if (R == 3) r = C == 4; //3.3x 3.4t
    		if (R == 4) r = true; //4.4t
    	}
    	printf("Case #%d: %s\n", caseN + 1, r ? "GABRIEL" : "RICHARD");
    }
    return 0;
}