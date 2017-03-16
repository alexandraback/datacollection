#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int kMaxPancakes = 1000;

int pancakes[kMaxPancakes + 10];
int dp[kMaxPancakes + 10][kMaxPancakes + 10];

void solve(int test_id) {
    int n;
    cin >> n;
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        cin >> pancakes[i];
        answer = max(answer, pancakes[i]);
    }
    int max_pankakes = answer;
    for (int threshold = 1; threshold <= max_pankakes; ++threshold) {
        int extra_steps = 0;
        for (int i = 0; i < n && extra_steps + threshold < answer; ++i) {
            extra_steps += dp[threshold][pancakes[i]];
        }
        answer = min(answer, extra_steps + threshold);
    }
    cout << "Case #" << test_id << ": " << answer << endl;
}

int main() {
    for (int threshold = 1; threshold <= kMaxPancakes; ++threshold) {
        for (int pancake = 1; pancake <= kMaxPancakes; ++pancake) {
            dp[threshold][pancake] = (pancake - 1) / threshold;
        }
    }
    int num_testcase;
    cin >> num_testcase;
    for (int test_id = 1; test_id <= num_testcase; ++test_id) {
        solve(test_id);
    }
    return 0;
}