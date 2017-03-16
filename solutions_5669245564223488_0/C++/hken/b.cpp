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
const LL MOD = 1000000007;

typedef vector <int>     vi; 
typedef vector <string>  vs;
typedef pair   <int,int> pii;


int n; LL res;
string a[100];

//
bool dx[100];


int valid1(const string& t) {
    //
    int r = 1;
    bool b[26]; memset(b, true, sizeof(b));

    //
    for (int i=0; i<t.length(); i++) {
        if (b[t[i]-'a']) { b[t[i]-'a'] = false; continue; }
        if (t[i] != t[i-1]) {
            r = 0; break;
        }
    }

    //cerr << t << " " << r << endl;

    return r;
}

void go1(int k, const string& t) {
    //
    if (k==0) { 
        res += valid1(t); 
        return; 
    }

    //
    for (int i=0; i<n; i++) if (dx[i]) {
        dx[i] = false;
        go1(k-1, t+a[i]);
        dx[i] = true;
    }
}


void solve1() {
    res = 0; memset(dx, true, sizeof(dx));
    go1(n, "");
}


int main() {
    int num_test;

    //
    cin >> num_test;
    for (int i=1; i<=num_test; i++) {
        cin >> n;
        for (int j=0; j<n; j++) cin >> a[j];
    
        //
        //cerr << n << endl;
        //for (int j=0; j<n; j++) cerr << a[i] << " "; cerr << endl;

        solve1();
        printf("Case #%d: %lld\n", i, res);
    }

    //
    return 0;
}
