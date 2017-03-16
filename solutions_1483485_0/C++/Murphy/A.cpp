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

string s = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
    int c;
    cin>>c;
    string s2;
    getline(cin, s2);
    REP(i, c) {
        getline(cin, s2);
        REP(j, s2.size()) {
            if (s2[j] >= 'a' && s2[j] <= 'z') {
                s2[j] = s[s2[j] - 'a'];
            }
        }
        printf("Case #%d: %s\n", i + 1, s2.c_str());
    }
}
