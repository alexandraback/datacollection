#include <stdio.h>

#include <tr1/unordered_set>

using namespace std;

void GetDigit(int x, int *digit, int &dcnt) {
    dcnt = 0;
    while (x) {
        digit[dcnt++] = x%10;
        x /= 10;
    }
}
int GetNumber(int *digit, int dcnt, int idx) {
    int ret = 0;
    for (int i = 0;i < dcnt;i++) {
        ret = 10*ret + digit[(idx+dcnt-i)%dcnt];
    }
    return ret;
}
int main() {
    int cas;
    scanf("%d", &cas);
    int digit[10];
    int dcnt = 0;
    tr1::unordered_set<long long> hset;
    for (int ic = 1;ic <= cas;ic++) {
        hset.clear();
        int a, b;
        scanf("%d%d", &a, &b);
        for (int i = a;i < b;i++) {
            GetDigit(i, digit, dcnt);
            for (int j = 0;j < dcnt-1;j++) {
                int num = GetNumber(digit, dcnt, j);
                if (num > i && num <= b) {
                    long long tmp = (1LL<<32)*i+num;
                    hset.insert(tmp);
                }
            }
        }
        printf("Case #%d: %d\n", ic, hset.size());
    }
    return 0;
}
