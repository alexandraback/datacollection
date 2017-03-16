#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>

using namespace std;

int A, B;

int numlen(int n) {
    if (n >= 1000000) return 7;
    else if (n >= 100000) return 6;
    else if (n >= 10000) return 5;
    else if (n >= 1000) return 4;
    else if (n >= 100) return 3;
    else if (n >= 10) return 2;
    else return 1;
}

int pow10(int len) {
    switch (len) {
        case 1: return 1;
        case 2: return 10;
        case 3: return 100;
        case 4: return 1000;
        case 5: return 10000;
        case 6: return 100000;
        case 7: return 1000000;
    }
}

int shift(int n, int len) {
    int digit = n % 10;
    return n / 10 + digit * pow10(len);
}

bool filter(int n) {
    char num[10];
    sprintf(num, "%d", n);
    for (int i = 1, N = strlen(num); i < N; ++i) {
        if (num[i] != '0' && num[i] < num[0]) return false;
    }
    return true;
}

// C(n, 2)
int C(int n) {
    if (n == 1) return 0;
    else return n * (n - 1) / 2;
}

int recycle(int n) {
    int len = numlen(n);
    int num = n;

    set<int> sol;
    for (int i = 1; i < len; ++i) {
        num = shift(num, len);
        // cannot start from 0.
        if (numlen(num) == len && n < num && num <= B)
            sol.insert(num);
    }

    //for (set<int>::iterator p = sol.begin(); p != sol.end(); ++p)
    //    cout << " " << *p << endl;

    int sol_num = sol.size();
    //cout << "  =>" << sol_num <<endl;

    return sol_num;
}

int run() {
    cin >> A >> B;

    int cnt = 0;
    for (int n = A; n <= B; ++n) {
        //cout << n << ":" << endl;

        cnt += recycle(n);
    }
    return cnt;
}

int main() {
    int caseN;
    cin >> caseN;

    for (int t = 0; t < caseN; ++t) {
        int num = run();
        printf("Case #%d: %d\n", t + 1, num);
    }

    return 0;
}

