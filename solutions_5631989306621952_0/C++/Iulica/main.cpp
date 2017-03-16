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
    string input;
    fin >> input;
    deque<char> deque;
    deque.push_back(input[0]);
    for (int i = 1; i < input.length(); i++) {
        if (input[i] >= deque.front()) {
            deque.push_front(input[i]);
        } else {
            deque.push_back(input[i]);
        }
    }
    fout << "Case #" << t << ": ";
    while (!deque.empty()) {
        fout << deque.front();
        deque.pop_front();
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
