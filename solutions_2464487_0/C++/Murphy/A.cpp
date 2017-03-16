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
typedef unsigned long long LL;
typedef pair<int, int> pii;

int main(){
    int caseNumber;
    scanf("%d", &caseNumber);
    //cin>>caseNumber;
    REP(caseN, caseNumber) {
        LL a, b;
        cin>>a>>b;
        LL res = 0;
        double L = 0, R = 1e10;
        while (R - L > 1) {
        	double M = (L + R) / 2;
        	double c = (M + 1) * (2 * M + 1 + 2 * a);
        	if (c < b) {
        		L = M;
        	} else {
        		R = M;
        	}
        	// cout<<c<<' '<<M<<endl;
        }
        for (LL i = max(0uLL, (LL)L); i <= L + 20; i++) {
        	LL d = (i + 1) * (2 * i + 1 + 2 * a);
        	if (d > b) {
        		res = i;
        		break;
        	}
        }
    	printf("Case #%d: %d\n", caseN + 1, (int)res);
    }
    return 0;
}