#include <bits/stdc++.h>
#define debug(args...) fprintf(stderr, args)

using namespace std;

int ansA, ansB;
string sA, sB;
int mini;

void f(string a, string b, int idx) {
    if(idx >= a.size() && idx >= b.size()) {
        int numA;
        sscanf(a.c_str(), "%d", &numA);
        int numB;
        sscanf(b.c_str(), "%d", &numB);
        int d = abs(numA - numB);
        if(d < mini) {
            mini = d;
            ansA = numA;
            ansB = numB;
            sA = a;
            sB = b;
        } else if(d == mini) {
            if(numA < ansA) {
                mini = d;
                ansA = numA;
                ansB = numB;
                sA = a;
                sB = b;
            } else if(numA == ansA && numB < ansB) {
                mini = d;
                ansA = numA;
                ansB = numB;
                sA = a;
                sB = b;
            }
        }
        return;
    }
    if(idx < a.size() && a[idx] == '?' && idx < b.size() && b[idx] == '?') {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                string a2 = a, b2 = b;
                a2[idx] = i + '0';
                b2[idx] = j + '0';
                f(a2, b2, idx + 1);
            }
        }
    } else if(idx < a.size() && a[idx] == '?') {
        string a2 = a, b2 = b;
        for(int i = 0; i < 10; i++) {
            a2[idx] = i + '0';
            f(a2, b2, idx + 1);
        }

    } else if(idx < b.size() && b[idx] == '?') {
        string a2 = a, b2 = b;
        for(int i = 0; i < 10; i++) {
            b2[idx] = i + '0';
            f(a2, b2, idx + 1);
        }
    } else {
        f(a, b, idx + 1);
    }
}

void go() {
    string a, b;
    mini = INT_MAX;
    cin >> a >> b;
    f(a, b, 0);
    cout << sA << " " << sB;
}

int main() {
    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; t++) {
        debug("Entering test %d\n", t);
        printf("Case #%d: ", t);
        go();
        printf("\n");
    }
    return 0;
}
