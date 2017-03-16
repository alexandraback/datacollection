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

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back

int main()
{
    int T;
    cin >> T;
    double C, F, X;
    REP(caso, T) {
        cin >> C >> F >> X;
        double farmtime = 0.0;
        double sol = 1000000.0;
        REP(farms, 1000000) {
            double next = farmtime + X/((double)farms*F + 2.0);
            if(next > sol) break;
            sol = next;
            
            // calc next farmtime
            farmtime += C/((double)farms*F + 2.0);
        }
        printf("Case #%d: %.7lf\n", caso+1, sol);
        
    }
}
