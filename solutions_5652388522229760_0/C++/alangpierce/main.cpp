#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <sstream>

using namespace std;

string problem = "qual/A-small-attempt0";
FILE *infile;
FILE *outfile;

typedef long long lld;

lld next_lld() {
    lld result = 0;
    fscanf(infile, "%lld", &result);
    return result;
}

lld answers[1000001];

string handle_case() {
    lld num = next_lld();
    if (num == 0) {
        return "INSOMNIA";
    }
    stringstream ss;
    ss << answers[num];
    return ss.str();
}

lld get_answer(lld n) {
    bool seen[10];
    for (int i = 0; i < 10; i++) {
        seen[i] = false;
    }
    int num_seen = 0;

    for (lld val = n;; val += n) {
        lld tmp = val;
        while (tmp) {
            int digit = (int)(tmp % 10);
            if (!seen[digit]) {
                seen[digit] = true;
                num_seen++;
            }
            tmp /= 10;
        }

        if (num_seen == 10) {
            return val;
        }
    }
}

void populate_answers() {
    for (lld i = 1; i <= 1000000; i++) {
        answers[i] = get_answer(i);
    }
}

int main() {
    populate_answers();

    string infilename = problem + ".in";
    string outfilename = problem + ".out";
    infile = fopen(infilename.c_str(), "r");
    outfile = fopen(outfilename.c_str(), "w");

    lld n_cases = next_lld();
    for (lld case_num = 1; case_num <= n_cases; ++case_num) {
        string result = handle_case();
        printf("Case #%lld: %s\n", case_num, result.c_str());
        fprintf(outfile, "Case #%lld: %s\n", case_num, result.c_str());
    }
    return 0;
}