#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <sstream>

using namespace std;

string problem = "/Users/apierce/codejam16/codejam/qual/D-large";
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

string handle_case() {
    lld base = next_lld();
    lld length = next_lld();
    lld max_allowed = next_lld();

    vector<lld> results;

    for (int i = 0; i < base; i++) {
        if (i % length == 0) {
            results.push_back(0);
        }
        lld &lastVal = results[results.size() - 1];
        lastVal *= base;
        lastVal += i;
    }

    if (results.size() > max_allowed) {
        return "IMPOSSIBLE";
    }

    stringstream ss;
    for (int i = 0; i < results.size(); i++) {
        if (i != 0) {
            ss << " ";
        }
        ss << results[i] + 1;
    }
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