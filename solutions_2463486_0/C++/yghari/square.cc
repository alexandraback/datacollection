#include <cstdio>
#include <cmath>
//#include <iostream>

using namespace std;

#define MAXN (10000001)
#define MAXD (14)

typedef unsigned long long ULL;

bool isFSPal[MAXN];
ULL numFSPals[MAXN];

bool isPalindrome(ULL in) {
    int digits[MAXD];
    int dd=0;
    do {
        digits[dd] = (in%10);
        ++dd;
        in /= 10;
    } while (in);

    int numD = dd;
    for (dd=0; dd<=numD/2; ++dd) {
        if (digits[dd] != digits[numD-1-dd]) {
            return false;
        }
    }
    return true;
}

void preprocess() {
    ULL nn;
    //cerr << "IsFSPal: " << endl;
    for (nn=0; nn<=MAXN; ++nn) {
        isFSPal[nn] = isPalindrome(nn) && isPalindrome(nn*nn);
        //cerr << " " << nn << " : " << isFSPal[nn] << endl;
    }
    numFSPals[0] = 1;
    //cerr << "NumFSPals: " << endl;
    for (nn=1; nn<=MAXN; ++nn) {
        numFSPals[nn] = numFSPals[nn-1];
        if (isFSPal[nn]) ++numFSPals[nn];
        //cerr << " " << nn << " : " << numFSPals[nn] << endl;
    }
}

ULL getNumFSPalsUnderAndExcluding(ULL const &A) {
    ULL sqrtA = (ULL)sqrt(A);
    if (sqrtA*sqrtA == A) {
        --sqrtA;
    }
    return (numFSPals[sqrtA]);
}

ULL getNumFSPalsUnderAndIncluding(ULL const &A) {
    ULL sqrtA = (ULL)sqrt(A);
    ULL res = getNumFSPalsUnderAndExcluding(A);
    if (sqrtA*sqrtA == A) {
        if (isFSPal[sqrtA]) ++res;
    }
    return res;
}


void doTest(int tt) {
    ULL A, B;
    scanf("%llu%llu", &A, &B);
    ULL res = (getNumFSPalsUnderAndIncluding(B)-getNumFSPalsUnderAndExcluding(A));
    printf("%llu", res);
}

int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    for (int tt=1; tt<=T; ++tt) {
        printf("Case #%d: ", tt);
        doTest(tt);
        printf("\n");
    }
    return 0;
}

