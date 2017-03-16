#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <memory.h>
 
using namespace std;
 
#define LL               long long
#define pb               push_back
#define mp               make_pair
typedef vector <int>     vi; 
typedef vector <string>  vs;
typedef pair   <int,int> pii;


int row, col, k, res;



void solve1() {
    int tmp;
    for (int x=1; x<=row-2; x++) for (int y=1; y<=col-2; y++) {
        tmp = x*y + 2*(x+y);
        if (tmp<=k && k<=tmp+4) {
            res = min(res, 2*(x+y) + k-tmp);
        }
    }
}

void solve2() {
    int tmp;

    //
    for (int x=1; x<=row-2; x++) for (int y=1; y<=col-3; y++) {
        for (int z=1; z<x; z++) {
            tmp = x*y+z + 2*(x+y+1);
            if (tmp<=k && k<=tmp+5) {
                res = min(res, 2*(x+y+1) + k-tmp);
            }
        }
    }

    //
    for (int x=1; x<=row-3; x++) for (int y=1; y<=col-2; y++) {
        for (int z=1; z<y; z++) {
            tmp = x*y+z + 2*(x+y+1);
            if (tmp<=k && k<=tmp+5) {
                res = min(res, 2*(x+y+1) + k-tmp);
            }
        }
    }

    //
    for (int x=1; x<=row-3; x++) for (int y=1; y<=col-3; y++) {
        for (int z=1; z<x; z++) for (int t=1; t<y; t++) {
            tmp = x*y+t+z + 2*(x+y+2);
            if (tmp<=k && k<=tmp+6) {
                res = min(res, 2*(x+y+2) + k-tmp);
            }
        }
    }
}

void solve3() {
    int t = 1;
    for (int i=2; i<=1000; i++) {
        if (i*2-1 > row) break;
        
        //
        if (t + (i-1)*4 >= k) res = min(res, (i-1)*4);
        t += (i-1)*4;
    }
}

int main() {
    int num_test;
    
    //
    cin >> num_test;
    for (int i=1; i<=num_test; i++) {
        cin >> row >> col >> k; if (row > col) swap(row, col);

        //
        res = INT_MAX;
        if (k<=4) res = k; 
        else if (row<=2) res = k;
        else {
            solve1();
            solve2();
            solve3();
        }

        //
        printf("Case #%d: %d\n", i, res);
    }

    //
    return 0;
}
