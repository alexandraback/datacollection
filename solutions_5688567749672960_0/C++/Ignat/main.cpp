#ifdef DEBUG_OUTPUT
#include "debug_output.h"
#else
#define PRINT(x)
#define PRINT_CONT(x)
#define PRINT_MSG(x)
#endif

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <cstdio>
#include <cassert>
using namespace std;


// Enlarge MSVS stack size
#pragma comment(linker, "/STACK:16777216")

#define pb push_back
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define sz(x) static_cast<int>(x.size())
typedef long long int64;

template<class T> T sqr(const T& t) {return t * t;}
template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}

void initialize()
{
    freopen("0.in", "r", stdin);
    freopen("0.out", "w", stdout);
}

const int MAX = 1000000 + 10;
int shortest[MAX];

int reverse(int num) {
    int res = 0;
    while (num > 0) {
        int d = (num % 10);
        num /= 10;
        res = (res * 10) + d;
    }
    return res;
}

int main()
{
    initialize();

    shortest[1] = 1;
    vector<int> q(MAX + 1);
    int st = 0;
    int en = 0;
    q[en++] = 1;
    while (st < en) {
        int num = q[st++];
        //cerr << st << " " << num << endl;
        if (num + 1 < MAX && shortest[num + 1] == 0) {
            shortest[num + 1] = shortest[num] + 1;
            q[en++] = num + 1;
        }

        int r = reverse(num);
        if (r < MAX && shortest[r] == 0) {
            shortest[r] = shortest[num] + 1;
            q[en++] = r;
        }
    }
    

    int T;
    cin >> T;

    for (int tt = 1; tt <= T; ++tt) {
        int64 n;
        cin >> n;
        cout << "Case #" << tt << ": " << shortest[n] << endl; 
    }
    
    return 0;
}
