#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <bitset>

#include <complex>

//#include <unordered_map>
//#include <unordered_set>

#define llong long long int
#define pb push_back
#define mp make_pair
#define pr pair <int, int>
#define X first
#define Y second
#define endl "\n"
using namespace std;
const int MAXN = 1e5 + 7;
//const int INF = 1e9 + 7;
//const llong LINF = 1e18;
//const llong MOD = 1e9 + 7;
//const long double EPS = 1e-18;
using namespace std;
int tests;
vector<int> ans;
map <char ,int>  C;
string DIG[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
map <char, int> cntD[20];
inline bool check(int digits) {
    for (auto i: cntD[digits]) {
        if (C[i.first] < i.second) {
            return false;
        }
    }
    return true;
}

inline void er(int digits) {
    for (auto i: cntD[digits]) {
        C[i.first] -= i.second;
        
    }
    ans.pb(digits);
}
int main() {
#ifdef DEBUG
    
    double beg = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
#else
    //freopen("centroid.in", "r", stdin);
    //freopen("centroid.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie();
    cin >> tests;
    for (int i = 0; i <= 9; i++) {
        for (auto j: DIG[i]) {
            cntD[i][j]++;
        }
    }
    for (int test = 1; test <= tests; test++) {
        string ST;
        C.clear();
        cin >> ST;
        ans.clear();
        
        for (auto i: ST) {
            C[i]++;
        }
        while (check(0)) {
            er(0);
        }
        
        while (check(6)) {
            er(6);
        }
        
        while (check(7)) {
            er(7);
        }
        
        while (check(2)) {
            er(2);
        }
        
        while (check(5)) {
            er(5);
        }
        
        while (check(4)) {
            er(4);
        }
        
        while (check(8)) {
            er(8);
        }
        
        while (check(1)) {
            er(1);
        }
        
        while (check(3)) {
            er(3);
        }
        
        while (check(9)) {
            er(9);
        }
        sort(ans.begin(), ans.end());
        cout << "Case #" << test << ": ";
        for (auto i: ans) {
            cout << i;
        }
        cout << '\n';
    }
    /*
     
     
     Zero
     siX
     Seven
     tWo
     fiVe
     Four
     eiGht
     One
     Three
     Nine
     
     */
#ifdef DEBUG
    double end = clock();
    fprintf(stderr, "\n*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}