#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <float.h>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

int N;
int M;

vector<int> V[50];

string solve(vector<int>& zip) {
    stringstream ret;
    int low = 100000;
    int n = -1;
    for (int i = 0; i < N; i++) {
        if (zip[i] < low) {
            low = zip[i];
            n = i;
        }
    }

    bool done[50] = {};
    int from[50];
    for (int i = 0; i < N; i++) {
        from[i] = -1;
    }
    queue<int> q;
    q.push(n);
    from[n] = -1;
    while(!q.empty()) {
        int city = q.front();
        if (!done[city]) {
            done[city] = true;
            ret << zip[city];
        }
        q.pop();
        int next = -1;
        int ll = 100000;
        for (int i = 0; i < V[city].size(); i++) {
            if (done[V[city][i]]) {
                continue;
            }
            if (zip[V[city][i]] < ll) {
                ll = zip[V[city][i]];
                next = V[city][i];
            }
        }
        if (next != -1) {
            q.push(next);
            from[next] =  city;
        } else {
            if (count(done, done + N, false) != 0) {
                q.push(from[city]);
            }
        }
    }
    return ret.str();
}

map<pair<int, int>, bool> ma;

int back[8];
bool edge[8][8];
bool done[8][8];

string solve1(vector<int>& zip) {
    string ret;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        v.push_back(i);
    }
    do {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                back[i] = -1;
                done[i][j] = false;
            }
        }
        int city = v[0];
        bool ok = true;
        for (int i = 1; i < N; ) {
            int next = v[i];
            if (edge[city][next]) {
                back[next] = city;
                city = next;
                i++;
            } else if (back[city] != -1) {
                city = back[city];
                continue;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            stringstream s;
            for (int i = 0; i < N; i++) {
                s << zip[v[i]];
            }
            string val = s.str();
            if (ret.size() == 0) {
                ret = val;
            } else {
                if (val < ret) {
                    ret = val;
                }
            }
        }
    } while(next_permutation(v.begin(), v.end()));
    return ret;
}
//#define LARGE

int main() {

#ifndef LARGE
    ifstream in("C-small-attempt0.in");
    ofstream out("C-small-attempt0.out");
#else
    ifstream in("C-large-attempt.in");
    ofstream out("C-large-attempt.out");
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> N >> M;
        vector<int> zip(N);
        for (int n = 0; n < N; n++) {
            in >> zip[n];
            V[n].clear();
        }
        ma.clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                edge[i][j] = false;
            }
        }
        for (int m = 0; m < M; m++) {
            int from, to; in >> from >> to;
            from--;
            to--;
            edge[from][to] = true;
            edge[to][from] = true;
            V[from].push_back(to);
            V[to].push_back(from);
        }
        string ret = solve1(zip);
        out << "Case #" << t + 1 << ": " << ret << endl;
    }
    getchar();
    return 0;
}
