#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define FF first
#define SS second
#define MP make_pair
#define PB push_back

#define MOD 1000000007
#define INF 2000000000

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

int T, L; LL X; string pat; string s;

int mult[5][5] = {{0, +0, +0, +0, +0},
                  {0, +1, +2, +3, +4},
                  {0, +2, -1, +4, -3},
                  {0, +3, -4, -1, +2},
                  {0, +4, +3, -2, -1}};

inline int convert(char c) {
    if (c == 'i') return 2;
    if (c == 'j') return 3;
    if (c == 'k') return 4;
    return 0;
}

int main() {
    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {
        cin >> L >> X >> pat; int psz = pat.size();

        if (X > 16) X = 16 + (X % 4);

        s = "";

        for (int i = 0; i < (int)X; i++) s = s + pat;
        int ssz = s.size();

        int currval = 1;
        int firsti = -1;
        int firstj = -1;

        for (int i = 0; i < ssz; i++) {
            int sgn = (currval < 0) ? -1 : 1;
            currval = mult[abs(currval)][convert(s[i])];
            currval = currval * sgn;

            if (currval == 2) {
                firsti = i;
                break;
            }
        }

        //cout << "DBG " << firsti << "\n";

        if (firsti == -1) {
            cout << "Case #" << test << ": NO\n";
            continue;
        }

        currval = 1;
        for (int i = firsti + 1; i < ssz; i++) {
            int sgn = (currval < 0) ? -1 : 1;
            currval = mult[abs(currval)][convert(s[i])];
            currval = currval * sgn;

            if (currval == 3) {
                firstj = i;
                break;
            }
        }
        
        //cout << "DBG " << firstj << "\n";

        if (firstj == -1) {
            cout << "Case #" << test << ": NO\n";
            continue;
        }

        currval = 1; bool found = false;
        for (int i = firstj + 1; i < ssz; i++) {
            int sgn = (currval < 0) ? -1 : 1;
            currval = mult[abs(currval)][convert(s[i])];
            currval = currval * sgn;
        }

        if (currval != 4) cout << "Case #" << test << ": NO\n";
        else cout << "Case #" << test << ": YES\n";
    }
    
    return 0; 
}
