#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cctype>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

#define pb push_back
#define FOR(i, N) for (int i = 0; i < N; i++)
#define FOR_1(i, N) for (int i = 1; i <= N; i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define pii pair<int, int>
#define sz size()

typedef long long ll;
typedef unsigned long long ull;

const int null = 0;
const int INF = numeric_limits<int>::max();
const ll INF_LONG = numeric_limits<ll>::max();

int main() {
    //ifstream in("B-small-sample.in");
    //ofstream out("B-small-sample.out");

    ifstream in("B-small-attempt0.in");
    ofstream out("B-small-attempt0.out");

    int T;
    in >> T;

    for (int t = 1; t <= T; t++) {
        int A, B, K;
        in >> A >> B >> K;

        int ans = 0;

        for (int a = 0; a < A; a++) {
            for (int b = 0; b < B; b++) {
                int x = a & b;
                if (x >= 0 && x < K)
                    ans++;
            }
        }

        out << "Case #" << t << ": " << ans << endl;
    }

    in.close();
    out.close();
}
