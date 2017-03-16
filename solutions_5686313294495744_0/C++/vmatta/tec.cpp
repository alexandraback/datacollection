
#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <map>
*/
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fst first
#define scd second
#define f(x, let) for(int let=0; let<x; let++)
#define ms(x, v) memset(x, v, sizeof x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef set<int> si;
typedef set<int>::iterator sit;
const int MOD = 1000000007;
const int OO = 1000000000;
//REMEMBER LONG LONG INT
//REMEMBER TO INITIALZE THINGS

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    f (t, k) {
        int n;
        cin >> n;
        set<string> s1;
        set<string> s2;
        vector<string> v1;
        vector<string> v2;
        f (n, i) {
            string s;
            cin >> s;
            v1.pb (s);
            cin >> s;
            v2.pb (s);
        }
        int org = 0;
        f (n, i) {
            int ok1 = 0, ok2 = 0;
            f (n, j) {
                if (i == j) continue;
                if (v1[i].compare (v1[j]) == 0) ok1 = 1;
                if (ok1) break;
            }
            f (n, j) {
                if (i == j) continue;
                if (v2[i].compare (v2[j]) == 0) ok2 = 1;
                if (ok2) break;
            }
            if (!ok1 || !ok2) {
                org++;
                s1.insert (v1[i]);
                s2.insert (v2[i]);
            }
        }
        f(n, i) {
            if (s1.find (v1[i]) == s1.end () && s2.find (v2[i]) == s2.end ()) {
                org++;
                s1.insert (v1[i]);
                s2.insert (v2[i]);
            }
        }
        f(n, i) {
            if (s1.find (v1[i]) == s1.end () || s2.find (v2[i]) == s2.end ()) {
                org++;
                s1.insert (v1[i]);
                s2.insert (v2[i]);
            }
        }
        cout << "Case #" << k+1 << ": " << n-org << endl;
    }   
}
