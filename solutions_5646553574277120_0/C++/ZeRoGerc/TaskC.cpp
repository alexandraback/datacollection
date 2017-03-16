#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

int T;
int c, d, v, x;
int ans;
bool used[31], avail[31];

void recalc(int added) {
    for (int i = v - added; i >= 0; i--) {
        avail[i + added] = ((avail[i]) ? true : avail[i + added]);
    }
}

void recur(int current_ans) {
    bool p = true;
    
    for (int i = 0; i <= v; i++) {
        if (!avail[i]) {
            p = false;
            break;
        }
    }
    
    if (p) {
        ans = min(ans, current_ans);
        return;
    }
    
    bool old_used[31], old_avail[31];
    for (int i = 0; i <= v; i++) {
        old_used[i] = used[i];
        old_avail[i] = avail[i];
    }
    
    for (int i = 0; i <= v; i++) {
        if (!avail[i]) {
            for (int j = 0; j < i; j++) {
                if (avail[j] && !used[i - j]) {
                    used[i - j] = true;
                    recalc(i - j);
                    recur(current_ans + 1);
                    
                    for (int i = 0; i <= v; i++) {
                        used[i] = old_used[i];
                        avail[i] = old_avail[i];
                    }
                    break;
                }
            }
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> T;
    for (int I = 0; I < T; I++) {
        cin >> c >> d >> v;
        memset(used, false, sizeof(used));
        memset(avail, false, sizeof(avail));
        avail[0] = true;
        for (int i = 0; i < d; i++) {
            cin >> x;
            used[x] = true;
            for (int j = v - x; j >= 0; j--) {
                avail[j + x] = ((avail[j]) ? true : avail[j + x]);
            }
        }
        
        ans = v - d;
        
        recur(0);
        
        cout << "Case #" << I + 1 << ": " << ans << '\n';
    }
}