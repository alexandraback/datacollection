#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <sstream>

using namespace std;

string problem = "/Users/apierce/codejam16/codejam/Round1A/B-small-attempt1";
FILE *infile;
FILE *outfile;

typedef long long lld;

lld next_lld() {
    lld result = 0;
    fscanf(infile, "%lld", &result);
    return result;
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

string next_string() {
    char result[1000];
    fscanf(infile, "%s", result);
    return string(result);
}

vector<vector<int>> grid;
vector<vector<int>> lists;

vector<pair<bool, int>> result_pair;

bool try_row(int next_row, int next_col, int lists_index) ;

bool try_col(int next_row, int next_col, int lists_index) ;

bool try_skip_col(int next_row, int next_col, int lists_index) ;

bool try_skip_row(int next_row, int next_col, int lists_index) ;

bool recurse(int next_row, int next_col, int lists_index) {
    if (lists_index == lists.size() && next_row == grid.size() && next_col == grid.size()) {
        return true;
    }

    if (lists_index < lists.size() && next_row < grid.size() && grid[next_row][0] == lists[lists_index][0]) {
        if (try_row(next_row, next_col, lists_index)) {
            return true;
        }
    }
    if (lists_index < lists.size() && next_col < grid.size() && grid[0][next_col] == lists[lists_index][0]) {
        if (try_col(next_row, next_col, lists_index)) {
            return true;
        }
    }
    if (next_row < grid.size()) {
        if (try_skip_row(next_row, next_col, lists_index)) {
            return true;
        }
    }
    if (next_col < grid.size()) {
        if (try_skip_col(next_row, next_col, lists_index)) {
            return true;
        }
    }
    return false;
}

bool try_row(int next_row, int next_col, int lists_index) {
    int unset_col = -1;
    for (int i = 0; i < next_col; i++) {
        if (grid[next_row][i] == -1) {
            unset_col = i;
        } else {
            if (grid[next_row][i] != lists[lists_index][i]) {
                return false;
            }
        }
    }
    if (unset_col != -1) {
        grid[next_row][unset_col] = lists[lists_index][unset_col];
    }
    for (int i = next_col; i < grid.size(); i++) {
        grid[next_row][i] = lists[lists_index][i];
    }

    if (recurse(next_row + 1, next_col, lists_index + 1)) {
        return true;
    }

    if (unset_col != -1) {
        grid[next_row][unset_col] = -1;
    }
    for (int i = next_col; i < grid.size(); i++) {
        grid[next_row][i] = -1;
    }
    return false;
}

bool try_col(int next_row, int next_col, int lists_index) {
    int unset_row = -1;
    for (int i = 0; i < next_row; i++) {
        if (grid[i][next_col] == -1) {
            unset_row = i;
        } else {
            if (grid[i][next_col] != lists[lists_index][i]) {
                return false;
            }
        }
    }
    if (unset_row != -1) {
        grid[unset_row][next_col] = lists[lists_index][unset_row];
    }
    for (int i = next_row; i < grid.size(); i++) {
        grid[i][next_col] = lists[lists_index][i];
    }

    if (recurse(next_row, next_col + 1, lists_index + 1)) {
        return true;
    }

    if (unset_row != -1) {
        grid[unset_row][next_col] = -1;
    }
    for (int i = next_row; i < grid.size(); i++) {
        grid[i][next_col] = -1;
    }
    return false;
}

bool try_skip_row(int next_row, int next_col, int lists_index) {
    result_pair.push_back(make_pair(true, next_row));
    if (recurse(next_row + 1, next_col, lists_index)) {
        return true;
    }
    result_pair.pop_back();
    return false;
}

bool try_skip_col(int next_row, int next_col, int lists_index) {
    result_pair.push_back(make_pair(false, next_col));
    if (recurse(next_row, next_col + 1, lists_index)) {
        return true;
    }
    result_pair.pop_back();
    return false;
}


string handle_case() {
    lists.clear();
    grid.clear();
    int n = next_int();
    for (int i = 0; i < 2*n - 1; i++) {
        lists.push_back(next_int_vector(n));
    }
    sort(lists.begin(), lists.end());
    grid.resize(n, vector<int>(n, -1));

    bool was_reversed = false;
    if (lists[0][0] == lists[1][0]) {

    } else {
        was_reversed = true;
        for (int i = 0; i < lists.size(); i++) {
            reverse(lists[i].begin(), lists[i].end());
            for (int j = 0; j < lists[i].size(); j++) {
                lists[i][j] = -lists[i][j];
            }
        }
        sort(lists.begin(), lists.end());
    }
    for (int i = 0; i < n; i++) {
        grid[0][i] = lists[0][i];
        grid[i][0] = lists[1][i];
    }

    recurse(1, 1, 2);

    bool result_is_row = result_pair.back().first;
    int result_index = result_pair.back().second;
    if (result_index == -1) {
        printf("Crap!!!\n");
    }

    vector<int> result;

    if (result_is_row) {
        for (int i = 0; i < grid.size(); i++) {
            result.push_back(grid[result_index][i]);
        }
    } else {
        for (int i = 0; i < grid.size(); i++) {
            result.push_back(grid[i][result_index]);
        }
    }

    if (was_reversed) {
        reverse(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            result[i] = -result[i];
        }
    }

    stringstream ss;
    for (int val : result) {
        ss << " " << val;
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
        printf("Case #%lld:%s\n", case_num, result.c_str());
        fprintf(outfile, "Case #%lld:%s\n", case_num, result.c_str());
    }
    return 0;
}