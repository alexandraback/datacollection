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

int T;
string pan;

int main() {
    scanf("%d", &T);
    
    FOR1(tc, T) {
        printf("Case #%d: ", tc);
        cin >> pan;

        int flips = 0;

        for (int i = 1; i < pan.size(); i++) {
            if (pan[i] != pan[i-1]) flips++;
        }

        cout << flips + (pan[pan.size()-1] == '-') << "\n";
    }
    
    return 0;
}
