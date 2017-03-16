#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ull;

ull minDiff, scoreA, scoreB;
string bestA, bestB;

ull stringToUll(const string& s) {
    stringstream ss(s);
    ull res;
    ss >> res;
    return res;
}

// unbalance = 1 -> B is greater, -1 -> A is greater
void fill_strings(string A, string B, unsigned int next, int unbalance) {
    if (next == A.length()) {
        ull a = stringToUll(A), b = stringToUll(B);
        if (a < b) swap(a, b);
        if (a - b < minDiff) {
            minDiff = a - b;
            scoreA = a, bestA = A;
            scoreB = b, bestB = B;
        } else if (a - b == minDiff && a < scoreA) {
            scoreA = a, bestA = A;
            scoreB = b, bestB = B;
        }
    } else {
        // Choose next char
        if (A[next] == '?' && B[next] == '?') {
            // Both question marks:
            if (unbalance == 0) {
                A[next] = '0', B[next] = '0';
                fill_strings(A, B, next + 1, 0); // Both 0
                A[next] = '1', B[next] = '0';
                fill_strings(A, B, next + 1, -1); // 1 - 0
                A[next] = '0', B[next] = '1';
                fill_strings(A, B, next + 1, 1); // 0 - 1
                A[next] = '9', B[next] = '0';
                fill_strings(A, B, next + 1, -1); // 9 - 0
                A[next] = '0', B[next] = '9';
                fill_strings(A, B, next + 1, 1); // 0 - 9
            } else if (unbalance == 1) {
                A[next] = '9', B[next] = '0';
                fill_strings(A, B, next + 1, unbalance); // 9 - 0
            } else {
                A[next] = '0', B[next] = '9';
                fill_strings(A, B, next + 1, unbalance); // 0 - 9
            }
        } else if (A[next] == '?') {
            // A is ?
            if (unbalance == 0) {
                A[next] = B[next];
                fill_strings(A, B, next + 1, 0); // Same as B
                A[next] = B[next] < '9' ? B[next] + 1 : '0';
                fill_strings(A, B, next + 1, A[next] < B[next] ? 1 : -1); // B+1
                A[next] = B[next] > '0' ? B[next] - 1 : '9';
                fill_strings(A, B, next + 1, A[next] < B[next] ? 1 : -1); // B-1
            } else if (unbalance == 1) {
                A[next] = '9';
                fill_strings(A, B, next + 1, unbalance);
            } else {
                A[next] = '0';
                fill_strings(A, B, next + 1, unbalance);
            }
        } else if (B[next] == '?') {
            // B is ?
            if (unbalance == 0) {
                B[next] = A[next];
                fill_strings(A, B, next + 1, 0); // Same as A
                B[next] = A[next] < '9' ? A[next] + 1 : '0';
                fill_strings(A, B, next + 1, A[next] < B[next] ? 1 : -1); // A+1
                B[next] = A[next] > '0' ? A[next] - 1 : '9';
                fill_strings(A, B, next + 1, A[next] < B[next] ? 1 : -1); // A-1
            } else if (unbalance == 1) {
                B[next] = '0';
                fill_strings(A, B, next + 1, unbalance);
            } else {
                B[next] = '9';
                fill_strings(A, B, next + 1, unbalance);
            }
        } else {
            // Nothing to pick
            if (unbalance == 0) {
                if (A[next] < B[next]) unbalance = 1;
                else if (A[next] > B[next]) unbalance = -1;
            }
            fill_strings(A, B, next + 1, unbalance);
        }
    }
}

int main(int argc, char *argv[]) {
    ifstream cin("B-large.in");
    ofstream cout("output.txt");
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; caso++) {
       string A, B;
       cin >> A >> B;
       minDiff = ULLONG_MAX;
       fill_strings(A, B, 0, 0);
       cout << "Case #" << caso << ": " << bestA << " " << bestB << endl;
    }
    return 0;
}
