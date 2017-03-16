#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, S, p;
int cnt_no, cnt_yes, cnt_maybe;

int getMax(int total) {
    switch (total % 3) {
        case 0: return total / 3;
        case 2: return (total + 1) / 3;
        case 1: return (total + 2) / 3;
    }
}

int getMaxS(int total) {
    switch (total) {
        case 30:
        case 29:
            return 10;
        case 0:
            return 0;
    }

    switch (total % 3) {
        case 1: return (total + 2) / 3;
        case 0: return (total + 3) / 3;
        case 2: return (total + 4) / 3;
    }
}

int run() {
    cin >> N >> S >> p;
    //cout << N << S << p;
    cnt_no = cnt_yes = cnt_maybe = 0;

    int total, max_no, max_s;
    for (int i = 0; i < N; ++i) {
        cin >> total;
        max_no = getMax(total);
        max_s = getMaxS(total);
        //cout << max_no << " " << max_s << endl;

        if (max_s < p) cnt_no++;
        else if (max_no >= p) cnt_yes++;
        else cnt_maybe++;
    }
    //cout << cnt_no << " " << cnt_maybe << " " << cnt_yes << endl;

    return cnt_yes + min(S, cnt_maybe);
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

