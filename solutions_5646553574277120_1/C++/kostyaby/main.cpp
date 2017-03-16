#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXD = 111;

int c, d, v;
int a[MAXD];

int solve() {
    cin >> c >> d >> v;
    for (int i = 0; i < d; i++) {
        cin >> a[i];
    }

    long long bound = 0;
    
    long long answer = 0;
    for (int i = 0; i < d; i++) {
        int value = a[i];
        while (bound + 1 < value) {
            answer += 1;
            bound += c * 1ll * (bound + 1);
            if (bound >= v) {
                return answer;
            }
        }
        bound += c * 1ll * value;
        if (bound >= v) {
             return answer;
        }
    }
    while (bound < v) {
        answer += 1;
        bound += c * 1ll * (bound + 1);
        if (bound >= v) {
            return answer;
        }
    }
}

int main() {
	int cases; cin >> cases;
	for (int i = 0; i < cases; i++) {
        cout << "Case #" << i + 1 << ": " << solve() << "\n";
    }
    return 0;
}