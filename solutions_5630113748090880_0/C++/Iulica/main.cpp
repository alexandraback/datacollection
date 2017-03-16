//
//  main.cpp
//  codejam
//
//  Created by Iulian Popescu on 16/04/16.
//  Copyright © 2016 Iulian Popescu. All rights reserved.
//

#include <fstream>
#include <deque>
using namespace std;

ifstream fin("/Users/iulian_popescu/Desktop/codejam/codejam/input.in");
ofstream fout("/Users/iulian_popescu/Desktop/codejam/codejam/output.out");

void solve(int t) {
    int n;
    fin >> n;
    int frecv[3000];
    for (int i = 0; i < 2800; i++) {
        frecv[i] = 0;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            fin >> x;
            frecv[x]++;
        }
    }
    fout << "Case #" << t << ": ";
    for (int i = 0; i < 2800; i++) {
        if (frecv[i] % 2 != 0) {
            fout << i << " ";
        }
    }
    fout << "\n";
}

int main(int argc, const char * argv[]) {
    int t;
    fin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}
