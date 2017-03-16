#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <climits>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <functional>
#include <iterator>
#include <complex>
#include <queue>
#include <cassert>
#include <sstream>
#include <cstdlib>

using namespace std;

double pi = acos((double) -1);

ofstream myfile;

bool start_cell(bool** rc, int r, int c, int x, int y) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x + i >= 0 && x + i < r && y + j >= 0 && y + j < c)
                if (!rc[x + i][y + j]) {
                    return false;
                }
        }
    }

    return true;
}

void print_rc(bool** rc, int r, int c, int start_i, int start_j) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (start_i == i && start_j == j) {
                myfile << 'c';
            }
            else {
                myfile << (rc[i][j] ? '.' : '*');
            }
        }
        myfile << endl;
    }
}

bool get_sum_of_pairs(vector<vector<pair<int, int>>>& memoize, vector<pair<int, int>>& pairs,
        double r, double c, int spaces, int initial_spaces) {
    if (!memoize[spaces].empty()) {
        int extra_r = 0;
        for (int i = 0; i < memoize[spaces].size(); i++)
            extra_r += memoize[spaces][i].first;

        if (extra_r <= r) {
            for (int i = 0; i < memoize[spaces].size(); i++)
                pairs.push_back(memoize[spaces][i]);

            return true;
        }
    }

    memoize[initial_spaces - spaces] = pairs;
    for (int j = c; j >= 2; j--) {
        for (int i = r; i >= (pairs.size() ? 1 : 2); i--) {
            if (i * j < spaces) {
                pairs.push_back(pair<int, int>(i, j));
                /*if (spaces - i * j > initial_spaces) {*/
                    //int gg = 1;
                /*}*/
                if (get_sum_of_pairs(memoize, pairs, r - i, j - 1, spaces - i * j, initial_spaces))
                    return true;
                pairs.pop_back();
            }
            else if (i * j == spaces) {
                pairs.push_back(pair<int, int>(i, j));
                return true;
            }
            else
                continue;
        }
    }

    return false;
}

struct sort_pred {
    bool operator()(const pair<int,int> &left, const pair<int,int> &right) {
        return left.second > right.second;
    }
};

int main() {
    clock_t tStart = clock();
    myfile.open ("output.txt");
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int r, c, m;
        scanf("%d %d %d", &r, &c, &m);
        int spaces = r * c - m;

        vector<pair<int, int>> sum_of_pairs;
        bool possible;
        if (spaces == 0) {
            possible = false;
        }
        else if (spaces == 1) {
            possible = true;
            sum_of_pairs.push_back(pair<int, int>(1, 1));
        }
        else if (r == 1 && c == 1) {
            possible = m != 1;
            sum_of_pairs.push_back(pair<int, int>(1, 1));
        }
        else if (r == 1 || c == 1) {
            possible = true;
            sum_of_pairs.push_back(pair<int, int>(r == 1 ? r : spaces, c == 1 ? c : spaces));
        }
        else {
            vector<vector<pair<int, int>>> memoize = vector<vector<pair<int, int>>>(spaces + 1, vector<pair<int, int>>());
            possible = get_sum_of_pairs(memoize, sum_of_pairs, r, c, spaces, spaces);
        }

        if (!possible)
            myfile << "Case #" << test << ":\nImpossible\n";
        else {
            sort(sum_of_pairs.begin(), sum_of_pairs.end(), sort_pred());

            bool **rc = new bool*[r];
            for (int i = 0; i < r; i++) {
                rc[i] = new bool[c];
                for (int j = 0; j < c; j++) {
                    rc[i][j] = 0;
                }
            }

            int x_start = 0, x, y;
            for (int p = 0; p < sum_of_pairs.size(); p++) {
                x = sum_of_pairs[p].first; y = sum_of_pairs[p].second;
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        rc[x_start + i][j] = 1;
                    }
                }
                x_start += x;
            }

            int s_i = -1, s_j = -1;
            for (int i = 0; i < r && s_i == -1; i++) {
                for (int j = 0; j < c && s_j == -1; j++) {
                    if (spaces == 1 || start_cell(rc, r, c, i, j)) {
                        s_i = i, s_j = j;
                    }
                }
            }

            if (s_i == -1 && s_j == -1)
                myfile << "Case #" << test << ":\nImpossible\n";
            else {
                myfile << "Case #" << test << ":\n";
                print_rc(rc, r, c, s_i, s_j);
            }
        }
    }
    myfile.close();

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
