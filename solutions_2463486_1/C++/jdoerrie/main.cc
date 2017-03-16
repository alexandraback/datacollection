#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

typedef long long LL;

bool isPali(LL n) {
    char buf[20];
    sprintf(buf, "%lld", n);
    int len = strlen(buf);
    for (int i = 0; i < len/2; ++i) {
        if (buf[i] != buf[len-i-1]) {
            return false;
        }
    }
    return true;
}

void plusOne(char *str, int i) {
    str[i] += 1;
    if (str[i] > '9' && i != 0) {
        str[i] = '0';
        plusOne(str, i-1);
    }
}

void nextPali (char *num) {
    int N = strlen(num);

    plusOne(num, N-1);
    if (num[0] == ':') {
        num[0] = '0';
        num[N-1] = '1';
        for (int i = N; i > 0; --i) {
            num[i] = num[i-1];
        }
        num[0] = '1';
        return;
    }

    for (int i = 0; i < N / 2; i++) {
        int j = N - i - 1;
        while (num[i] != num[j]) {
            plusOne(num, j);
        }
    }
}

bool isSquare(LL n) {
    LL sq = (LL) sqrt(n);
    return sq*sq == n;
}


LL nextPali(LL n) {
    char buf[20];
    sprintf(buf, "%lld", n);
    nextPali(buf);
    sscanf(buf, "%lld", &n);
    return n;
}

int main(int argc, char const *argv[]) {
    std::vector<LL> fair;
    for (LL i = 1; i <= 10000000; i = nextPali(i)) {
        LL sq = i*i;
        if (isPali(sq)) {
            fair.push_back(sq);
        }
    }

    int cas = 0, T;
    LL A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &A, &B);
        std::vector<LL>::iterator low,up;
        low = std::lower_bound (fair.begin(), fair.end(), A);
        up  = std::upper_bound (fair.begin(), fair.end(), B);
        printf("Case #%d: %ld\n", ++cas, up - low);
    }
    return 0;
}