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
    	int r = 1;
        int b[20] = {0}; b[3] = 2; b[4] = 2;
        int c[20] = {0}; c[4] = 5;
        b[5] = 3; c[5] = 10;
        b[6] = 4;
    	if (X == 7) r = 0;
    	else {
            if (R * C / X * X != R * C) r = 0;
            if (R < b[X]) r = 0;
            if (R == b[X] && C < c[X]) r = 0;
    	}
    	printf("Case #%d: %s\n", caseN + 1, r ? "GABRIEL" : "RICHARD");
    }
    return 0;
}