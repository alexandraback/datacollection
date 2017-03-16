#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
const int INF = 2000000000;

using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, A, N;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> A >> N;
        vector<int> b(N);
        int cnt = 0, ans = INF;
        for(int i = 0; i < N; i++)
            cin >> b[i];
        sort(b.begin(), b.end());
        int i = 0;
        while(i < N) {
            if(b[i] < A) {
                A += b[i];
                i++;
            } else {
                ans = min(ans, cnt + N - i);
                if(A == 1) {
                    cnt = INF;
                    break;
                }
                A += A - 1;
                cnt++;
            }
        }
        ans = min(ans, cnt);
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
    return 0;
}
