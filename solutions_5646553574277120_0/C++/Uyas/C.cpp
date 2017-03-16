#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

long long C, D, V, a[111], answer, now, b[112345];

void readin() {
    cin >> C >> D >> V;
    for (int i = 1; i <= D; ++i) 
        cin >> a[i]; 
}

void work() {
    sort(a + 1, a + 1 + D);
    answer = 0;
    now = 0;
    for (int i = 1; i <= D; ++i) {
        if (now >= V) return;
        if (now + 1 < a[i]) {
            int add = now + 1;
            now = now + add * C;
            answer += 1;
            i -= 1;
        } else {
            now += a[i] * C;
        }
    }
    while (now < V) {
        int add = now + 1;
        now += add * C;
        answer += 1;
    }
}

int main() {
    int tasks; cin >> tasks;
    for (int cas = 1; cas <= tasks; ++cas) {
        readin();
        work();
        cout << "Case #" << cas << ": " << answer << endl;
    }
    return 0;
}
