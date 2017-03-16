/// in the name of ALLAH

///#include <bits\stdc++.h>

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <deque>
#include <sstream>
#include <string>
#include <fstream>
#include <utility>
#include <cstring>

#define bits(a) __builtin_popcount(a)
#define ll long long
int dx[] = {1 , -1 , 0 , 0 };
int dy[] = {0 ,  0 , 1 , -1};
const int mod = (int)1e9 + 7;
const int oo = 1<<30;
const ll loo = (ll)1<<60;
const double pi = 3.14159265359;
const int N = (int) 1e6 + 5;

using namespace std;
//#define in cin
//#define out cout
pair<int , pair<int , int> > pr[N];
map<pair<int , int> , int> jp , js , ps;
int main() {
    fstream  in("C-small-attempt2.in" , ios::in);
    fstream out("out.out" , ios::out);
    int t;
    in >> t;
    int j , p , s , k , c;
    for(int q = 1; q <= t; q ++){
        in >> j >> p >> s >> k;
        c = 0;
        out << "Case #" << q << ": ";
        jp.clear();
        js.clear();
        ps.clear();
        bool ok = true;
        while(ok) {
            ok = false;
            for(int ij = 0; ij < j; ij ++) {
                for(int ip = 0; ip < p; ip ++) {
                    for(int is = 0; is < s; is++) {
                        if(jp[make_pair(ij , ip)] == k ||
                           js[make_pair(ij , is)] == k ||
                           ps[make_pair(ip , is)] == k) continue;
                           if(c) {
                            if(pr[c-1].first == ij && pr[c-1].second.first == ip && pr[c-1].second.second == is)
                                continue;
                           }
                           ok = true;
                           jp[make_pair(ij , ip)] ++;
                           js[make_pair(ij , is)] ++;
                           ps[make_pair(ip , is)] ++;
                           pr[c++] = make_pair(ij , make_pair(ip , is));
                    }
                }
            }
        }
        out << c << endl;
        for(int i = 0; i < c; i ++) {
            out << pr[i].first+1 << ' ' << pr[i].second.first+1 << ' ' << pr[i].second.second+1 << endl;
        }

    }
}
