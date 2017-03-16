#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <utility>


using namespace std;

vector<int> find_the_missing(vector<vector<int> > lists) {
    unordered_map<int, int> heights;
    for (auto list : lists) {
        for (auto h : list) {
            if (heights.find(h) != heights.end()) {
                ++heights[h];
            }
            else {
                heights[h] = 1;
            }
//            cout << h << " " << heights[h] << endl;
        }
    }
    vector<int> missing;
    for (auto h : heights) {
//        cout << h.first << " " << h.second << endl;
        if (h.second % 2 == 1) {
            missing.push_back(h.first);
        }
    }
    sort(missing.begin(), missing.end());
    return missing;
}

int main(int argc, char **argv) {
    fstream input("/Users/garygaojun/Google Drive/Documents/codejam/rank-and-file/rank-and-file.in", ios_base::in);
    fstream output("/Users/garygaojun/Google Drive/Documents/codejam/rank-and-file/rank-and-file.out", ios_base::out);
    if (!input.is_open()) {
        cout << "fail to open input file" << endl;
        return -1;
    }
    int lines;
    input >> lines;
    for (int k = 1; k <= lines; ++k) {
        vector<vector<int>> lists;
        int n ;
        input >> n;
        vector<int> list;
        for (int i = 0; i < 2 * n - 1; ++i) {
            list.clear();
            for (int j = 0; j < n; ++j) {
                int h;
                input >> h;
                list.push_back(h);
            }
            lists.push_back(list);
        }
        auto missing = find_the_missing(lists);
        output << "Case #" << k << ": ";
        for (int i = 0; i < n; ++i) {
            output << missing[i] << " ";
        }
        output << endl;
    }
    return 0;
}