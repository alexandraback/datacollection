#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

void solveE(string& c, string& j, int bal) {
    for(int i = 0; i < c.size(); i++) {
        if(c[i] == '?')
            c[i] = (bal == -1? '9' : '0');
        if(j[i] == '?')
            j[i] = (bal == 1? '9' : '0');
    }
}

long long diff(string a, string b) {
    long long A = 0, B = 0;
    for(int i = 0; i < a.size(); i++)
        A = A * 10 + a[i] - '0';
    for(int i = 0; i < b.size(); i++)
        B = B * 10 + b[i] - '0';
    return (A > B)? A - B : B - A;
}

long long backtrack(string& c, string& j, int k = 0, int bal = 0) {
    if(k == c.size())
        return diff(c,j);
    if(bal != 0) {
        solveE(c, j, bal);
        return diff(c, j);
    }
    string cc = c, cj = j;
    if(j[k] != '?') {
        if(c[k] != '?')
            return (j[k] == c[k])? backtrack(c, j, k + 1) : backtrack(c, j, k + 1, (c[k] > j[k])? 1 : -1);

        long long bestSol = 1e18+5;
        string bestC, bestJ;

        c[k] = j[k];
        bestSol = backtrack(c, j, k + 1);
        bestC = c; bestJ = j;

        c = cc; j = cj;
        c[k] = (j[k] - '0' + 1) % 10 + '0';
        long long sol = backtrack(c, j, k + 1, 1);
        if(sol < bestSol ||
            (sol ==  bestSol && bestC > c) ||
            (sol == bestSol && bestC == c && bestJ > j)) {
                bestSol = sol;
                bestC = c;
                bestJ = j;
            }

        c = cc; j = cj;
        c[k] = (j[k] - '0' + 9) % 10 + '0';
        sol = backtrack(c, j, k + 1, -1);
        if(sol < bestSol ||
            (sol ==  bestSol && bestC > c) ||
            (sol == bestSol && bestC == c && bestJ > j)) {
                bestSol = sol;
                bestC = c;
                bestJ = j;
            }

        c = bestC;
        j = bestJ;
        return bestSol;

    }
    else {
        long long bestSol = 1e18+5;
        string bestC, bestJ;

        if(c[k] == '?') {

            j[k] = '0';
            bestSol = backtrack(c, j, k);
            bestC = c; bestJ = j;

            c = cc; j = cj;
            j[k] = '1';
            long long sol = backtrack(c, j, k);

            if(sol < bestSol ||
            (sol ==  bestSol && bestC > c) ||
            (sol == bestSol && bestC == c && bestJ > j)) {
                bestSol = sol;
                bestC = c;
                bestJ = j;
            }

            c = bestC;
            j = bestJ;
            return bestSol;
        }
        else {
            ///beginning of copy
            j[k] = c[k];
            bestSol = backtrack(c, j, k + 1);
            bestC = c; bestJ = j;

            c = cc; j = cj;
            j[k] = (c[k] - '0' + 1) % 10 + '0';
            long long sol = backtrack(c, j, k + 1, -1);
            if(sol < bestSol ||
                (sol ==  bestSol && bestC > c) ||
                (sol == bestSol && bestC == c && bestJ > j)) {
                    bestSol = sol;
                    bestC = c;
                    bestJ = j;
                }

            c = cc; j = cj;
            j[k] = (c[k] - '0' + 9) % 10 + '0';
            sol = backtrack(c, j, k + 1, 1);
            if(sol < bestSol ||
                (sol ==  bestSol && bestC > c) ||
                (sol == bestSol && bestC == c && bestJ > j)) {
                    bestSol = sol;
                    bestC = c;
                    bestJ = j;
                }

            c = bestC;
            j = bestJ;
            return bestSol;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    string c, j;
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++) {
        cin >> c >> j;
        backtrack(c,j);
        cout << "Case #" << cas << ": " << c << " " << j << "\n";
    }
}
