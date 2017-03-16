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

int T, X, R, C;

int main() {
    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {
        scanf("%d%d%d", &X, &R, &C);

        cout << "Case #" << test << ": "; 

        if ((R * C) % X != 0) {
            cout << "RICHARD\n";
            continue;
        }

        if (X == 1 || X == 2) {
            cout << "GABRIEL\n";
            continue;
        }
        else if (X == 3) {
            cout << ((R * C == 3) ? "RICHARD\n" : "GABRIEL\n");
            continue;
        }
        else if (X == 4) {
            cout << ((R * C <= 8) ? "RICHARD\n" : "GABRIEL\n");
            continue;
        }
    }
    
    return 0; 
}
