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
    	string s; string r; cin>>r;
    	REP(i, r.size()) {
    		char c = r[i];
    		string s1 = s + c, s2 = c + s;
    		s = max(s1, s2);
    	}
    	printf("Case #%d: %s\n", caseN + 1, s.c_str());
    }
    return 0;
}