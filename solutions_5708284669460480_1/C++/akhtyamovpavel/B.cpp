#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "B.in"
#define FILEOUT "B.out"



int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
    	
        int n1, n2, t;
        cin >> n1 >> n2 >> t;
        string s1;
        string s2;
        cin >> s1 >> s2;

        int c[26];
        for (int i = 0; i < 26; ++i) {
            c[i] = 0;
        }
        
        for (int i = 0; i < n1; ++i) {
            c[s1[i] - 'A']++;
        }
        long double expe = 0.0;
        long double words = max(t - n2 + 1, 0);
        for (int i = 0; i < n2; ++i) {
            words *= ((long double)(c[s2[i] - 'A']))/(long double)n1;
        }

        int maxans = 0;
        int maxtail = 0;
        // cout << s2 << endl;
        for (int i = 1; i <= n2 - 1; ++i) {
            bool f = true;
            for (int k = 0; k < i; ++k) {
                if (s2[n2- i + k] != s2[k]) {
                    f = false;
                }
                
            }
            if (f) {
                maxtail = i;
            }
        }

        bool maybe = true;
        for (int i =0; i < n2; ++i) {
            if (c[s2[i] - 'A'] == 0) {
                maybe = false;
            }
        }
        long double ans = 0.0;
        int much = 0;
        if (maybe) {
            // cout << maxtail << endl;
            much = 1 + (t - n2)/(n2-maxtail);
            // cout << much << endl;
            ans = much - words;
        }


        cout << "Case #" << _ << ": ";
        //Output answer
        cout << fixed;
        cout << setprecision(8); 
        cout << ans;
        
        cout << endl;
    }
    return 0;
}