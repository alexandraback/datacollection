//
//  main.cpp
//  CodeJam.2013.Q.A
//
//  Created by Maxim Piskunov on 13.04.2013.
//  Copyright (c) 2013 Maxim Piskunov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct test_case {
    vector <string> board;
};

void read(vector <test_case> *tests)
{
    ifstream in("input");
    
    int T;
    in >> T;
    tests->resize(T);
    for (int i = 0; i < T; i++) {
        (*tests)[i].board.resize(4);
        for (int j = 0; j < 4; j++) {
            in >> (*tests)[i].board[j];
        }
    }
    
    in.close();
}

void write(vector <string> *results)
{
    ofstream out("output");
    
    out << "Case #1: " << (*results)[0];
    for (int i = 1; i < results->size(); i++) {
        out << endl << "Case #" << i+1 << ": " << (*results)[i];
    }
    
    out.close();
}

string solve_test (test_case test)
{
    char symbol[2] = {'X', 'O'};
    for (int i = 0; i < 2; i++) {
        string result;
        result.push_back(symbol[i]);
        result += " won";
        
        for (int j = 0; j < 4; j++) {
            bool success = true;
            for (int k = 0; k < 4; k++) {
                if (test.board[j][k] != symbol[i] && test.board[j][k] != 'T') {
                    success = false;
                    break;
                }
            }
            if (success) return result;
        }
        
        for (int j = 0; j < 4; j++) {
            bool success = true;
            for (int k = 0; k < 4; k++) {
                if (test.board[k][j] != symbol[i] && test.board[k][j] != 'T') {
                    success = false;
                    break;
                }
            }
            if (success) return result;
        }
        
        bool success = true;
        for (int j = 0; j < 4; j++) {
            if (test.board[j][j] != symbol[i] && test.board[j][j] != 'T') {
                success = false;
                break;
            }
        }
        if (success) return result;
        
        success = true;
        for (int j = 0; j < 4; j++) {
            if (test.board[j][4-j-1] != symbol[i] && test.board[j][4-j-1] != 'T') {
                success = false;
                break;
            }
        }
        if (success) return result;
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (test.board[i][j] == '.') return "Game has not completed";
        }
    }
    return "Draw";
}

void solve(vector <test_case> *tests, vector <string> *results)
{
    results->resize(tests->size());
    for (int i = 0; i < tests->size(); i++) (*results)[i] = solve_test((*tests)[i]);
}

int main(int argc, const char * argv[])
{
    vector <test_case> tests;
    vector <string> results;
    
    read(&tests);
    solve(&tests, &results);
    write(&results);
    
    return 0;
}