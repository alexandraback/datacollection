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

int main() {
    int T;
    cin >> T;
    string digits[] = {
        "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };
    for ( int tc=1 ; tc<=T ; ++tc ) {
        cout << "Case #" << tc << ": ";
        string line;
        cin >> line;
        vector<int> chars(26);
        for ( int i=0 ; i<line.size() ; ++i ) {
            chars[line[i]-'A']++;
        }
        vector<int> res;

        string d1 = "ZWUXG";
        int n1[] = {0, 2, 4, 6, 8};
        for ( int i=0 ; i<d1.length() ; ++i ) {
            int k = chars[d1[i]-'A'];
            for ( char c : digits[n1[i]] ) {
                chars[c-'A'] -= k;
            }
            for ( int j=0 ; j<k ; ++j ) {
                res.push_back(n1[i]);
            }
        }

        string d2 = "HF";
        int n2[] = {3, 5};
        for ( int i=0 ; i<d2.length() ; ++i ) {
            int k = chars[d2[i]-'A'];
            for ( char c : digits[n2[i]] ) {
                chars[c-'A'] -= k;
            }
            for ( int j=0 ; j<k ; ++j ) {
                res.push_back(n2[i]);
            }
        }

        string d3 = "OVI";
        int n3[] = {1, 7, 9};
        for ( int i=0 ; i<d3.length() ; ++i ) {
            int k = chars[d3[i]-'A'];
            for ( char c : digits[n3[i]] ) {
                chars[c-'A'] -= k;
            }
            for ( int j=0 ; j<k ; ++j ) {
                res.push_back(n3[i]);
            }
        }

        sort(res.begin(), res.end());
        for ( auto x : res ) {
            cout << x;
        }
        cout << endl;
    }
    return 0;
}
