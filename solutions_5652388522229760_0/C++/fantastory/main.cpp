#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdint.h>
#include <assert.h>

using namespace std;

string prepath = "..\\2016-A\\";
//string testin = "test";
string testin = "A-small-attempt0";
//string testin = "A-small-attempt1";
//string testin = "A-large";


int work();
int test();

int main()
{
    test();
    work();
    return 0;
}

int test() {

    printf("tests done\n");
    return 0;
}

int solve(FILE *fin, FILE *fout) {
    uint64_t t;

    fscanf(fin, "%I64u\n", &t);
    printf("%I64u\n", t);

    if (t == 0) {
        fprintf(fout, " INSOMNIA\n");
        return 0;
    }

    int seenDigits[10];
    for (int i = 0; i < 10; ++i) {
        seenDigits[i] = 1;
    }
    int seenC = 0;

    uint64_t current = t;
    while (true) {
        uint64_t currentCopy = current;
        while(currentCopy > 0) {
            int digit = currentCopy%10;
            currentCopy /= 10;
            seenC += seenDigits[digit];
            seenDigits[digit] = 0;
        }

        if (seenC >= 10) break;

        current += t;
    }

    fprintf(fout, " %I64u\n", current);
    printf(" %I64u\n", current);

    return 0;
}

int work () {

    string path = prepath + testin + "_out.in";
    FILE *fout = fopen(path.c_str(), "w");
    if (fout == NULL) {
        printf("can not open out\n");
        exit(0);
    }
    fflush(fout);

    path = prepath + testin + ".in";
    FILE *fin = fopen(path.c_str(), "r");
    if (fin == NULL) {
        printf("can not open in\n");
        exit(0);
    }

    int problemc;
    int ret = fscanf(fin, "%d\n", &problemc);
    if (ret != 1) {
        printf("problemc\n");
        exit(0);
    }
    printf("problemc %d\n", problemc);

    for (int n = 0; n < problemc; ++n) {
        fprintf(fout, "Case #%d:", n+1);
        printf("Case #%d:", n+1);

        solve(fin, fout);
    }

    return 0;
}

