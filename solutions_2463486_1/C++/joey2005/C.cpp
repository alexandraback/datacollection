#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

const int maxn = 10000001;

int sum[maxn];
int arrays[128];

bool isPalindrome(long long num) {
    int length = 0;
    while (num > 0) {
        arrays[length++] = num % 10;
        num /= 10;
    }
    for (int l = 0, r = length - 1; l < r; ++l, --r) {
        if (arrays[l] != arrays[r]) {
            return false;
        }
    }
    return true;
}

void preprocess() {
    sum[1] = 1;
    sum[2] = 1;
    sum[3] = 1;

    int base = 1;
    for (int length = 1; length <= 3; ++length) {
        //even
        for (int leftPart = base; leftPart < base * 10; ++leftPart) {
            int rightPart = 0;
            for (int x = leftPart; x > 0; x /= 10) {
                rightPart = rightPart * 10 + x % 10;
            }
            int sqrtnum = leftPart * base * 10 + rightPart;
            //if (length == 1) fprintf(stderr, "%d %d %d\n", sqrtnum, leftPart, rightPart);
            long long sqrnum = (long long)sqrtnum * sqrtnum;
            if (isPalindrome(sqrnum)) {
                sum[sqrtnum] = 1;
            }
        }

        //odd
        for (int leftPart = base; leftPart < base * 10; ++leftPart) {
            int rightPart = 0;
            for (int x = leftPart; x > 0; x /= 10) {
                rightPart = rightPart * 10 + x % 10;
            }
            for (int mid = 0; mid <= 9; ++mid) {
                int sqrtnum = (leftPart * 10 + mid) * base * 10 + rightPart;
                //if (length == 1) fprintf(stderr, "%d %d %d %d\n", sqrtnum, leftPart, mid, rightPart);
                long long sqrnum = (long long)sqrtnum * sqrtnum;
                if (isPalindrome(sqrnum)) {
                    sum[sqrtnum] = 1;
                }
            }
        }

        
        base *= 10;
    }

    for (int i = 1; i < maxn; ++i) {//if (sum[i]) fprintf(stderr, "%d %I64d\n", i, (long long)i * i);
        sum[i] += sum[i - 1];
    }
    fprintf(stderr, "%d\n", sum[maxn - 1]);
}

int query(long long r) {
    return sum[(int)sqrt(r + 0.5)];
}

int main() {
    preprocess();

    freopen("C-large-1.in", "r", stdin);
    //freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    
    int testCount;
    scanf("%d", &testCount);
    for (int testID = 1; testID <= testCount; testID++) {
        long long l, r;
        scanf("%I64d%I64d", &l, &r);
        printf("Case #%d: %d\n", testID, query(r) - query(l - 1));
    }
}
