#include "std.h"
#define DBGLEVEL 1
#include "debug.h"

char buf[1024];
char ans[1024];
int N;

int main() {
    int T;
    cin >> T;
    FOR(tt, T)
    {
        int B;
        LL M;
        cin >> B >> M;
        cout << "Case #" << (tt + 1) << ": ";

        int n = B - 2;
        LL max = 1LL << n;
        if (max < M) cout << "IMPOSSIBLE";
        else
        {
            cout << "POSSIBLE" << endl;
            vector<LL> ways(B);
            vector<int> sel(B);
            ways[0] = ways[1] = 1;
            FOR2(i, 2, B) ways[i] = 2 * ways[i - 1];
            for (int i = B - 2; i >= 0; i--) if (ways[i] <= M) sel[i] = true, M -= ways[i];
            assert(M == 0);
            
            FOR(i, B - 1) {
                string s0(i+1, '0');
                string s1(B - 2 - i, '1');
                cout << s0 << s1 << (sel[i] ? '1' : '0') << endl;
            }
            cout << string(B, '0') << endl;
        }
        cout << endl;

        next:;       

    }
    return 0;
}
