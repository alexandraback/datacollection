#include <cstring>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAXL = 20;

int L;
char C[MAXL + 1], J[MAXL + 1];

long long mabs(long long a) {
    return (a >= 0) ? a : -a;
}

void check(int L, char C[], char J[], long long& resC, long long& resJ, bool swap)
{
    long long Ct = 0, Jt = 0;
    for (int i = 0; i < L; ++i) {
        Ct = Ct*10 + (C[i]-'0');
        Jt = Jt*10 + (J[i]-'0');
    }

    if (mabs(Ct-Jt) > mabs(resC-resJ)) return;
    if (mabs(Ct-Jt) < mabs(resC-resJ)) { resC = Ct; resJ = Jt; return; }

    if (!swap && (Ct < resC || (Ct == resC && Jt < resJ))) {
        resC = Ct; resJ = Jt; return;
    }

    if (swap && (Jt < resJ || (Jt == resJ && Ct < resC))) {
        resC = Ct; resJ = Jt; return;
    }
}

void calc(int L, char C[], char J[], long long& resC, long long& resJ, bool swap)
{
    char Ct[MAXL + 1], Jt[MAXL + 1];
    Ct[L] = Jt[L] = 0;

    for (int l_eq = 0; l_eq <= L; ++l_eq) {
        if (l_eq > 0) {
            if (C[l_eq-1] != '?' && J[l_eq-1] != '?' && C[l_eq-1] != J[l_eq-1])
                break;

            if (C[l_eq-1] == '?' && J[l_eq-1] == '?') {
                Ct[l_eq-1] = Jt[l_eq-1] = '0';
            } else if (C[l_eq-1] == '?') {
                Ct[l_eq-1] = Jt[l_eq-1] = J[l_eq-1];
            } else if (J[l_eq-1] == '?') {
                Ct[l_eq-1] = Jt[l_eq-1] = C[l_eq-1];
            } else {
                Ct[l_eq-1] = Jt[l_eq-1] = J[l_eq-1];
            }
        }

        if (l_eq < L) {
            if (C[l_eq] != '?' && J[l_eq] != '?' && C[l_eq] >= J[l_eq])
                continue;

            if (C[l_eq] == '9' || J[l_eq] == '0')
                continue;

            if (C[l_eq] == '?' && J[l_eq] == '?') {
                Ct[l_eq] = '0';
                Jt[l_eq] = '1';
            } else if (C[l_eq] == '?') {
                Ct[l_eq] = J[l_eq] - 1;
                Jt[l_eq] = J[l_eq];
            } else if (J[l_eq] == '?') {
                Ct[l_eq] = C[l_eq];
                Jt[l_eq] = C[l_eq] + 1;
            } else {
                Ct[l_eq] = C[l_eq];
                Jt[l_eq] = J[l_eq];
            }
        }

        for (int i = l_eq+1; i < L; ++i) {
            if (C[i] == '?') Ct[i] = '9'; else Ct[i] = C[i];
            if (J[i] == '?') Jt[i] = '0'; else Jt[i] = J[i];
        }

        check(L, Ct, Jt, resC, resJ, swap);
    }
}

void print_pad(int L, long long a) {
    char tmp[MAXL + 1];
    sprintf(tmp, "%lld", a);
    int M = strlen(tmp);
    for (int i = 0; i < L-M; ++i) printf("0");
    printf("%s", tmp);
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%s%s", C, J);
        L = strlen(C);

        long long resC = -1, resJ = 1000000000000000000LL;

        calc(L, C, J, resC, resJ, false);
        calc(L, J, C, resJ, resC, true);

        printf("Case #%d: ", t+1);
        print_pad(L, resC);
        printf(" ");
        print_pad(L, resJ);
        printf("\n");
    }

    return 0;
}
