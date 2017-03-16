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

string problem = "/Users/apierce/codejam16/codejam/Round1B/B-large";
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

pair<string, string> find_solution(string s1, string s2, int split_point, bool s1_wins) {
    bool s1_greater = false;
    bool s2_greater = false;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != '?' && s2[i] != '?') {
            if (s1_greater || s2_greater) {
                continue;
            }
            if (s1[i] > s2[i]) {
                s1_greater = true;
            } else if (s2[i] > s1[i]) {
                s2_greater = true;
            }
            continue;
        } else if (s1[i] == '?' && s2[i] != '?') {
            if (s2_greater) {
                s1[i] = '9';
            } else if (s1_greater) {
                s1[i] = '0';
            } else {
                if (i == split_point) {
                    if (s1_wins && s2[i] < '9') {
                        s1[i] = s2[i] + (char)1;
                        s1_greater = true;
                        continue;
                    } else if (!s1_wins && s2[i] > '0') {
                        s1[i] = s2[i] - (char)1;
                        s2_greater = true;
                        continue;
                    }
                }
                s1[i] = s2[i];
            }
        } else if (s1[i] != '?' && s2[i] == '?') {
            if (s1_greater) {
                s2[i] = '9';
            } else if (s2_greater) {
                s2[i] = '0';
            } else {
                if (i == split_point) {
                    if (!s1_wins && s1[i] < '9') {
                        s2[i] = s1[i] + (char)1;
                        s2_greater = true;
                        continue;
                    } else if (s1_wins && s1[i] > '0') {
                        s2[i] = s1[i] - (char)1;
                        s1_greater = true;
                        continue;
                    }
                }
                s2[i] = s1[i];
            }
        } else {
            if (s1_greater) {
                s1[i] = '0';
                s2[i] = '9';
            } else if (s2_greater) {
                s1[i] = '9';
                s2[i] = '0';
            } else {
                if (i == split_point) {
                    if (s1_wins) {
                        s1[i] = '1';
                        s2[i] = '0';
                        s1_greater = true;
                    } else {
                        s1[i] = '0';
                        s2[i] = '1';
                        s2_greater = true;
                    }
                } else {
                    s1[i] = '0';
                    s2[i] = '0';
                }
            }
        }
    }
    return make_pair(s1, s2);
}

lld getDifference(pair<string, string> p) {
    lld a, b;
    sscanf(p.first.c_str(), "%lld", &a);
    sscanf(p.second.c_str(), "%lld", &b);
    return abs(a - b);
}

string handle_case() {
    string s1 = next_string();
    string s2 = next_string();

    vector<pair<string, string>> results;
    for (int i = 0; i < s1.size(); i++) {
        results.push_back(find_solution(s1, s2, i, true));
        results.push_back(find_solution(s1, s2, i, false));
    }
    results.push_back(find_solution(s1, s2, s1.size() + 1, false));

    lld best_difference = getDifference(results[0]);
    pair<string, string> best_result = results[0];
    for (auto result : results) {
        lld diff = getDifference(result);
        if (diff < best_difference) {
            best_difference = diff;
            best_result = result;
        } else if (diff == best_difference && result < best_result) {
            best_difference = diff;
            best_result = result;
        }
    }

    stringstream ss;
    ss << best_result.first << " " << best_result.second;
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