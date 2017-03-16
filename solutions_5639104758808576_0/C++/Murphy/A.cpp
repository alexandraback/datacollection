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
        int N, c = 0, r = 0;
        string s;
        cin>>N>>s;
        REP(i, N + 1) {
            int n = s[i] - '0';
            r = max(r, i - c);
            c += n;
        }
    	printf("Case #%d: %d\n", caseN + 1, r);
    }
    return 0;
}