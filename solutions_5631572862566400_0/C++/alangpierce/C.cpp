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

string problem = "/Users/apierce/codejam16/codejam/Round1A/C-small-attempt0";
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

// Returns the group_id and length for each value;
pair<int, int> max_len_starting_at(vector<pair<int, int>> &memo, vector<int> &friendships, int index) {
    if (memo[index].first != -1) {
        return memo[index];
    }

    int f = friendships[index];
    if (friendships[f] == index) {
        memo[index] = make_pair(index, 0);
        return memo[index];
    }

    memo[index] = make_pair(-2, -2);
    pair<int, int> friend_result = max_len_starting_at(memo, friendships, f);
    if (friend_result.first != -2) {
        memo[index] = make_pair(friend_result.first, friend_result.second + 1);
    }
    return memo[index];
}

string handle_case() {
    int n = next_int();
    vector<int> friendships = next_int_vector(n);
    for (int i = 0; i < friendships.size(); i++) {
        friendships[i]--;
    }

    int longest_cycle = 0;

    for (int start = 0; start < friendships.size(); start++) {
        vector<bool> seen(friendships.size(), false);
        int len = 0;
        int val = start;
        seen[val] = true;
        while (true) {
            val = friendships[val];
            len++;
            if (val == start) {
                longest_cycle = max(longest_cycle, len);
                break;
            }
            if (seen[val]) {
                break;
            }
            seen[val] = true;
        }
    }

//    map<int, int> max_length_by_group;
    vector<pair<int, int>> memo(n, make_pair(-1, -1));

//    for (int i = 0; i < friendships.size(); i++) {
//        pair<int, int> res = max_len_starting_at(memo, friendships, i);
//        if (res.first >= 0) {
//            max_length_by_group[res.first] = max(max_length_by_group[res.first], res.second);
//        }
//    }

//    int best_pairs_score = 0;
//    for (auto best : max_length_by_group) {
//        best_pairs_score += 2 + best.second;
//    }


    set<int> groups;
    for (int i = 0; i < friendships.size(); i++) {
        pair<int, int> res = max_len_starting_at(memo, friendships, i);
        if (res.first >= 0) {
            groups.insert(res.first);
        }
    }

    int best_pairs_score = 0;
    for (int group_id : groups) {
        best_pairs_score += 1;
        vector<int> scores;
        for (int i = 0; i < memo.size(); i++) {
            if (memo[i].first == group_id) {
                scores.push_back(memo[i].second);
            }
        }
        sort(scores.begin(), scores.end());

        if (scores.size() > 0) {
            best_pairs_score += scores.back();
        }
    }

    stringstream ss;
    ss << max(longest_cycle, best_pairs_score);
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