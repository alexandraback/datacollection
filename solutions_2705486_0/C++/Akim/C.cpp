#include <cstdio>
using namespace std;
#include <iostream>
#include <string>
#include <vector>

vector<string> dict;

const int INF = 1000000;

const int MAXM = 521196 + 10;
int a[MAXM][15][5], b[MAXM][15][5];
int total_moves;

void make_move(char ch) {
    ++total_moves;
    int m = dict.size();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < (int)dict[i].size(); ++j)
            for (int k = 0; k < 5; ++k)
                b[i][j][k] = INF; 
    int opt_new_word[5];
    for (int r = 0; r < 5; ++r) opt_new_word[r] = INF;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < (int)dict[i].size(); ++j)
            for (int k = 0; k < 5; ++k)
                if (a[i][j][k] < INF) {
                    char expected = dict[i][j];
                    if (j == ((int)dict[i].size()) - 1) {
                        if (ch == expected || k == 4) {
                            int kk = (ch == expected ? min(k + 1, 4) : 0);
                            opt_new_word[kk] = min(opt_new_word[kk], a[i][j][k] + (ch != expected ? 1 : 0));
                        }
                    } else {
                        if (ch == expected || k == 4) {
                            int ii = i;
                            int jj = j + 1;
                            int kk = (ch == expected ? min(k + 1, 4) : 0);
                            b[ii][jj][kk] = min(b[ii][jj][kk], a[i][j][k] + (ch != expected ? 1 : 0));
                        }
                    }
                }
    for (int i = 0; i < m; ++i)
        for (int k = 0; k < 5; ++k)
            b[i][0][k] = min(b[i][0][k], opt_new_word[k]);
}


void solve(int testnum) {
    cerr << testnum << endl;
    string s;
    cin >> s;
    int m = dict.size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (int)dict[i].size(); ++j) {
            for (int k = 0; k < 5; ++k)
                a[i][j][k] = (j == 0 ? 0 : INF);
        }
    }
    for (int x = 0; x < (int)s.size(); ++x) {
        make_move(s[x]);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < (int)dict[i].size(); ++j)
                for (int k = 0; k < 5; ++k)
                    a[i][j][k] = b[i][j][k];
    }
    int ANS = INF;
    for (int i = 0; i < m; ++i)
        for (int k = 0; k < 5; ++k)
            ANS = min(ANS, a[i][0][k]);
    cout << "Case #" << testnum << ": " << ANS << endl;
}


void prepare() {
    FILE* f = fopen("dict.txt", "rb");
    char buf[100000];
    dict.clear();
    while (fscanf(f, "%s", buf) != -1) {
        dict.push_back(string(buf));
    }
    fclose(f);
}

int main() {
    prepare();
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve(i + 1);
    cerr << "Total moves: " << total_moves << endl;
    return 0;

}

