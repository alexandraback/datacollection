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

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MOD 1000000007
#define INF 2000000000

const int MAXN = 35;
const int MAXD = 11;

int md[MAXD][MAXN][MAXD]; // (i ^ j) mod k

int N, J;

map<vector<int>, vector<int> > good;

vector<int> v;

void printv() { FORD(i, v.size()) cout << v[i]; cout << " "; }

bool test() {
    vector<int> div;

    for (int b = 2; b < MAXD; b++) {
        int m = 2;

        while (m < MAXD) {
            int vm = 0;
            
            FORN(i, N) {
                if (v[i]) vm = (vm + md[b][i][m]) % m;
            }

            if (vm == 0) break;
            else m++;
        }

        if (m < MAXD) {
            div.PB(m);
        }
        else {
            return false;
        }
    }

    good[v] = div;
    return true;
}

int main() {
    FORN(j, MAXN) FORN(i, MAXD) FOR1(k, MAXD-1) {
        md[i][j][k] = (j == 0) ? 1 % k : (md[i][j-1][k] * i) % k;
    }

    cin >> N >> J; 
    v.resize(N); v[0] = v[N-1] = 1;

    cout << "Case #1:" << endl;

    while (J) {
        for (int i = 1; i < N-1; i++) v[i] = rand() % 2;

        if (good.find(v) == good.end() && test()) {
            printv();
            FORN(i, good[v].size()) cout << good[v][i] << " ";
            cout << endl;
            J--;
        }
    }

    return 0;
}
