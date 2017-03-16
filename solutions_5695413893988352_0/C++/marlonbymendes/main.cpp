#include <bits/stdc++.h>

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debugat(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;

using namespace std;

string A, B;
int n;

int mina, minb, lastDiff;
string s1, s2;

void printD(int d) {
    string ds = to_string(d);
    cout << string(n - (int) ds.size(), '0') << ds;
}

void bt(int posa, int posb) {
//    printf("%d %d", posa, posb);
    if(posa == (n - 1) and posa == posb) {
        int nextA = atoi(A.c_str()), nextB = atoi(B.c_str());
        int nextDiff = abs(nextA - nextB);
        if(nextDiff < lastDiff) {
            mina = nextA;
            minb = nextB;
            lastDiff = nextDiff;
        }
        else if(nextDiff == lastDiff) {
            if(nextA == mina and nextB < minb) {
                mina = nextA;
                minb = nextB;
            }
            else if(nextA < mina) {
                mina = nextA;
                minb = nextB;
            }
        }
        return;
    }

    if(posa < (n - 1)) {
        ++posa;
        if(s1[posa] == '?') {
            for(char c = '0'; c <= '9'; ++c) {
                A[posa] = c;
                bt(posa, posb);
            }
        }
        else {
            A[posa] = s1[posa];
            bt(posa, posb);
        }
    }
    if(posb < (n - 1)) {
        ++posb;
        if(s2[posb] == '?') {
            for(char c = '0'; c <= '9'; ++c) {
                B[posb] = c;
                bt(posa, posb);
            }
        }
        else {
            B[posb] = s2[posb];
            bt(posa, posb);
        }
    }
}

int main() {
    int tests;
    cin >> tests;

    for(int t = 1; t <= tests; ++t) {
        cin >> s1 >> s2;

        A = s1;
        B = s2;
        n = s1.size();

        mina = lastDiff = (1 << 15);
        minb = 0;

        bt(-1, -1);

        printf("Case #%d: ", t);
        printD(mina);
        printf(" ");
        printD(minb);
        puts("");
    }

    return 0;
}
