/*
 * File:   main.cpp
 * Author: Ming Qin
 *
 * Created on February 27, 2015, 8:37 PM
 */

 //#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void as(bool expression, int code = 0) {
    if (!expression) {
        cout << "assertion fail! Code=" << code << endl;
        system("pause");
        exit(-1);
    }
}

//int solve(int n) {
//    int i2;
//    int i = 1;
//    int count = 1;
//    while (i != n) {
//        string s = to_string(i);
//        reverse(s.begin(), s.end());
//        i2 = stoi(s);
//        if (i2 > i && i2 <= n) {
//            i = i2;
//        } else {
//            ++i;
//        }
//        ++count;
//    }
//
//    return count;
//}
vector<int> solve(int n) {
    int i2;
    vector<int> need;
    need.reserve(n + 1);
    for (int i = 0; i <= n; ++i) {
        need.push_back(i);
    }
    for (int i = 2; i <= n; ++i) {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        i2 = stoi(s);
        need[i] = min(need[i], need[i - 1] + 1);
        if (i2 > i && i2 <= n) {
            need[i2] = min(need[i2], need[i] + 1);
        }
    }
    return need;
}

int main() {
    vector<string> strv;
    int TestCase;
    long long n;
    string str;

    fstream infile("i4.in");
    ofstream outfile("out.txt");
    vector<int>ins;
    vector<int>res;

    infile >> TestCase;
    ins.reserve(TestCase);
    res.reserve(TestCase);
    int maxi = 0;

    for (int caseID = 1; caseID <= TestCase; ++caseID) {
        infile >>  n;
        ins.push_back(n);
        if (n > maxi) {
            maxi = n;
        }
    }
    res = solve(maxi);
    for (int caseID = 1; caseID <= TestCase; ++caseID) {
        outfile << "Case #" << caseID << ": ";
        outfile << res[ins[caseID-1]] << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
