#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

const int kMaxN = 1e7 + 1;
int a[kMaxN];

typedef long long int64_t;

bool isPalin(int64_t num) {
    int a[20], end = 0;
    while (num) {
        a[end++] = num % 10;
        num /= 10;
    }
    for (int i = 0, j = end - 1; i <= j; i++, j--) {
        if (a[i] != a[j]) {
            return false;
        }
    }
    return true;
}
bool isFairAndPalin(int num) {
    int64_t tmp = ((int64_t) num) * num;
    return isPalin(num) && isPalin(tmp);
}
void init() {
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < kMaxN; i++) {
        a[i] = a[i - 1] + isFairAndPalin(i);
    }
}

int main(int argc, char *argv[]) {
    init();
    int T;
    scanf("%d", &T);
    int64_t beg, end;

    for(int ncas = 1; ncas <= T; ncas++) {
        cin >> beg >> end;
        printf("Case #%d: ", ncas);
        int64_t qb = sqrt(beg), qe = sqrt(end);
        // cout << "qb :" << qb << " qe: " << qe << endl;
        if (qb * qb != beg) {
            qb += 1;
        }
        // cout << "After: " << "qb :" << qb << "qe: " << qe << endl;
        cout << a[qe] - a[qb - 1] << endl;
    }
    return 0;
}

// (shell-command (format "%s < %s > %s " ts-run-file-name "C-small-attempt1.in" "C-small-attempt1.out"))
// (shell-command (format "%s < %s > %s " ts-run-file-name "C-large.in" "C-large.out"))
