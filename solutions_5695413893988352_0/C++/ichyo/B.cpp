// Template {{{
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

#ifdef LOCAL
#include "contest.h"
#else
#define dump(x) 
#endif

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}
//}}}

int main(){
    iostream_init();
    int T;
    cin >> T;
    string A, B;
    REP(testnum, T) {
        cout << "Case #" << testnum+1 << ": ";
        cin >> A >> B;

        int n = A.size();
        LL ans = LLONG_MAX;
        string ansA, ansB;

        auto calc = [&](char c1, char c2) {
            string a = A;
            string b = B;
            for(char& c : a) if(c == '?') { c = c1; }
            for(char& c : b) if(c == '?') { c = c2; }
            LL tmp = abs(stoll(a) - stoll(b));
            if(tmp < ans) {
                ans = tmp;
                ansA = a;
                ansB = b;
            }
            if(tmp == ans && stoll(a) < stoll(ansA)) {
                ans = tmp;
                ansA = a;
                ansB = b;
            }
            if(tmp == ans && stoll(a) == stoll(ansA) && stoll(b) < stoll(ansB)) {
                ans = tmp;
                ansA = a;
                ansB = b;
            }
        };

        auto calcAB = [&]{
            calc('0', '9');
        };

        auto calcBA = [&]{
            calc('9', '0');
        };

        REP(i, n) {
            bool AQ = A[i] == '?';
            bool BQ = B[i] == '?';
            if(AQ && BQ) {
                A[i] = '1'; B[i] = '0';
                calcAB();
                A[i] = '0'; B[i] = '1';
                calcBA();
                A[i] = B[i] = '0';
            } else if(AQ) {
                if(B[i] != '9') {
                    A[i] = B[i] + 1;
                    calcAB();
                }
                if(B[i] != '0') {
                    A[i] = B[i] - 1;
                    calcBA();
                }
                A[i] = B[i];
            } else if(BQ) {
                if(A[i] != '0') {
                    B[i] = A[i] - 1;
                    calcAB();
                }
                if(A[i] != '9') {
                    B[i] = A[i] + 1;
                    calcBA();
                }
                B[i] = A[i];
            } else if(A[i] > B[i]) {
                calcAB();
            } else if(A[i] < B[i]) {
                calcBA();
            } else {
            }

            calc('0', '0');
        }
        cout << ansA << " " << ansB << endl;
    }
    return 0;
}

