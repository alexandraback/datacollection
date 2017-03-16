#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long


bool isok(int n, string s) {
    for(int i=SZ(s)-1; i>=0; i--) {
        int d = n%10;
        n /= 10;
        if(s[i] == '?') continue;
        if(s[i]-'0' != d) return false;
    }
    return true;
}

void copytostr(int n, string &s) {
    for(int i=SZ(s)-1; i>=0; i--) {
        int d = n%10;
        n /= 10;
        s[i] = d+'0';
    }
}

int aabs(int a) {
    return (a<0)?-a:a;
}

int main()
{
    int T;
    cin >> T;
    REP(caso, T) {
        cout << "Case #" << caso+1 << ": ";
        string S, T;
        cin >> S >> T;
        int MAX=1;
        REP(i, SZ(S)) MAX *= 10;
        // cout << S << " " << T << " ";
        int bests=MAX-1, bestt=0;
        REP(s, MAX) {
            if(!isok(s,S)) continue;
            REP(t, MAX) {
                if(!isok(t,T)) continue;
                if(aabs(s-t) < aabs(bests-bestt)) {
                    bests=s;
                    bestt=t;
                }
            }
        }

        copytostr(bests, S);
        copytostr(bestt, T);
        
        cout << S << " " << T << endl;
    }
}
