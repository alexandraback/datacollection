#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <sstream>

using namespace std;

string problem = "qual/B-large";
FILE *infile;
FILE *outfile;

typedef long long lld;

lld next_lld() {
    lld result = 0;
    fscanf(infile, "%lld", &result);
    return result;
}

string next_string() {
    char result[1000];
    fscanf(infile, "%s", result);
    return string(result);
}

lld answers[1000001];

string handle_case() {
    string str = next_string();

    int result = 0;
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] != str[i + 1]) {
            result++;
        }
    }
    if (str[str.length() - 1] == '-') {
        result++;
    }

    stringstream ss;
    ss << result;
    return ss.str();
}

int main() {
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