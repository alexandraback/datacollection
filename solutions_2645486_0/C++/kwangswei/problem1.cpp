#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <stack>
#include <cstdlib>

using namespace std;

#define MAX_E 6
#define MAX_R 6
#define MAX_N 11

int e;
int r;
int n;
vector<int> v;

int gain(int in_energy, int job) {
    return in_energy * v[job];
}

int recover ( int cur_e) {
    if ( cur_e + r > e )
        return e;
    return cur_e + r;
}

int solve(int cur_e, int job) {
    if (job == n - 1 )
        return  cur_e * v[job];

    int gain_max = 0;
    for (int i = 0; i <= cur_e; i++) {
        int remain_energy = recover( cur_e-i);
        gain_max = max(gain_max, gain(i, job) + solve(remain_energy, job+1));
    }
    return gain_max;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> e >> r >> n;
        v = vector<int>(n);
        for (int j = 0; j < n; j++)
           cin >> v[j];

        cout << "Case #" << i << ": " << solve(e, 0) << endl;
    }

    return 0;
}
