#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cmath>
using namespace std;

long long res_n1, res_n2;
long long res_diff;
string res_s1, res_s2;

bool check(string s) {
    for ( int i=0 ; i<s.length() ; ++i ) {
        if ( s[i] == '?' ) return false;
    }
    return true;
}

void go(string s1, string s2) {
    // cout << s1 << " " << s2 << endl;
    if ( check(s1) && check(s2) ) {
        long long n1, n2;
        sscanf(s1.c_str(), "%lld", &n1);
        sscanf(s2.c_str(), "%lld", &n2);
        long long diff = n1 > n2 ? n1 - n2 : n2 - n1;
        if ( diff < res_diff ) {
            res_diff = diff;
            res_n1 = n1;
            res_n2 = n2;
            res_s1 = s1;
            res_s2 = s2;
        }
        else if ( diff == res_diff ) {
            if ( n1 < res_n1 ) {
                res_n1 = n1;
                res_n2 = n2;
                res_s1 = s1;
                res_s2 = s2;
            }
            else if ( n2 < res_n2 ) {
                res_n1 = n1;
                res_n2 = n2;
                res_s1 = s1;
                res_s2 = s2;
            }
        }
        return;
    }
    for ( int i=0 ; i<s1.length() ; ++i ) {
        if ( s1[i] == '?' ) {
            for ( int j=0 ; j<10 ; ++j ) {
                s1[i] = char('0' + j);
                go(s1, s2);
            }
        }
    }
    for ( int i=0 ; i<s2.length() ; ++i ) {
        if ( s2[i] == '?' ) {
            for ( int j=0 ; j<10 ; ++j ) {
                s2[i] = char('0' + j);
                go(s1, s2);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        cout << "Case #" << tc << ": ";
        string coder, jammer;
        cin >> coder >> jammer;

        res_diff = INT64_MAX;
        res_n1 = res_n2 = -1;
        res_s1 = res_s2 = "";
        go(coder, jammer);

        cout << res_s1 << " " << res_s2 << endl;
    }
    return 0;
}
