#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x) * (x))
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 500;
const string D[10] = {"ZERO", "SIX", "TWO", "EIGHT", "FOUR", "FIVE", "SEVEN", "THREE", "NINE", "ONE"};
const int p[10] = {0, 6, 2, 8, 4, 5, 7, 3, 9, 1};

int cnt[N], temp[N];

int main() {
    freopen("/Users/nurlan/Dropbox/Programming/contest/contest/input", "r", stdin);
    freopen("/Users/nurlan/Dropbox/Programming/contest/contest/output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        string s;
        cin >> s;
        memset(cnt, 0, sizeof(cnt));
        for (char ch : s) {
            cnt[ch]++;
        }
        string res = "";
        for (int i = 0; i <= 9; i++) {
            memset(temp, 0, sizeof(temp));
            for (char ch : D[i]) {
                temp[ch]++;
            }
            while (true) {
                bool check = false;
                for (char ch = 'A'; ch <= 'Z'; ch++) {
                    if (cnt[ch] < temp[ch]) {
                        check = true;
                        break;
                    }
                }
                if (check) {
                    break;
                }
                res += (char)('0' + p[i]);
                for (int j = 0; j < sz(D[i]); j++) {
                    cnt[D[i][j]]--;
                }
            }
        }
        sort(all(res));
        cout << res;
        cout << "\n";
    }
    return 0;
}