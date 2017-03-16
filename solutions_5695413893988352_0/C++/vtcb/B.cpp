#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for(int a = b; a < c; a++)

#define dbg(x) cerr << x << endl;
#define _ << ", " << 

typedef unsigned long long ull;
typedef pair<ull, ull> ii;

pair<ull, pair<ull, ull> > tp(ii a) {
    return make_pair(a.first > a.second ? a.first - a.second : a.second - a.first, a);
}

bool cmp(ii a, ii b) {
    return tp(a) < tp(b);
}

int n;
string A, B;
ii ans;
bool first;
void bt(int at = 0, ull a = 0, ull b = 0) {
    if(at == n) {
        if(first || cmp(make_pair(a, b), ans)) {
            ans = make_pair(a, b);
            first = false;
        }
        return;
    }

    fr(i, 0, 10) {
        if(A[at] != '?') {
            i = A[at] - '0';
        }
        fr(j, 0, 10) {   
            if(B[at] != '?') {
                j = B[at] - '0';
            }

            bt(at + 1, a * 10 + i, b * 10 + j);

            if(B[at] != '?') {
                break;
            }
        }
        if(A[at] != '?') {
            break;
        }
    }

/*
    if(a == b) {
        
        if(A[i] == '?' && B[i] == '?') {
        } else if(A[i] == '?') {
        } else if(B[i] == '?') {
            int xb = B[i] - '0';
            int xa = A[i] - '0';
        } else {
            int xa = A[i] - '0';
            int xb = B[i] - '0';
            bt(at + 1, a * 10 + xa, b * 10 + xb);
        }
        
    } else {
        if(a > b) {
            int xa = A[at] == '?' : 0 : A[at] - '0';
            int xb = B[at] == '?' : 9 : B[at] - '0';
            bt(at + 1, a * 10 + xa, b * 10 + xb);
        } else {
            int xa = A[at] == '?' : 9 : A[at] - '0';
            int xb = B[at] == '?' : 0 : B[at] - '0';
            bt(at + 1, a * 10 + xa, b * 10 + xb);
        }
    }
*/
}

int main() {
    ios_base::sync_with_stdio(false);

    int T;

    cin >> T;

    fr(cas, 1, T+1) {
        cin >> A >> B;

        n = A.length();

        first = true;
        bt();

        cout << "Case #" << cas << ": ";
        cout << setw(n) << setfill('0') << ans.first << " ";
        cout << setw(n) << setfill('0') << ans.second << "\n";
    }

    return 0;
}
