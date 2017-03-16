#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long int64;
typedef vector<int>::iterator it;

const int oo = 0x3f3f3f3f;
const int MAX_N = 21;
const int MAX_CONF = 1 << MAX_N;
const int MAX_KEY = 205;

int N, ReqKey[MAX_N], Keys[MAX_KEY], ContainedKeys[MAX_N][MAX_KEY], Move[MAX_CONF];

void Solve() {
    memset(Move, -1, sizeof(Move));
    Move[0] = 0;
    for (int conf = 1; conf < (1 << N); ++conf) {
        for (int i = 0; i < N; ++i) {
            if (((conf >> i) & 1) == 0) {
                --Keys[ReqKey[i]];
                for (int j = 1; j <= ContainedKeys[i][0]; ++j)
                    ++Keys[ContainedKeys[i][j]];
            }
        }
        for (int i = 0; i < N && Move[conf] == -1; ++i)
            if (((conf >> i) & 1) == 1 && Keys[ReqKey[i]] > 0 && Move[conf ^ (1 << i)] != -1)
                Move[conf] = i;
        for (int i = 0; i < N; ++i) {
            if (((conf >> i) & 1) == 0) {
                ++Keys[ReqKey[i]];
                for (int j = 1; j <= ContainedKeys[i][0]; ++j)
                    --Keys[ContainedKeys[i][j]];
            }
        }
    }
}

void Initialize() {
    memset(ReqKey, 0, sizeof(ReqKey));
    memset(Keys, 0, sizeof(Keys));
    memset(ContainedKeys, 0, sizeof(ContainedKeys));
}

void Read(ifstream &in) {
    int K; in >> K >> N;
    for (; K > 0; --K) {
        int key = 0; in >> key;
        ++Keys[key];
    }
    for (int i = 0; i < N; ++i) {
        in >> ReqKey[i] >> ContainedKeys[i][0];
        for (int j = 1; j <= ContainedKeys[i][0]; ++j)
            in >> ContainedKeys[i][j];
    }
}

void Trace(ofstream &out, const int conf) {
    if (conf == 0)
        return;
    out << Move[conf] + 1 << " ";
    Trace(out, conf ^ (1 << Move[conf]));
}

void Print(ofstream &out, int test) {
    out << "Case #" << test << ": ";
    if (Move[(1 << N) - 1] == -1)
        out << "IMPOSSIBLE";
    else
        Trace(out, (1 << N) - 1);
    out << "\n";
}

int main() {
    ifstream in("input.in");
    ofstream out("output.out");
    int Tests; in >> Tests;
    for (int t = 1; t <= Tests; ++t) {
        Initialize();
        Read(in);
        Solve();
        Print(out, t);
    }
    in.close();
    out.close();
    return 0;
}
