/*
 * Author: fatboy_cw
 * Created Time:  2013/4/13 12:57:28
 * File Name: C.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
typedef long long lint;

lint v[] = {
  0LL
, 1LL
, 2LL
, 3LL
, 11LL
, 22LL
, 101LL
, 111LL
, 121LL
, 202LL
, 212LL
, 1001LL
, 1111LL
, 2002LL
, 10001LL
, 10101LL
, 10201LL
, 11011LL
, 11111LL
, 11211LL
, 20002LL
, 20102LL
, 100001LL
, 101101LL
, 110011LL
, 111111LL
, 200002LL
, 1000001LL
, 1001001LL
, 1002001LL
, 1010101LL
, 1011101LL
, 1012101LL
, 1100011LL
, 1101011LL
, 1102011LL
, 1110111LL
, 1111111LL
, 2000002LL
, 2001002LL
, 10000001LL
, 10011001LL
, 10100101LL
, 10111101LL
, 11000011LL
, 11011011LL
, 11100111LL
, 11111111LL
, 20000002LL
, 100000001LL
, 100010001LL
, 100020001LL
, 100101001LL
, 100111001LL
, 100121001LL
, 101000101LL
, 101010101LL
, 101020101LL
, 101101101LL
, 101111101LL
, 110000011LL
, 110010011LL
, 110020011LL
, 110101011LL
, 110111011LL
, 111000111LL
, 111010111LL
, 111101111LL
, 111111111LL
, -1LL
}; 

vector<lint> vec;

lint t, A, B, ca;

lint solve(lint x) {
    lint l = 0, r = vec.size() - 1, mid, ans = 0;
    while(l <= r) {
        mid = (l + r) / 2;
        if(vec[mid] <= x) {
            ans = mid + 1;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}
        

int main() {
    freopen("C.out", "w", stdout);
    for(int i = 0; ; i++) {
        if(v[i] == -1) break;
        vec.push_back(v[i] * v[i]);
    }
    cin >> t;
    while(t--) {
        cin >> A >> B;
        cout << "Case #" << ++ca << ": " << solve(B) - solve(A - 1) << endl;
    }
    return 0;
}

