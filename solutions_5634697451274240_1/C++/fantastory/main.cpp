#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdint.h>
#include <assert.h>

using namespace std;

string prepath = "..\\2016-B\\";
//string testin = "test";
//string testin = "B-small-attempt0";
//string testin = "B-small-attempt1";
string testin = "B-large";


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
    char buf[1024];

    fgets(buf, 1024, fin);
    printf(" %s\n", buf);

    string ccc = buf;
    std::reverse(ccc.begin(), ccc.end());
    printf(" %s\n", ccc.c_str());
    const char *c = ccc.c_str();
    //skip \n at the begining
    c++;

    int flips = 0;
    char side = '+';
    while (*c == '+' || *c == '-') {
        if (*c != side) {
            //printf("%c != %c flip %d", *c, side, flips);
            flips++;
            if (side == '+') {
                side = '-';
            } else {
                side = '+';
            }
        }
        c++;
    }
    fprintf(fout, " %d\n", flips);
    printf(" %d\n", flips);

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

