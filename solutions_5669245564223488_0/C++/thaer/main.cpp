/* 
 * File:   main.cpp
 * Author: tlatif
 *
 * Created on May 11, 2014, 6:15 AM
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>

#define INF 999999999
#define pb push_back
typedef long long LL;

using namespace std;

LL counter;

vector<string> v;
int N;
bool taken[11];

//set<char> valid(string ps, string s, set<char> m) {
//    int i;
//    char prev = '#';
//    if (ps.size() > 0)
//        prev = ps[ps.size() - 1];
//    //cout<<ps<<" "<<s<<endl;
//    for (i = 0; i < s.size(); i++) {
//        if (prev != s[i]) {
//            if (m.find(s[i]) != m.end()) {
//                m.clear();
//                return m;
//            }
//            m.insert(s[i]);
//            prev = s[i];
//        }
//    }
//    return m;
//}

bool valid(string s) {
    int i;
    char prev = '#';
    set<char> m;
    //cout<<ps<<" "<<s<<endl;
    for (i = 0; i < s.size(); i++) {
        if (prev != s[i]) {
            if (m.find(s[i]) != m.end()) {
                return false;
            }
            m.insert(s[i]);
            prev = s[i];
        }
    }
    return true;

}

void backtrack(string str, int n) {
    if (n == N) {
        if (valid(str))
            counter ++;
        
    } else {
        int i;
        set<char> vset;
        for (i = 0; i < N; i++) {
            if (!taken[i]) {
                //vset = valid(str, v[i], m);
               // cout<<vset.size()<<endl;
                
                //if (vset.size() > 0) {
                    taken[i] = true;
                    backtrack(str + v[i], n + 1);
                    taken[i] = false;
                //}
                
            }
        }
    }
}



/*
 * 
 */
int main() {
    freopen("input.in", "r", stdin);//
    freopen("output.txt", "w", stdout);
    int tc = 0, t;
    cin>>t;
    LL fact[11];
    fact[0] = 0;
    fact[1] = 1;
//    for (i = 2; i < 11; i++) {
//        fact[i] = fact[i - 1] * i; 
//    }
    while (tc++ < t) {
        v.clear();
        int n;
        cin>>N;
        int i, j, k;
        string aux, proc = "";
        set<string> st;
        map<string, int> fs; 
        for (i = 0; i < N; i++) {
            cin>>aux;
            char prev = '#';
            proc = "";
            for (j = 0; j < aux.size(); j++) {
                if (prev != aux[j]) {
                    prev = aux[j];
                    proc += prev;
                }
            }
            //cout<<proc<<endl;
            //fs[proc]++;
            //st.insert(proc);
            v.pb(proc);
        }
        counter = 0;
        memset(taken, false, sizeof(taken));
        set<char> m, vset;
        string str = "";
        for (i = 0; i < N; i++) {
            //vset = valid(str, v[i], m);
            //cout<<vset.size();
            //if (vset.size() > 0) {
                taken[i] = true;
                backtrack(v[i], 1);
                taken[i] = false;
            //}
        }
        printf("Case #%d: ", tc);
        cout<<counter<<endl;
    }
    return 0;
}

