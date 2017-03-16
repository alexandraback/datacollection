#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <sstream>
#include <set>
#include <map>

using namespace std;

string problem = "/Users/apierce/codejam16/codejam/Round1B/A-small-attempt1";
FILE *infile;
FILE *outfile;

typedef long long lld;

lld next_lld() {
    lld result = 0;
    fscanf(infile, "%lld", &result);
    return result;
}

string next_string() {
    char result[100000];
    fscanf(infile, "%s", result);
    return string(result);
}

int next_int() {
    int result = 0;
    fscanf(infile, "%d", &result);
    return result;
}

vector<int> next_int_vector(int n) {
    vector<int> result(n, -1);
    for (int i = 0; i < n; i++) {
        result[i] = next_int();
    }
    return result;
}

string originalStr;
string str;
vector<int> result;

void handle_number(int num, char uniqueLetter, string fullWord) {
    int num_matches = 0;
    for (char c : str) {
        if (c == uniqueLetter) {
            num_matches++;
        }
    }

    for (char letter_to_remove : fullWord) {
        int num_to_remove = num_matches;
        for (int i = 0; i < str.size() && num_to_remove; i++) {
            if (str[i] == letter_to_remove) {
                str[i] = '_';
                num_to_remove--;
            }
        }
        if (num_to_remove != 0) {
            printf("Crap!\n");
        }
    }

    for (int i = 0; i < num_matches; i++) {
        result.push_back(num);
    }
}

string handle_case() {
    str = next_string();
    originalStr = str;
    result.clear();

    handle_number(0, 'Z', "ZERO");
    handle_number(6, 'X', "SIX");
    handle_number(2, 'W', "TWO");
    handle_number(8, 'G', "EIGHT");
    handle_number(3, 'H', "THREE");
    handle_number(4, 'U', "FOUR");
    handle_number(1, 'O', "ONE");
    handle_number(5, 'F', "FIVE");
    handle_number(7, 'S', "SEVEN");
    handle_number(9, 'I', "NINE");

//    for (int i = 0; i < str.size(); i++) {
//        if (str[i] != '_') {
//            printf("Crap!");
//        }
//    }

    sort(result.begin(), result.end());

    stringstream ss;
    for (int res : result) {
        ss << res;
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