//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int t, caseno = 1;
LL rec[39] = {
    1, 2, 3, 11, 22,
    101, 111, 121, 202, 212,
    1001, 1111, 2002, 10001, 10101,
    10201, 11011, 11111, 11211, 20002,
    20102, 100001, 101101, 110011, 111111, 
    200002, 1000001, 1001001, 1002001, 1010101,
    1011101, 1012101, 1100011, 1101011, 1102011,
    1110111, 1111111, 2000002, 2001002,
};
LL a, b, sa, sb, reca, recb, ans;

int main() {
    cin >> t;
    while(t --) {
        reca = 0, recb = 39;
        ans = 0;
        cin >> a >> b;
        sa = sqrt(a), sb = sqrt(b);
        if(sa * sa != a)    sa ++;
        for(int i = 0 ;i < 39; i ++) {
            if(rec[i] >= sa) {
                reca = i;
                break;
            }
        }
        for(int i = 0 ;i < 39; i ++) {
            if(rec[i] > sb) {
                recb = i;
                break;
            }
        }
        ans = recb - reca;
        printf("Case #%d: ", caseno ++);
        cout << ans << endl;
    }
    return 0;
}

