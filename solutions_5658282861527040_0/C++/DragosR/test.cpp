#include <cstdio>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <stack>
#define pb push_back

#define mp make_pair
#define f first
#define s second
#define ll long long

using namespace std;

int main() {
    ifstream cin("test.in");
    ofstream cout("test.out");

    int T; cin >> T;

    for (int tcase = 1; tcase <= T; ++tcase) {
        int A, B, K;
        cin >> A >> B >> K;

        long long answer = 0;
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                if ( (i & j) < K) {
                    answer += 1;
                }
            }
        }
        cout << "Case #" << tcase << ": ";
        cout << answer << "\n";
    }
    return 0;
}
