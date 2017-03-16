#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

string problem = "/Users/apierce/codejam16/codejam/Round1A/A-small-attempt0";
FILE *infile;
FILE *outfile;

typedef long long lld;

lld next_lld() {
    lld result = 0;
    fscanf(infile, "%lld", &result);
    return result;
}

string next_string() {
    char result[3000];
    fscanf(infile, "%s", result);
    return string(result);
}

string handle_case() {
    string s = next_string();

    string result = "";

    for (char c : s) {
        string next1 = c + result;
        string next2 = result + c;
        if (next1 > next2) {
            result = next1;
        } else {
            result = next2;
        }
    }

    stringstream ss;
    ss << result;
    return ss.str();
}

int main() {
    string infilename = problem + ".in";
    string outfilename = problem + ".out";
    infile = fopen(infilename.c_str(), "r");
    if (infile == nullptr) {
        printf("File %s not found!", infilename.c_str());
        return 1;
    }
    outfile = fopen(outfilename.c_str(), "w");

    lld n_cases = next_lld();
    for (lld case_num = 1; case_num <= n_cases; ++case_num) {
        string result = handle_case();
        printf("Case #%lld: %s\n", case_num, result.c_str());
        fprintf(outfile, "Case #%lld: %s\n", case_num, result.c_str());
    }
    return 0;
}