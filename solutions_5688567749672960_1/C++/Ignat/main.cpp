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
    freopen("large.in", "r", stdin);
    freopen("large.out", "w", stdout);
}

const int MAX = 10000000 + 10;
int shortest[MAX];
int back[MAX];

int reverse(int num) {
    int res = 0;
    while (num > 0) {
        int d = (num % 10);
        num /= 10;
        res = (res * 10) + d;
    }
    return res;
}

int64 pow(int64 num, int64 deg) {
    int64 res = 1;
    for (int i = 0; i < deg; ++i) {
        res *= num;
    }
    return res;
}

int length(int64 num) {
    int res = 0;
    while (num > 0) {
        res += 1;
        num /= 10;
    }
    return res;
}

void split(int64 num, int* a, int* b) {
    int res = 0;
    int len = length(num);

    *a = 0;
    *b = 0;

    int deg = 1;
    bool first = true;
    for (int i = 0; i < len; ++i) {
        int d = (num % 10);
        num /= 10;
        if (i * 2 + 1 < len) {
            *a = d * deg + (*a);
        } else {
            if (first) {
                deg = 1;
                first = false;
            }
            *b = d * deg + *b;
        }
        deg *= 10;
    }
}

int solve(int64 num) {
    if (num < 10) {
        return num;
    }

    //cerr << "SOLVE " << num << endl;;

    int len = length(num);
    int64 next = pow(10, len - 1) - 1;
    int64 add = 0;
    if (length(num - next - 1) <= ((len + 1) / 2)) {
        //cerr << "FIRST " << num - next << endl;
        add = num - next;
    } else {
        int a, b;
        split(num, &a, &b);
        if (a == 0) {
            return 1 + solve(num - 1);
        }
        
        //cerr << a << " " << reverse(b) << endl;
        // a > 0
        add += (a - 1);
        int flag = (b != pow(10, (len - 1) / 2));
        add += 1 + reverse(b) + flag;
    }

    return add + solve(next);
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
            back[num + 1] = num;
            q[en++] = num + 1;
        }

        int r = reverse(num);
        if (r < MAX && shortest[r] == 0) {
            shortest[r] = shortest[num] + 1;
            back[r] = num;
            q[en++] = r;
        }
    }

    //cerr << shortest[1110] << " " << solve(1110) << endl;
    //for (int i = 1; i <= 100000; ++i) {
    //    if (shortest[i] != solve(i)) {
    //        cerr << i << ": " << shortest[i] << " " << solve(i) << endl;
    //        return 0;
    //    }
    //}

    //int num = 299;
    //while (num > 1) {
    //    cerr << num << endl;
    //    num = back[num];
    //}

    //for (int num = 1; num <= 1000000; num *= 10) {
    //    cerr << num << " " << shortest[num] << endl;
    //    cerr << 2 * num << " " << shortest[2 * num] << endl;
    //}
    

    int T;
    cin >> T;

    for (int tt = 1; tt <= T; ++tt) {
        int64 n;
        cin >> n;
        cout << "Case #" << tt << ": " << solve(n) << endl; 
    }
    
    return 0;
}
