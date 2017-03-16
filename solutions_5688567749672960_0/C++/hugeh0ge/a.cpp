#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int T;

long long int pow10(int d) {
    long long int ret = 1;
    for (int i=0; i<d; i++) ret *= 10;
    return ret;
}

long long int calc(int dig) {
    return pow10(dig/2) + pow10(dig-dig/2) - 1;
}

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        char nstr[16];
        char reversed[16] = "0";
        int digit;
        long long int ans = 0;
        int require = 0;
        int require2 = 0;

        scanf(" %s", nstr);
        digit = strlen(nstr);
        if (nstr[digit-1] == '0') {
            require2 = 1;
            for (int i=digit-1; i>=0; i--) {
                if (nstr[i] == '0') {
                    nstr[i] = '9';
                } else {
                    nstr[i]--;
                    break;
                }
            }

            if (nstr[0] == '0') {
                digit--;
                for (int i=0; i<digit; i++) {
                    nstr[i] = nstr[i+1];
                }
                nstr[digit] = '\0';
            }
        }

        for (int i=1; i<=digit-1; i++) {
            ans += calc(i);
        }

        for (int i=0; i<digit/2; i++) {
            reversed[i] = nstr[digit/2-i-1];
        }
        ans += atoll(reversed) + atoll(nstr+digit/2);
        if (atoll(reversed) == 1) require = 1;
        printf("Case #%d: %lld\n", Case, ans-require+require2);
    }
}
